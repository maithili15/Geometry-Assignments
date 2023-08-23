//scaler triple product--->A.(A*C)==0 ----> its coplanar

#include<iostream>
#include<cmath>
#include<vector>
#include<GL/glut.h>
using namespace std;

struct Vector {
	double x, y, z;
	Vector(double _x, double _y, double _z);
};
//dots prod A & C
double dot(const vector<double>& a, const vector<double>& c) {
	double result = 0.0;
	for (size_t i = 0; i < a.size(); i++) {
		result += a[i] * c[i];
	}
	return result;
}

//cross prod A & C
vector <double>calculateCrossProduct(vector<double>& a, vector<double>& c) {
	vector<double> crossProduct(3);
	crossProduct[0] = a[1] * c[2] - a[2] * c[1];
	crossProduct[1] = a[2] * c[0] - a[0] * c[2];
	crossProduct[2] = a[0] * c[1] - a[1] * c[0];
	return crossProduct;
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	//DRAW square
	glBegin(GL_QUADS);
	glColor3d(0.0, 0.0, 1.0);//blue color
	glVertex3d(-10.0, -10.0, 0.0);//bottom left
	glVertex3d(10.0, -10.0, 0.0);//bottom right
	glVertex3d(10.0, 10.0, 0.0);//top right
	glVertex3d(-10.0, 10.0, 0.0);//top left
	glEnd();
	glutSwapBuffers();
}

void reshape(int width,int height) {
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double )width / height, 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(15.0, 15.0, 15.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

int main(int argc, char** argv) {
	vector<double> A = { 10, 0, 0 };
	vector <double>C = { 10, 10, 0 };

	vector<double> resCross = calculateCrossProduct(A, C);
	cout << "cross product : " << resCross[0] << "," << resCross[1] << "," << resCross[2] << endl;
	double triple = dot(A, resCross);
	cout << "scaler triple product : " << triple << endl;

	if (triple == 0) {
		cout << "its coplanar" << endl;
	}
	else
	{
		cout << "its not coplanar" << endl;

	}

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutCreateWindow("square");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}