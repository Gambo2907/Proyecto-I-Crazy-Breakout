#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <iostream>
#define PORT 7000
#define QUEUE 20

int main() {
    fd_set rfds;
    struct timeval tv;
    int retval, maxfd;
    int ss = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_sockaddr;
    server_sockaddr.sin_family = AF_INET;
    server_sockaddr.sin_port = htons(PORT);
    //printf("%d\n",INADDR_ANY);
    server_sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    if(bind(ss, (struct sockaddr* ) &server_sockaddr, sizeof(server_sockaddr))==-1) {
        perror("bind");
        exit(1);
    }
    if(listen(ss, QUEUE) == -1) {
        perror("listen");
        exit(1);
    }

    struct sockaddr_in client_addr;
    socklen_t length = sizeof(client_addr);
    /// Successful return of non-negative descriptor, error Return-1
    int conn = accept(ss, (struct sockaddr*)&client_addr, &length);
    if( conn < 0 ) {
        perror("connect");
        exit(1);
    }
    while(1) {
        /*Clear the collection of readable file descriptors*/
        FD_ZERO(&rfds);
        /*Add standard input file descriptors to the collection*/
        FD_SET(0, &rfds);
        maxfd = 0;
        /*Add the currently connected file descriptor to the collection*/
        FD_SET(conn, &rfds);
        /*Find the largest file descriptor in the file descriptor set*/    
        if(maxfd < conn)
            maxfd = conn;
        /*Setting timeout time*/
        tv.tv_sec = 5;
        tv.tv_usec = 0;
        /*Waiting for chat*/
        retval = select(maxfd+1, &rfds, NULL, NULL, &tv);
        if(retval == -1){
            printf("select Error, client program exit\n");
            break;
        }else if(retval == 0){
            printf("The server does not have any input information, and the client does not have any information coming. waiting...\n");
            continue;
        }else{
            /*The client sent a message.*/
            if(FD_ISSET(conn,&rfds)){
                char buffer[1024];    
                memset(buffer, 0 ,sizeof(buffer));
                int len = recv(conn, buffer, sizeof(buffer), 0);
                if(strcmp(buffer, "exit\n") == 0) break;
                printf("%s", buffer);
                //Send (conn, buffer, len, 0); send back the data to the client
            }
            /*When the user enters the information, he begins to process the information and send it.*/
            if(FD_ISSET(0, &rfds)){
                char buf[1024];
                fgets(buf, sizeof(buf), stdin);
                //printf("you are send %s", buf);
                send(conn, buf, sizeof(buf), 0);    
            }
        }
    }
    close(conn);
    close(ss);
    return 0;
}