#include <GL/glut.h>

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	gluOrtho2D(0.0,300.0,0.0,300.0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

void menu(int id)
{
	switch(id)
	{
		case 1:
			glClear(GL_COLOR_BUFFER_BIT);
			glBegin(GL_POINTS);
			glVertex2i(50,100);
			glVertex2i(100,150);
			glVertex2i(150,200);
			glEnd();
			glFlush();
		break;
		case 2:
			glClear(GL_COLOR_BUFFER_BIT);
			glBegin(GL_LINES);
			glVertex2i(50,100);
			glVertex2i(100,150);
			glVertex2i(152,200);
			glVertex2i(200,250);
			glEnd();
			glFlush();
		break;
		case 3:
			glClear(GL_COLOR_BUFFER_BIT);
			glBegin(GL_LINE_LOOP);
			glVertex2i(50,100);
			glVertex2i(100,150);
			glVertex2i(150,50);
			glEnd();
			glFlush();
		break;
		case 4: exit(0);
		break;
	}
}
void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(50, 100);
	glutCreateWindow("OpenGL Menu");
	init();
	glutDisplayFunc(display);
	glutCreateMenu(menu);
	glutAddMenuEntry("Points", 1);
	glutAddMenuEntry("Lines", 2);
	glutAddMenuEntry("LineLoop", 3);
	glutAddMenuEntry("Exit", 4);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
}
