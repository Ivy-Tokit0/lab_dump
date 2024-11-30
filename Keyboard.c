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
void key(unsigned char key,int x,int y)
{
	if(key=='C') // Exit on Capital C
		exit(0);
	else if(key=='c') // Write 'c' To Display on Small 'c'
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,'c');
	glFlush();
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(50, 100);
	glutCreateWindow("OpenGL Keyboard | Key=C/c");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(key);
	glutMainLoop();
}
