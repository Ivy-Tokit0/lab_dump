#include <GL/glut.h>

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	gluOrtho2D(0.0,300.0,0.0,300.0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_LOOP);
	glVertex2i(50,100);
	glVertex2i(100,150);
	glVertex2i(150,50);
	glEnd();
	glFlush();
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(50, 100);
	glutCreateWindow("OpenGL LineLoop");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}
