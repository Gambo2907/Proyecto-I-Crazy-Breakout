

#include <iostream>
#include <assert.h>
#include "math.h"
#if defined(__APPLE__) || defined(MACOSX)
	#include <GLUT/glut.h>
#else
	#include "glut.h"
#endif
#include "Breakout.h"
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#define PORT 8080


Breakout game;

/*

cd <breakout project path>
mkdir build
cd build
cmake -G Unix\ Makefiles ..
make
./crazyBreakout

*/




void myDisplay()
{
	game.display();
}


void myReshape(int width, int height)
{
	game.reshape(width, height);
}



void myMouseMove(int x, int y)
{
	game.mouseMove(x, y);
}


void myKeyStroke(unsigned char key, int x, int y)
{
	game.keyStroke(key, x, y);
}

void mySpecialKeyStroke(int key, int x, int y)
{
	game.specialKeyPos(key, x, y);
}


int main(int argc, char ** argv)
{
	
	int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = "Processing your connection...";
       
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
       
    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                  &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
       
    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address, 
                                 sizeof(address))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, 
                       (socklen_t*)&addrlen))<0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    valread = read( new_socket , buffer, 1024);
    printf("%s\n",buffer );
    send(new_socket , hello , strlen(hello) , 0 );
    printf("Hello message sent\n");
	
	glutInit(&argc, argv);

	
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_MULTISAMPLE);
	

	
	glutInitWindowSize(WINWIDTH, WINHEIGHT);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(WINTITLE);
	
	
	
	game.WelcomeScreen();
	
	
	glutDisplayFunc(myDisplay);
	
	glutReshapeFunc(myReshape);
	
	
    glutPassiveMotionFunc(myMouseMove);
	
	glutKeyboardFunc(myKeyStroke);
	
	glutSpecialFunc(mySpecialKeyStroke);
	
	glutMainLoop();

	return 0;
}
