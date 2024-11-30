#include <GL/glut.h>

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	gluOrtho2D(0.0,300.0,0.0,300.0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'A');
	glFlush();
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(50, 100);
	glutCreateWindow("OpenGL Character");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}
