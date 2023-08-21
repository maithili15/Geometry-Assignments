// Drawing Object.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/GLU.h>
#include<gl/GL.h>
#define PI 3.14159265358979323846
using namespace std;

void MyInit() {//func initialize drawing environment
	glClearColor(0, 0, 0, 1);//bg color -->black
	glColor3f(1, 0, 0);//rgb
}
void Draw() {//fun draw circle and 3 btn
	glClear(GL_COLOR_BUFFER_BIT);//clearing color buffer to current background color

	//square
	glBegin(GL_POLYGON);//POLYGON
	glColor3f(0, 0, 1);//blue
	glVertex2f(-0.5, 0.5);//vertex---top left
	glVertex2f(0.5, 0.5);//top right
	glVertex2f(0.5, -0.5);//bottom right
	glVertex2f(-0.5, -0.5);//bottom left
	glEnd();

	//circle
	GLfloat x = 0.0f;//center co-ordinate of circle
	GLfloat y = 0.0f;//center co-ordinate of circle
	GLfloat radius = 0.5f;
	int trinagleAmount = 40;//no. of triangle approx.
	GLfloat twicePi = 2.0f*PI;
	glColor3f(0, 1, 0);//rgb--->green
	glBegin(GL_TRIANGLE_FAN);//A triangle fan is a primitive in 3D computer graphics that saves on storage and processing time. 
							//It describes a set of connected triangles that share one central vertex 
	glColor3f(1, 0, 0);
	glColor3ub(43, 78, 102);//rgb---->custom
	glVertex2f(x, y);
	for (int i = 0; i <= trinagleAmount; i++) {//calculate vertex pos. for each triangle 
		glVertex2f(
			x + (radius*cos(i*twicePi / trinagleAmount)),
			y + (radius*sin(i*twicePi / trinagleAmount))
		);
	}
	glEnd();

	//1st btn
	glColor3f(0, 1, 0);  //btn color
	glBegin(GL_POLYGON);
	glVertex2d(-0.5, -0.7);
	glVertex2d(-0.2, -0.7);
	glVertex2d(-0.2, -0.9);
	glVertex2d(-0.5, -0.9);
	glEnd();
	glColor3f(0, 0, 0);
	glRasterPos2f(-0.38, -0.8);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'S');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'T');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'A');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'R');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'T');
	//2nd btn
	glColor3f(0, 1, 0);  //btn color
	glBegin(GL_POLYGON);
	glVertex2d(-0.134, -0.7);
	glVertex2d(0.136, -0.7);
	glVertex2d(0.136, -0.9);
	glVertex2d(-0.134, -0.9);
	glEnd();
	glColor3f(0, 0, 0);
	glRasterPos2f(-0.045, -0.8);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'S');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'T');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'O');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'P');
	//3rd btn
	glColor3f(0, 1, 0);  //btn color
	glBegin(GL_POLYGON);
	glVertex2d(0.2, -0.7);
	glVertex2d(0.5, -0.7);
	glVertex2d(0.5, -0.9);
	glVertex2d(0.2, -0.9);
	glEnd();
	glColor3f(0, 0, 0);
	glRasterPos2f(0.307, -0.8);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'P');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'A');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'U');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'S');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'E');
	






	glFlush();//it is used when the problem of submitting more operations to OpenGL than it could execute.
}

int main(int c,char* v[])
{
	glutInit(&c, v);//initialize glut lib
	glutInitWindowPosition(250, 50);//set window pos.
	glutInitWindowSize(700, 700);//size of window
	glutCreateWindow("object");//title
	MyInit();//initialize drawing environment
	glutDisplayFunc(Draw);//func. called
	glutMainLoop();//event handle
	return 0;
}




/*

	// 1st button name (Start)
	glRasterPos2f(-0.38, -0.8);
	const char *startLabel = "Start";
	int startLabelLen = strlen(startLabel);
	for (int i = 0; i < startLabelLen; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, startLabel[i]);
	}
	// 2nd button name (Stop)
	glRasterPos2f(-0.045, -0.8);//used to rendering 2d n 3d img. x and y are coordinates.
	const char *stopLabel = "Stop";
	int stopLabelLen = strlen(stopLabel);
	for (int i = 0; i < stopLabelLen; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, stopLabel[i]);//represent character directly on screen
	}
	// 3rd button name (Pause)
	glRasterPos2f(0.307, -0.8);
	const char *pauseLabel = "Pause";
	int pauseLabelLen = strlen(pauseLabel);
	for (int i = 0; i < pauseLabelLen; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, pauseLabel[i]);
	}
*/