#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
int flag = 0;
void build();
void car(int, int);
float xv = 0, yv = 0;
float r = 0, g = 0, b = 1;
void d1();
int rev = 0;
void moverev();
void idlefunc(int value);
void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 500);
	glMatrixMode(GL_MODELVIEW);
}
void print(const char *a, float x, float y)//For displaying text on the screen at required position.
{
	glRasterPos2f(x, y);
	for (int i = 0; a[i] != '\0'; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, a[i]);
	}

}
void mouse(int button, int status, int x, int y)
{
	printf("gqwh");
	if (button == GLUT_LEFT_BUTTON && status == GLUT_DOWN)
	{
		printf("inside mouse");
		flag = 1;
		d1();
	}

}
void firstdisp()//Welcome text
{
	glBegin(GL_POLYGON);
	glColor3f(0, 0.5, 0);
	glVertex2f(0, 0);
	glColor3f(0, 0.5, 0);
	glVertex2f(0, 500);
	glColor3f(0, 0.5, 0.5);
	glVertex2f(500, 0);
	glColor3f(0, 0.5, 0.5);
	glVertex2f(500, 500);
	glColor3f(0, 0.5, 0.5);
	glVertex2f(0, 501);
	glColor3f(0, 0.5, 0.5);
	glVertex2f(501, 0);
	glEnd();

	glColor3f(1, 1, 1);
	print("Welcome to Car Simulation.", 205, 330);
	glBegin(GL_LINES);
	{
		glVertex2f(200, 327);
		glVertex2f(305, 327);
	}
	glEnd();
	print("The car changes its position and starts moving in user's direction.", 80, 300);
	print("The user can move the car using the arrow keys.", 80, 280);
	print("User can even specify the direction using mouse also.", 80, 260);
	print("User even can change the color of the car.", 80, 240);
	print("User can stop the car when ever he requires using mouse and even he can make the car move from initial position.", 80, 220);
	//print(".", 80, 240);
	print("User can press the key to make the car to move in his direction.", 180, 190);
	print("Project by", 300, 90);
	print("NAGAMANI (1RN15CS063)", 280, 70);
	print("RAKSHITHA B R (1RN15CS130)", 280, 50);

}

void road()
{
	int x = 0, y = 0;
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);
	glVertex2f(x + 0, y + 200);				//vertices for road
	glVertex2f(x + 500, y + 200);
	glVertex2f(x + 500, y + 300);
	glVertex2f(x + 0, y + 300);
	glEnd();

	glBegin(GL_LINES);				//white lines on road
	glLineWidth(15.0);				//to increase the width of the line
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(x + 0, y + 250);
	glVertex2f(x + 100, y + 250);
	glVertex2f(x + 200, y + 250);
	glVertex2f(x + 300, y + 250);
	glVertex2f(x + 400, y + 250);
	glVertex2f(x + 500, y + 250);
	glEnd();
	//xr = 0, yr 

	build();

	glutSwapBuffers();
	glFlush();
	//mountain();= 0;
	//car(xr,yr);

	//move();

	//glutPostRedisplay();



}
void sqr(int x, int y)
{
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(x + 100, y + 210);
	glVertex2f(x + 300, y + 210);
	glVertex2f(x + 300, y + 240);
	glVertex2f(x + 100, y + 240);
	glEnd();
	glFlush();

}
void move()
{
	int i;
	//int xx = 0;
	//overpos();
	//otherveh(xv, yv);
	road();

	//glLoadIdentity();
	for (i = 0; i < 1; i++)
	{
		glClearColor(0.6, 0.6, 0.6, 0.5);
		glClear(GL_COLOR_BUFFER_BIT);
		//overpos();
		//otherveh(xv, yv);
		road();
		xv = xv + 2;

		if (xv >= 400)
		{
			xv = -100;
			car(xv, yv);

		}

		printf("%d", yv);

		car(xv, yv);

		glutSwapBuffers();
		glFlush();

	}



}


