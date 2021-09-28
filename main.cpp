

#include <iostream>
#include <assert.h>
#include "math.h"
#if defined(__APPLE__) || defined(MACOSX)
	#include <GLUT/glut.h>
#else
	#include "glut.h"
#endif
#include "Breakout.h"


Breakout game;




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
