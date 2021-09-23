

#include <iostream>
#include <assert.h>
#include "math.h"
#if defined(__APPLE__) || defined(MACOSX)
	#include <GLUT/glut.h>
#else
	#include "glut.h"
#endif
#include "cliente.h"
#include "Breakout.h"


Breakout game;



// Define the display function
void myDisplay()
{
	game.display();
}

// Define the reshape function
void myReshape(int width, int height)
{
	game.reshape(width, height);
}


// Define the mouse drag events
void myMouseMove(int x, int y)
{
	game.mouseMove(x, y);
}

// Define keystroke events
void myKeyStroke(unsigned char key, int x, int y)
{
	game.keyStroke(key, x, y);
}

void mySpecialKeyStroke(int key, int x, int y)
{
	game.specialKeyPos(key, x, y);
}

// The main function here
int main(int argc, char ** argv)
{
	// Init glut
	glutInit(&argc, argv);

	
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_MULTISAMPLE);
	// Init display mode

	// Init window size, position, title
	glutInitWindowSize(WINWIDTH, WINHEIGHT);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(WINTITLE2);
	
	

	
	// Init game
	game.WelcomeScreen();
	
	// Draw scene
	glutDisplayFunc(myDisplay);
	// Handle reshape
	glutReshapeFunc(myReshape);
	
	// Handle mouse motion
    glutPassiveMotionFunc(myMouseMove);
	// Handle keyboard strokes
	glutKeyboardFunc(myKeyStroke);
	// specify keyboard special key input events
	glutSpecialFunc(mySpecialKeyStroke);
	// Enter the opengl event processing loop
	glutMainLoop();

	return 0;
}
