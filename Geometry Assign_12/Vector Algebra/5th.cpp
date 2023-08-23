//#include <GL/glut.h>
//#include <cmath>
//#include <vector>
//using namespace std;
//struct Point {
//	double x, y, z;
//	Point(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}
//};
//double calculateDotProduct1(const vector<double>& a, const vector<double>& c) {
//	int product1 = 0,i;
//	for (i = 0; i < a.size(); i++)
//		product1 = product1+a[i] * c[i];
//	return product1;
//}
//double calculateDotProduct2(const vector<double>& b, const vector<double>& c) {
//	int product2 = 0,i;
//	for (i = 0; i <b.size(); i++)
//		product2 += b[i] * c[i];
//	return product2;
//}
//
//
//void display() {
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	// Draw Vector A 
//	vector<double> vectorA = { 10.0, 0.0, 0.0 }; // Vector A coordinates
//	glColor3d(0.0, 0.0, 1.0);//BLUE
//	glBegin(GL_LINES);
//	glVertex3d(0.0, 0.0, 0.0);
//	glVertex3d(vectorA[0], vectorA[1], vectorA[2]);
//	glEnd();
//
//	// Draw Vector b
//	vector<double> vectorB = { 0.0, 10.0, 0.0 }; // Vector B coordinates
//	glColor3d(1.0, 1.0, 0.0);//YELLOW
//	glBegin(GL_LINES);
//	glVertex3d(0.0, 0.0, 0.0);
//	glVertex3d(vectorB[0], vectorB[1], vectorB[2]);
//	glEnd();
//
//
//	// Draw Vector c 
//	vector<double> vectorC = { 10.0, 10.0, 0.0 }; // Vector C coordinates
//	glColor3d(0.0, 1.0, 0.0);//green
//	glBegin(GL_LINES);
//	glVertex3d(0.0, 0.0, 0.0);
//	glVertex3d(vectorC[0], vectorC[1], vectorC[2]);
//	glEnd();
//
//	// Calculate and Draw Cross Product OF A & C
//	double vectorR1 = calculateDotProduct1(vectorA, vectorC);
//	glColor3d(1.0, 0.0, 0.0);//red
//	glBegin(GL_LINES);
//	glVertex3d(0.0, 0.0, 0.0);
//	glVertex3d(vectorR1, vectorR1, vectorR1);
//	glEnd();
//
//	// Calculate and Draw Cross Product OF C & B
//	double vectorR2 = calculateDotProduct2(vectorB, vectorC);
//	glColor3d(0.0, 1.0, 1.0);//cyan
//	glBegin(GL_LINES);
//	glVertex3d(0.0, 0.0, 0.0);
//	glVertex3d(vectorR2, vectorR2, vectorR2);
//	glEnd();
//
//
//	
//	glFlush();
//}
//
//void reshape(int width, int height) {
//	glViewport(0, 0, width, height);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(45, (float)width / height, 1, 100); // Adjust the perspective projection
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	gluLookAt(15, 10, 15, 0, 0, 0, 0, 1, 0); // Adjust the camera position and orientation
//
//}
//
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
//	glutInitWindowSize(800, 600);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow(" 3D");
//	glEnable(GL_DEPTH_TEST);
//	glClearColor(0.0, 0.0, 0.0, 1.0);
//	glutDisplayFunc(display);
//	glutReshapeFunc(reshape);
//	glutMainLoop();
//	return 0;
//}
//


#include <GL/glut.h>
#include <cmath>
struct Vector {
	double x, y, z;
	Vector(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}
};

Vector calculatePerpendicular(const Vector& original) {
	return Vector(original.y, -original.x, original.z);
	//(-y)=rotate 90 degrees counterclockwise relative or vec. c
	//(-x)=rotate 90 degrees clockwise relative or vec. c
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Original Vector C
	Vector vectorC(10.0, 10.0, 0.0);
	glColor3d(0.0, 1.0, 0.0); // Green color for Vector C
	glBegin(GL_LINES);
	glVertex3d(0.0, 0.0, 0.0);
	glVertex3d(vectorC.x, vectorC.y, vectorC.z);
	glEnd();

	// Calculate Perpendicular Vector
	Vector perpenC = calculatePerpendicular(vectorC);
	// Draw Perpendicular Vector
	glColor3d(1.0, 0.0, 0.0); // Red color for Perpendicular Vector
	glBegin(GL_LINES);
	glVertex3d(0.0, 0.0, 0.0);
	glVertex3d(perpenC.x, perpenC.y, perpenC.z);
	glEnd();
	glFlush();
}



void reshape(int width, int height) {
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, (float)width / height, 1, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(15, 10, 15, 0, 0, 0, 0, 1, 0);
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Perpendicular Vector in 3D Space");
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}