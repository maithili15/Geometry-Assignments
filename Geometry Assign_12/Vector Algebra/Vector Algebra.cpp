#include <iostream>
#include <cmath>
#include <vector>
#include <GL/glut.h>
using namespace std;
struct Point {
	double x, y, z;
	Point(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}
};
struct Vector {
	Vector(){}
	double x, y, z;
	Vector(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}
};
Point p1(0, 0, 0), p2(10, 0, 0);
Point p3(0, 0, 0), p4(0, 10, 0);
Point p5(0, 0, 0), p6(10, 10, 0);

Vector A(p2.x - p1.x, p2.y - p1.y, p2.z - p1.z);
Vector B(p4.x - p3.x, p4.y - p3.y, p4.z - p3.z);
Vector C(p6.x - p5.x, p6.y - p5.y, p6.z - p5.z);




/*
double dotProduct(const Vector& a, const Vector& b) {
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

double magnitude(const Vector& v) {
	return std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

double angleBetweenVectors(const Vector& a, const Vector& b) {
	return std::acos(dotProduct(a, b) / (magnitude(a) * magnitude(b)));
}


bool areVectorsCoplanar(const Vector& a, const Vector& b, const Vector& c) {
	Vector cross = crossProduct(a, b);
	return cross.x == 1 && cross.y == 1 && cross.z == 1;
}
*/

void display() {
	//glClearColor(1.0, 1.0, 1.0, 1.0);//white
	glClearColor(0.0, 0.0, 0.0, 0.0);//black
	glClear(GL_COLOR_BUFFER_BIT);
	

	glColor3f(1.0, 0.0, 1.0); // pink color for vector A
	glBegin(GL_LINES);
	glVertex3d(0,0,0);
	glVertex3d(A.x, A.y, A.z);
	glEnd();

	
	glColor3f(0.0, 1.0, 1.0); // ciyan color for vector b
	glBegin(GL_LINES);
	glVertex3d(0, 0, 0);
	glVertex3d(B.x, B.y, B.z);
	//glVertex3d(10, 0, 0);
	glEnd();
	
	
	glColor3f(0.0, 0.0, 1.0); // blue color for vector c
	glBegin(GL_LINES);
	glVertex3d(0, 0, 0);
	glVertex3d(C.x, C.y, C.z);
	glEnd();

	glFlush();
}



int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowPosition(300, 70);//set window pos.
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutCreateWindow("OpenGL Vectors");
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//gluOrtho2D(0.0, 499.0, 0.0, 499.0);
	gluOrtho2D(-10, 10, -10, 10);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}





/*
#include <iostream>
#include <cmath>
#include <vector>

struct Point {
	double x, y, z;
	Point(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}
};

struct Vector {
	double x, y, z;
	Vector(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}
};

Vector crossProduct(const Vector& a, const Vector& b) {
	return Vector(a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x);
}

double dotProduct(const Vector& a, const Vector& b) {
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

double magnitude(const Vector& v) {
	return std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

double angleBetweenVectors(const Vector& a, const Vector& b) {
	return std::acos(dotProduct(a, b) / (magnitude(a) * magnitude(b)));
}

bool areVectorsCoplanar(const Vector& a, const Vector& b, const Vector& c) {
	Vector cross = crossProduct(a, b);
	return cross.x == 0 && cross.y == 0 && cross.z == 0;
}

int main() {
	Point p1(0, 0, 0), p2(10, 0, 0);
	Point p3(0, 0, 0), p4(0, 10, 0);
	Point p5(0, 0, 0), p6(10, 10, 0);

	Vector A(p2.x - p1.x, p2.y - p1.y, p2.z - p1.z);
	Vector B(p4.x - p3.x, p4.y - p3.y, p4.z - p3.z);
	Vector C(p6.x - p5.x, p6.y - p5.y, p6.z - p5.z);

	Vector crossAB = crossProduct(A, B);
	double dotAC = dotProduct(A, C);
	Vector perpendicularC = Vector(-C.y, C.x, C.z);

	double angleAC = angleBetweenVectors(A, C);

	bool coplanar = areVectorsCoplanar(A, B, C);

	std::cout << "Cross product of A and B: (" << crossAB.x << ", " << crossAB.y << ", " << crossAB.z << ")\n";
	std::cout << "Dot product of A and C: " << dotAC << "\n";
	std::cout << "Perpendicular vector for C: (" << perpendicularC.x << ", " << perpendicularC.y << ", " << perpendicularC.z << ")\n";
	std::cout << "Angle between A and C: " << angleAC << " radians\n";
	std::cout << "Are A and C coplanar? " << (coplanar ? "Yes" : "No") << "\n";

	return 0;
}
*/