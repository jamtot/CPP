#include <GL/glut.h>
#include <iostream>
#include "Grid.hpp"

using namespace std;

//create global grid pointer
Grid *g;

//Called when a key is pressed
void processNormalKeys(unsigned char key, int x, int y) {
	switch (key) {
		case 27: //Escape key
			exit(0);
	}
}

void renderScene() {
   	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective

	glPushMatrix(); //Save the transformations performed thus far


	g->draw();

	
	glPopMatrix(); //Undo the move to the center of the trapezoid
	
	glutSwapBuffers();
}

int main (int argc, char **argv)
{
	float width = 800.f;
	float height = 600.f;
	g = new Grid(width, height);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition ( 0, 0 );
    glutInitWindowSize(width, height);
	glutCreateWindow("Snake!");

	// register callbacks
	glutDisplayFunc(renderScene);
	glutIdleFunc(renderScene);	

	// here are the new entries
	glutKeyboardFunc(processNormalKeys);

	// enter GLUT event processing cycle
	glutMainLoop();

    return 1;
}