int x = 0, y = 0;
void d1()
{

	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);
	glVertex2f(x + 0, y + 200);				//vertices for road
	glVertex2f(x + 500, y + 200);
	glVertex2f(x + 500, y + 300);
	glVertex2f(x + 0, y + 300);
	glEnd();

	glBegin(GL_LINES);				//white lines on road
	glLineWidth(15.0);				//to increase the width of the line
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(x + 0, y + 250);
	glVertex2f(x + 100, y + 250);
	glVertex2f(x + 200, y + 250);
	glVertex2f(x + 300, y + 250);
	glVertex2f(x + 400, y + 250);
	glVertex2f(x + 500, y + 250);
	glEnd();
	//xr = 0, yr 

	build();
	xv = -100;
	glColor3f(0.6, 0.3, 0.5);
	car(xv, yv);
	if (rev == 0)
		move();

	if (rev == 1)
		moverev();

	glutSwapBuffers();
	glFlush();
	//mountain();= 0;
	//car(xr,yr);

	//move();

	//glutPostRedisplay();


}
void build()
{

	glColor3f(0.1, 0.6, 0.8);
	glBegin(GL_POLYGON);//sky
	glVertex2f(0, 400);
	glVertex2f(500, 400);
	glVertex2f(500, 500);
	glVertex2f(0, 500);
	glEnd();


	glBegin(GL_QUADS);				//grass
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(500, 300);
	glVertex2f(500, 400);
	glVertex2f(0, 400);
	glVertex2f(0, 300);
	glVertex2f(500, 0);
	glVertex2f(500, 200);
	glVertex2f(0, 200);
	glVertex2f(0, 0);
	glEnd();

	glBegin(GL_POLYGON);			//first tree trunk
	glColor3f(0.5, 0.35, 0.05);
	glVertex2f(305, 380);
	glVertex2f(305, 420);
	glVertex2f(295, 420);
	glVertex2f(295, 380);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.4, 0.2);				//first tree greenary part
	glVertex2f(310, 420);
	glVertex2f(320, 420);
	glVertex2f(310, 430);
	glVertex2f(320, 430);
	glVertex2f(310, 440);
	glVertex2f(320, 440);
	glVertex2f(300, 450);
	glVertex2f(280, 440);
	glVertex2f(290, 440);
	glVertex2f(280, 430);
	glVertex2f(290, 430);
	glVertex2f(280, 420);
	glVertex2f(290, 420);
	glEnd();


	glBegin(GL_POLYGON);			//second tree trunk
	glColor3f(0.5, 0.35, 0.05);
	glVertex2f(205, 380);
	glVertex2f(205, 420);
	glVertex2f(195, 420);
	glVertex2f(195, 380);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.4, 0.2);				// second tree greenary part
	glVertex2f(210, 420);
	glVertex2f(220, 420);
	glVertex2f(210, 430);
	glVertex2f(220, 430);
	glVertex2f(210, 440);
	glVertex2f(220, 440);
	glVertex2f(200, 450);
	glVertex2f(180, 440);
	glVertex2f(190, 440);
	glVertex2f(180, 430);
	glVertex2f(190, 430);
	glVertex2f(180, 420);
	glVertex2f(190, 420);
	glEnd();


	glLineWidth(100);
	glBegin(GL_POLYGON);//1st part of the building
	glColor3f(1, 0.4, 0.6);
	glVertex2f(296, 385);
	glVertex2f(295, 320);
	glVertex2f(280, 320);
	glVertex2f(280, 387);
	glEnd();
	glLineWidth(20);
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);		//outer window part of the first house
	glVertex2f(285, 340);
	glVertex2f(290, 340);
	glVertex2f(290, 330);
	glVertex2f(285, 330);
	glEnd();
	glBegin(GL_LINES);			//inner window line of the first house
	glColor3f(0, 0, 0);
	glVertex2f(287, 340);
	glVertex2f(287, 330);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2f(278, 385);//upper part of the first house
	glVertex2f(277, 387);
	glVertex2f(287, 394);
	glVertex2f(297, 387);
	glVertex2f(296, 385);
	glVertex2f(287, 392);
	glEnd();

	glBegin(GL_POLYGON);//upper part of the second portion
	glColor3f(0, 0, 0);
	glVertex2f(297, 387);
	glVertex2f(298, 387);
	glVertex2f(298, 385);
	glVertex2f(296, 385);
	glEnd();
	glLineWidth(20);
	glColor3f(0.8, 0.7, 0.7);
	glBegin(GL_POLYGON);//doown part of the second portion
	glVertex2f(296, 385);
	glVertex2f(295, 320);
	glVertex2f(300, 320);
	glVertex2f(300, 385);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.6, 0.5);//middle part of the house
	glVertex2f(300, 385);
	glVertex2f(300, 320);
	glVertex2f(360, 320);
	glVertex2f(360, 385);
	glEnd();
	glBegin(GL_POLYGON);//door part of the middle house
	glColor3f(0, 0, 0);
	glVertex2f(320, 320);
	glVertex2f(320, 335);
	glVertex2f(340, 335);
	glVertex2f(340, 320);
	glEnd();
	glBegin(GL_POLYGON);//upper part of the middle  house
	glVertex2f(298, 385);
	glVertex2f(298, 387);
	glVertex2f(330, 420);
	glVertex2f(362, 387);
	glVertex2f(362, 385);
	glVertex2f(330, 418);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.8, 0.3, 0.2);//next part of the middle house
	glVertex2f(360, 385);
	glVertex2f(360, 332);
	glVertex2f(378, 332);
	glVertex2f(378, 385);
	glEnd();
	glBegin(GL_POLYGON);// down part of next part of the middle house
	glColor3f(0.9, 0.2, 0.3);
	glVertex2f(360, 332);
	glVertex2f(380, 332);
	glVertex2f(380, 320);
	glVertex2f(360, 320);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.8, 0.6);//next section of next part of the middle house 
	glVertex2f(380, 326);
	glVertex2f(400, 326);
	glVertex2f(400, 320);
	glVertex2f(380, 320);
	glEnd();
	glBegin(GL_LINES);//vertical line of the last section
	glColor3f(0, 0, 0);
	glVertex2f(388, 326);
	glVertex2f(388, 385);
	glEnd();
	glBegin(GL_LINES);//top part of the last section
	glColor3f(0, 0, 0);
	glVertex2f(362, 387);
	glVertex2f(398, 387);
	glVertex2f(398, 385);
	glVertex2f(362, 385);
	glEnd();
	glBegin(GL_POLYGON);//centre part of the last section
	glColor3f(0.6, 0.5, 0.3);
	glVertex2f(378, 385);
	glVertex2f(398, 385);
	glVertex2f(398, 326);
	glVertex2f(380, 326);
	glVertex2f(378, 332);
	glEnd();

	//building 1
	glBegin(GL_POLYGON);
	glColor3f(0.8, 0.4, 0.2);//first section
	glVertex2f(60, 338);
	glVertex2f(60, 370);
	glVertex2f(50, 380);
	glVertex2f(50, 340);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.5, 0.2);//second section section
	glVertex2f(60, 370);
	glVertex2f(63, 373);
	glVertex2f(80, 360);
	glVertex2f(80, 334);
	glVertex2f(60, 338);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.5, 0.8);//third section section
	glVertex2f(110, 340);
	glVertex2f(110, 362);
	glVertex2f(80, 360);
	glVertex2f(80, 334);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);//window of third section section
	glVertex2f(90, 342);
	glVertex2f(90, 348);
	glVertex2f(100, 348);
	glVertex2f(100, 342);
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(0.8, 0.7, 0.8);//fourth section section
	glVertex2f(110, 340);
	glVertex2f(110, 362);
	glVertex2f(100, 368);
	glVertex2f(160, 373);
	glVertex2f(160, 344);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);//door for fourth section section
	glVertex2f(120, 342);
	glVertex2f(120, 360);
	glVertex2f(140, 360);
	glVertex2f(140, 342);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.6, 0.5);//top part of first section section
	glVertex2f(50, 380);
	glVertex2f(60, 370);
	glVertex2f(80, 360);
	glVertex2f(110, 362);
	glVertex2f(110, 368);
	glVertex2f(100, 368);
	glVertex2f(95, 368);
	glVertex2f(50, 380);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.6, 0.5);//first top part
	glVertex2f(70, 376);
	glVertex2f(70, 388);
	glVertex2f(95, 400);
	glVertex2f(95, 370);
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.6, 0.5);//first top part
	glVertex2f(95, 368);
	glVertex2f(180, 373);
	glVertex2f(140, 420);
	glVertex2f(95, 400);
	glEnd();

	//drawing grass
	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.4, 0.2);//first top part
	glVertex2f(0, 0);
	glVertex2f(0, 40);
	glVertex2f(40, 20);
	glVertex2f(45, 80);
	glVertex2f(55, 40);
	glVertex2f(65, 60);
	glVertex2f(75, 40);
	glVertex2f(85, 80);
	glVertex2f(100, 50);
	glVertex2f(105, 90);
	glVertex2f(120, 60);
	glVertex2f(125, 30);
	glVertex2f(140, 70);
	glVertex2f(155, 50);
	glVertex2f(180, 90);
	glVertex2f(200, 70);
	glVertex2f(250, 120);
	glVertex2f(255, 80);
	glVertex2f(300, 100);
	glVertex2f(320, 60);
	glVertex2f(355, 70);
	glVertex2f(355, 40);
	glVertex2f(360, 60);
	glVertex2f(365, 40);
	glVertex2f(415, 70);
	glVertex2f(430, 30);
	glVertex2f(450, 65);
	glVertex2f(455, 45);
	glVertex2f(460, 80);
	glVertex2f(458, 40);
	glVertex2f(460, 60);
	glVertex2f(500, 50);
	glVertex2f(500, 0);
	glEnd();


	//glutPostRedisplay();


}
void car(int x, int y)
{

	glBegin(GL_POLYGON);
	glColor3f(r, g, b);
	glVertex2f(x + 150, y + 210);		//upper part of the car
	glVertex2f(x + 150, y + 220);
	glVertex2f(x + 140, y + 240);
	glVertex2f(x + 100, y + 240);
	glVertex2f(x + 100, y + 210);
	glEnd();
	//drawBall();
	glColor3f(0, 0, 0);					//to draw afirst  wheel
	glPushMatrix();
	glTranslatef(x + 110, y + 210, 0);
	glRotatef(180, x + 110, y + 210, 0);
	glutSolidSphere(3, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(x + 110, y + 210, 0);
	glutWireSphere(3, 50, 50);
	//glutSolidSphere(3, 50, 50);
	glPopMatrix();

	glColor3f(0, 0, 0);						//to draw second wheel
	glPushMatrix();
	glTranslatef(x + 135, y + 210, 0);
	glRotatef(180, x + 135, y + 210, 0);
	glutSolidSphere(3, x + 50, y + 50);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(x + 135, y + 210, 0);

	glutWireSphere(3, 50, 50);
	//glutSolidSphere(3, 50, 50);
	glPopMatrix();
	//	glPointSize(8);
	//	glColor3f(0, 0, 0);
	//	glBegin(GL_POLYGON);
	//	glVertex2f(150, 210);
	//glVertex2f(150, 215);
	//glVertex2f(155, 215);
	//	glVertex2f(155, 210);
	//glEnd();
	glBegin(GL_LINES);
	glVertex2f(x + 107, y + 210);				//to draw lines inside the first wheel
	glVertex2f(x + 113, y + 210);
	glVertex2f(x + 110, y + 207);
	glVertex2f(x + 110, y + 213);
	glVertex2f(x + 108.5, y + 211.5);
	glVertex2f(x + 111.5, y + 208.5);
	glVertex2f(x + 108.5, y + 208.5);
	glVertex2f(x + 111.5, y + 211.5);

	//for second wheel

	glVertex2f(x + 132, y + 210);
	glVertex2f(x + 138, y + 210);
	glVertex2f(x + 135, y + 213);
	glVertex2f(x + 135, y + 207);

	glVertex2f(x + 133.5, y + 211.5);
	glVertex2f(x + 136.5, y + 208.5);

	glVertex2f(x + 136.5, y + 211.5);
	glVertex2f(x + 133.5, y + 208.5);

	glEnd();
	//car_animation();

	//glutSwapBuffers();

	//glFlush();

}

void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	if (flag == 0)
	{

		firstdisp();
		glutSwapBuffers();
		glFlush();
	}
	if (flag == 1)
	{
		d1();
	}

	//glutPostRedisplay();


}
void moverev();
void idlefunc(int value)
{

	xv += 2;

	if (xv >= 400)
		xv = -100;

	glutTimerFunc(60, idlefunc, 0);
	//overpos();
	if (flag == 0)
	{
		firstdisp();
	}
	if (flag == 1)
	{
		if (rev == 0)
			move();
		if (rev == 1)
			moverev();
	}

	//glutSwapBuffers();

	//();
}
void moverev()
{

	int i;
	//int xx = 0;
	//overpos();
	//otherveh(xv, yv);
	road();



	//glLoadIdentity();
	for (i = 0; i < 1; i++)
	{
		glClearColor(0.6, 0.6, 0.6, 0.5);
		glClear(GL_COLOR_BUFFER_BIT);
		//overpos();
		//otherveh(xv, yv);
		road();
		xv = xv - 2;

		if (xv >= 400)
		{
			xv = -100;
			car(xv, yv);

		}
		if (xv <= -100)
		{
			xv = 400;
			car(xv, yv);

		}

		car(xv, yv);


		glutSwapBuffers();
		glFlush();

	}

}
void movement(int id)
{
	switch (id)
	{
	case 1:yv = yv + 50;

		if (yv >= 100)
			yv = yv - 50;

		car(xv, yv); move();
		break;
	case 2:yv = yv - 50;
		if (yv < 0)

			yv = yv + 50;

		car(xv, yv); move();
		break;
	case 3:rev = 0; car(xv, yv); move();
		break;
	case 4:rev = 1; car(xv, yv); move();
		break;


	}
}
void Specialkey(int key, int x, int y)//allow to use navigation key for movement of car
{
	int i = 0;
	switch (key)
	{
	case GLUT_KEY_LEFT:

		move();

		break;
	case GLUT_KEY_RIGHT:

		move();

		break;
	case GLUT_KEY_UP:yv = yv + 50;
		if (yv >= 100)
			yv = yv - 50;
		printf("upp %f ", yv); car(xv, yv);
		move();


		break;
	case GLUT_KEY_DOWN:yv = yv - 50; printf("down%f ", yv);
		if (yv < 0)
			yv = yv + 50;
		car(xv, yv); move();

		break;
	}
}

void submenu(int id)
{
	switch (id)
	{
	case 3://glClear(GL_COLOR_BUFFER_BIT);
		r = 1; g = 0; b = 0;
		car(xv, yv);
		break;
	case 4:r = 0; g = 0; b = 1;
		car(xv, yv);
		break;
	case 5:r = 1; g = 0.75; b = 0.2;
		car(xv, yv);
		break;
	}
}

int main(int argc, char**argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(1500, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("CAR");
	myinit();
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutSpecialFunc(Specialkey);
	int m1 = glutCreateMenu(submenu);
	glutAddMenuEntry("red", 3);
	glutAddMenuEntry("blue", 4);
	glutAddMenuEntry("yellow", 5);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutCreateMenu(movement);
	glutAddMenuEntry("up", 1);
	glutAddMenuEntry("down", 2);
	glutAddMenuEntry("front", 3);
	glutAddMenuEntry("stop", 4);
	glutAddSubMenu("color", m1);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutTimerFunc(60, idlefunc, 0);
	glutMainLoop();
}