#include <GL/glut.h>

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glOrtho(-2.0,2.0,-2.0,2.0,-2.0,2.0);
}

// Cube Co-ordinates Array
GLfloat vertices[8][3] = {
	{-1.0,-1.0,1.0},{-1.0,1.0,1.0},{1.0,1.0,1.0}, {1.0,-1.0,1.0}, {-1.0,-1.0,-1.0},{-1.0,1.0,-1.0}, {1.0,1.0,-1.0}, {1.0,-1.0,-1.0}
};

GLfloat colors[8][3] = {
	{0.0,0.0,0.0},{1.0,0.0,0.0},{1.0,1.0,0.0}, {0.0,1.0,0.0}, {0.0,0.0,1.0},{1.0,0.0,1.0}, {1.0,1.0,1.0}, {0.0,1.0,1.0}
};

void quad(int a, int b, int c, int d)
{
	glBegin(GL_QUADS);
	glColor3fv(colors[a]);
	glVertex3fv(vertices[a]);
	glColor3fv(colors[b]);
	glVertex3fv(vertices[b]);
	glColor3fv(colors[c]);
	glVertex3fv(vertices[c]);
	glColor3fv(colors[d]);
	glVertex3fv(vertices[d]);
	glEnd();
}

void colorcube()
{
	quad(0,3,2,1);
	quad(2,3,7,6);
	quad(0,4,7,3);
	quad(1,2,6,5);
	quad(4,5,6,7);
	quad(0,1,5,4);
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	colorcube();
	glFlush();
}

void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(50, 100);
	glutCreateWindow("OpenGL Cube");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}
