#include <GL/glut.h>
#include <cmath>
#include <vector>
using namespace std;
struct Point {
	double x, y, z;
	Point(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}
};

double calculateDotProduct(const std::vector<double>& a, const std::vector<double>& c) {

	int product = 0;
	for (int i = 0; i < a.size(); i++)
		product += a[i] * c[i];
	return product;

	/*double prod = a[0] * c[0] + a[1] * c[1] + a[2] * c[2];
	return prod;*/

}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Draw Vector A 
	std::vector<double> vectorA = { 10.0, 0.0, 0.0 }; // Vector A coordinates
	glColor3d(0.0, 0.0, 1.0);//BLUE
	glBegin(GL_LINES);
	glVertex3d(0.0, 0.0, 0.0);
	glVertex3d(vectorA[0], vectorA[1], vectorA[2]);
	glEnd();

	// Draw Vector c 
	std::vector<double> vectorC = { 10.0, 10.0, 0.0 }; // Vector C coordinates
	glColor3d(0.0, 1.0, 0.0);//green
	glBegin(GL_LINES);
	glVertex3d(0.0, 0.0, 0.0);
	glVertex3d(vectorC[0], vectorC[1], vectorC[2]);
	glEnd();

	// Calculate and Draw dot Product 
	double vectorR = calculateDotProduct(vectorA, vectorC);
	glColor3d(1.0, 0.0, 0.0);//red
	glBegin(GL_LINES);
	glVertex3d(0.0, 0.0, 0.0);
	glVertex3d(vectorR, vectorR, vectorR);
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

