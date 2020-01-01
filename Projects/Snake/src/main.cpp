#include <GL/glut.h>
#include <iostream>

using namespace std;

int main (int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	//Create the window
	glutCreateWindow("My new window");
	glutMainLoop();
    
    return 0;
}