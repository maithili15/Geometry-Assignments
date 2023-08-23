#include <GL/glut.h>
#include <cmath>
#include <vector>

struct Point {
	double x, y, z;
	Point(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}
};

std::vector<double> calculateCrossProduct(const std::vector<double>& a, const std::vector<double>& b) {
	std::vector<double> crossProduct(3);
	crossProduct[0] = a[1] * b[2] - a[2] * b[1];
	crossProduct[1] = a[2] * b[0] - a[0] * b[2];
	crossProduct[2] = a[0] * b[1] - a[1] * b[0];
	return crossProduct;
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Draw Vector A 
	std::vector<double> vectorA = { 10.0, 0.0, 0.0 }; // Vector A coordinates
	glColor3f(0.0, 0.0, 1.0);//BLUE
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(vectorA[0], vectorA[1], vectorA[2]);
	glEnd();

	// Draw Vector B 
	std::vector<double> vectorB = { 0.0, 10.0, 0.0 }; // Vector B coordinates
	glColor3f(0.0, 1.0, 0.0);//green
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(vectorB[0], vectorB[1], vectorB[2]);
	glEnd();

	// Calculate and Draw Cross Product 
	std::vector<double> vectorR = calculateCrossProduct(vectorA, vectorB);
	glColor3f(1.0, 0.0, 0.0);//red
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(vectorR[0], vectorR[1], vectorR[2]);
	glEnd();

	glFlush();
}

void reshape(int width, int height) {
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, (float)width / height, 1, 100); // Adjust the perspective projection
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(15, 10, 15, 0, 0, 0, 0, 1, 0); // Adjust the camera position and orientation
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(" 3D Space");
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}

