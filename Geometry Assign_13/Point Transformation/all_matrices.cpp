#include <iostream>
#include <cmath>
#include <vector>
#include <GL/glut.h>


struct Vector {
	Vector() {}
	double x, y, z;
	Vector(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}
};

// 1)matrix 1
Vector p2(10, 0, 0);
Vector transformVector1(const Vector& v, const double matrix1[3][3]) {
	double newX1 = matrix1[0][0] * v.x + matrix1[0][1] * v.y + matrix1[0][2] * v.z;
	double newY1 = matrix1[1][0] * v.x + matrix1[1][1] * v.y + matrix1[1][2] * v.z;
	double newZ1 = matrix1[2][0] * v.x + matrix1[2][1] * v.y + matrix1[2][2] * v.z;
	return Vector(newX1, newY1, newZ1);
}
double transformationMatrix1[3][3] = {
	{0.707388 ,-0.706825,0},
	{0.706825 ,0.707388,0},
	{0,0,1}
};


// 2)matrix 2
//Vector p2(10, 0, 0);
Vector transformVector2(const Vector& v, const double matrix2[3][3]) {
	double newX2 = matrix2[0][0] * v.x + matrix2[0][1] * v.y + matrix2[0][2] * v.z;
	double newY2 = matrix2[1][0] * v.x + matrix2[1][1] * v.y + matrix2[1][2] * v.z;
	double newZ2 = matrix2[2][0] * v.x + matrix2[2][1] * v.y + matrix2[2][2] * v.z;
	return Vector(newX2, newY2, newZ2);
}
double transformationMatrix2[3][3] = {
	{1   ,    0    ,   0},
	{0     ,  0.707388 ,- 0.706825},
	{0     ,  0.706825     ,   0.707388}
};


// 3)matrix 3
//Vector p2(10, 0, 0);
Vector transformVector3(const Vector& v, const double matrix3[3][3]) {
	double newX3 = matrix3[0][0] * v.x + matrix3[0][1] * v.y + matrix3[0][2] * v.z;
	double newY3 = matrix3[1][0] * v.x + matrix3[1][1] * v.y + matrix3[1][2] * v.z;
	double newZ3 = matrix3[2][0] * v.x + matrix3[2][1] * v.y + matrix3[2][2] * v.z;
	return Vector(newX3, newY3, newZ3);
}
double transformationMatrix3[3][3] = {
	{0.707388   ,     0   ,    0.706825},
	{0    ,   1     ,  0},
	{-0.706825 ,      0    ,   0.707388}
};


void display() {
	//glClearColor(1.0, 1.0, 1.0, 1.0);//white
	glClearColor(0.0, 0.0, 0.0, 0.0);//black
	glClear(GL_COLOR_BUFFER_BIT);

	//original vector
	glColor3f(1.0, 0.0, 0.0); //  red color for vector 
	glBegin(GL_LINES);
	glVertex3d(0, 0, 0);
	glVertex3d(p2.x, p2.y, p2.z);
	glEnd();

	// 1) transform the vector 1
	Vector transformedVector1 = transformVector1(p2, transformationMatrix1);
	//draw transformed vector 1
	glColor3f(0.0, 1.0, 0.0); //  green color for vector 
	glBegin(GL_LINES);
	glVertex3d(0, 0, 0);
	glVertex3d(transformedVector1.x, transformedVector1.y, transformedVector1.z);
	glEnd();


	// 2) transform the vector 2
	Vector transformedVector2 = transformVector2(transformedVector1, transformationMatrix2);
	//draw transformed vector 2
	glColor3f(1.0, 1.0, 1.0); //  white color for vector 
	glBegin(GL_LINES);
	glVertex3d(0, 0, 0);
	glVertex3d(transformedVector2.x, transformedVector2.y, transformedVector2.z);
	glEnd();


	// 3) transform the vector 3
	Vector transformedVector3 = transformVector3(transformedVector2, transformationMatrix3);
	//draw transformed vector 2
	glColor3f(0.0, 0.0, 1.0); //  blue color for vector 
	glBegin(GL_LINES);
	glVertex3d(0, 0, 0);
	glVertex3d(transformedVector3.x, transformedVector3.y, transformedVector3.z);
	glEnd();


	glFlush();
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowPosition(300, 50);//set window pos.
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutCreateWindow("OpenGL Vectors");
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10, 10, -10, 10);

	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}


/*
uniform scaling matrix:
3 0 0 0
0 3 0 0
0 0 3 0
0 0 0 1
----------------------------------------------
rotationh matrix for Z angle:
{0.707388 ,-0.706825,0},
	{0.706825 ,0.707388,0},
	{0,0,1}
-----------------------------------------------
rotationh matrix for X angle:
1       0       0
0       0.707388        -0.706825
0       0.706825        0.707388
.................................................
rotationh matrix for Y angle:
0.707388        0       0.706825
0       1       0
-0.706825       0       0.707388
*/