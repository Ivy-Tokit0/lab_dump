// source: https://drive.google.com/file/d/1dnrdDjhX0R3dCFV9ImIBAyF1HAQNuh5K // VTU-Code**
#include <GL/glut.h>

GLsizei wh = 500, ww = 500; /* initial window width and height */
GLfloat size = 3.0; /*one half of side length */

void init()
{
	glViewport(0,0,ww,wh);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble) ww , 0.0, (GLdouble) wh);
	glMatrixMode(GL_MODELVIEW);
	glClearColor (0.0, 0.0, 0.0, 1.0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glRasterPos2i(250, 250);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'A');
	glFlush();
}

void reshape(GLsizei w, GLsizei h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glViewport(0,0,w,h); // Adjust viewport and clear
	// Update Global Vars
	ww=w;
	wh=h;
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(50, 100);
	glutCreateWindow("OpenGL Reshape");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
}
