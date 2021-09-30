

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
	
	int sock = 0, valread;
    	struct sockaddr_in serv_addr;
    	const char *hello = "Connection accepted";
    	char buffer[1024] = {0};
    	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    	{
        	printf("\n Socket creation error \n");
        	return -1;
    	}
   
    	serv_addr.sin_family = AF_INET;
    	serv_addr.sin_port = htons(PORT);
       
    	// Convert IPv4 and IPv6 addresses from text to binary form
    	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) 
    	{
 	    printf("\nInvalid address/ Address not supported \n");
    	    return -1;
   	 }
   
   	 if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
   	 {
    	    printf("\nConnection Failed \n");
    	    return -1;
   	 }
   	 send(sock , hello , strlen(hello) , 0 );
   	 printf("Connection Successful\n");
   	 valread = read( sock , buffer, 1024);
   	 printf("%s\n",buffer );
	
	
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
