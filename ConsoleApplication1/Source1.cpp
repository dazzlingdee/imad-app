#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>
static int z = 0;
void myinit(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
}
void display(void)
{
	GLfloat position[] = { 0.0, 0.0, 1.5, 1.0 };
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0, 0.5, 0.0);
	glPushMatrix();
	glRotatef((GLfloat)z, 1.0, 1.0, 1.0);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glDisable(GL_LIGHTING);
	glBegin(GL_QUAD_STRIP);
	for (i = 0; i <= 360; i++)
	{
		glVertex3f(sin(i*3.1416 / 180)*0.5, cos(i*3.1416 / 180)*0.5, 0);
		glVertex3f(sin(i*3.1416 / 180)*0.7, cos(i*3.1416 / 180)*0.7, 0);
	}
	glEnd();
	glutSwapBuffers();
}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("planets amidst stars");
	myinit();
	glutDisplayFunc(display);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 0;
}