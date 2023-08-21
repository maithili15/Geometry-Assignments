//#include<iostream>
//#include<fstream>
//#include<sstream>
//#include<vector>
//#include<string>
//#include <GL/glew.h>
//#include <GL/freeglut.h>
//#include <GL/GLU.h>
//#include<gl/GL.h>
//using namespace std;
//struct Vertex {
//	float x, y, z;
//};
//struct Triangle {
//	int v1, v2, v3;
//};
//
//vector<Vertex>vertices1;
//vector<Triangle>triangles;
//
//void parseStlFile(const string& filename) {
//	ifstream stlFile(filename,ios::binary);
//	if (!stlFile.is_open()) {
//		cerr << "failed to open" << endl;
//		return;
//	}
//
//	//skip the header (80 bytes)
//	stlFile.seekg(80);
//
//	uint32_t numTriangles;
//	stlFile.read(reinterpret_cast<char*>(&numTriangles), sizeof(numTriangles));
//
//	for (uint32_t i = 0; i < numTriangles; i++) {
//		float normal[3];
//		stlFile.read(reinterpret_cast<char*>(normal), sizeof(normal));
//
//		Vertex vertices[3];
//		for (int j = 0; j < 3; j++) {
//			stlFile.read(reinterpret_cast<char*>(&vertices[j]), sizeof(Vertex));
//			vertices1.push_back(vertices[j]);
//		}
//
//		//create new vertices if not already in list
//		for (int j = 0; j < 3; j++) {
//			int index = -1;
//			for (int k = 0; k < vertices1.size(); k++) {
//				if (vertices[j].x == vertices[k].x &&
//					vertices[j].y == vertices[k].y &&
//					vertices[j].z == vertices[k].z) {
//					index = k;
//					break;
//				}
//			}
//			if (index == -1) {
//				index = vertices1.size();
//				vertices1.push_back(vertices[j]);
//			}
//			triangles.push_back(Triangle{ index,index,index });
//		}
//	}
//
//	stlFile.close();
//}
//
//void display() {
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	glBegin(GL_TRIANGLES);
//
//	for (const Triangle& triangle : triangles) {
//		glVertex3f(vertices1[triangle.v1 - 1].x, vertices1[triangle.v1 - 1].y, vertices1[triangle.v1 - 1].z);
//		glVertex3f(vertices1[triangle.v2 - 1].x, vertices1[triangle.v2 - 1].y, vertices1[triangle.v2 - 1].z);
//		glVertex3f(vertices1[triangle.v3 - 1].x, vertices1[triangle.v3 - 1].y, vertices1[triangle.v3 - 1].z);
//	}
//	glEnd();
//	glutSwapBuffers();
//}
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
//	glutInitWindowSize(800, 800);
//	glutCreateWindow("open gl");
//	glEnable(GL_DEPTH_TEST);
//	parseStlFile("C:/Users/Maithili.Mali/source/repos/3D Geometry/stl_file.stl");
//	glutDisplayFunc(display);
//	glutMainLoop();
//	return 0;
//}








#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <GL/freeglut.h>
#include <GL/glut.h>
using namespace std;
struct Vertex {
	float x, y, z;
};
struct Normal {
	float nx, ny, nz;
};
struct Facet {
	Normal normal;
	Vertex v1, v2, v3;
};
vector<Facet> facets;
float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;
void readSTLFile(const string& filename) {
	ifstream file(filename, ios::in);
	string line;
	while (getline(file, line)) {
		istringstream iss(line);
		string keyword;
		iss >> keyword;
		if (keyword == "facet") {
			Facet facet;
			iss >> keyword; // "normal"
			iss >> facet.normal.nx >> facet.normal.ny >> facet.normal.nz;
			getline(file, line); // skip "outer loop"
			getline(file, line);
			istringstream v1Line(line);
			v1Line >> keyword >> facet.v1.x >> facet.v1.y >> facet.v1.z;
			getline(file, line);
			istringstream v2Line(line);
			v2Line >> keyword >> facet.v2.x >> facet.v2.y >> facet.v2.z;
			getline(file, line);
			istringstream v3Line(line);
			v3Line >> keyword >> facet.v3.x >> facet.v3.y >> facet.v3.z;
			getline(file, line); // skip "endloop"
			getline(file, line); // skip "endfacet"
			facets.push_back(facet);
		}
	}

	file.close();
}

void renderModel() {
	glBegin(GL_TRIANGLES);
	for (const Facet& facet : facets) {
		glNormal3f(facet.normal.nx, facet.normal.ny, facet.normal.nz);
		glVertex3f(facet.v1.x, facet.v1.y, facet.v1.z);
		glVertex3f(facet.v2.x, facet.v2.y, facet.v2.z);
		glVertex3f(facet.v3.x, facet.v3.y, facet.v3.z);
	}
	glEnd();
}

void printSTLData() {
	for (const Facet& facet : facets) {
		cout << "Facet Normal: " << facet.normal.nx << " " << facet.normal.ny << " " << facet.normal.nz << endl;
		cout << "  Vertex 1: " << facet.v1.x << " " << facet.v1.y << " " << facet.v1.z << endl;
		cout << "  Vertex 2: " << facet.v2.x << " " << facet.v2.y << " " << facet.v2.z << endl;
		cout << "  Vertex 3: " << facet.v3.x << " " << facet.v3.y << " " << facet.v3.z << endl;
		cout << endl;
	}
}

void init() {
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	GLfloat light_pos[] = { -1.0f, 10.0f, 100.0f, 1.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
	glClearColor(0.529f, 0.808f, 0.922f, 1.0f); // Sky blue window color
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(20.0, 1.0, 1.0, 2000.0);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_LINE_SMOOTH);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0f, -30.0f, -500.0f);
	glRotatef(angleX, 1.0f, 0.0f, 0.0f); // Rotate around X-axis
	glRotatef(angleY, 0.0f, 1.0f, 0.0f); // Rotate around Y-axis
	glRotatef(angleZ, 0.0f, 0.0f, 1.0f); // Rotate around Z-axis
	glScalef(50.0f, 50.0f, 50.0f);
	renderModel();
	glFlush();
	glutSwapBuffers();
}

void idle() {
	angleX += 0.5f; // Update rotation angle around X-axis
	angleY += 0.2f; // Update rotation angle around Y-axis
	angleZ += 0.3f; // Update rotation angle around Z-axis
	if (angleX > 360.0f) {
		angleX -= 360.0f;
	}
	if (angleY > 360.0f) {
		angleY -= 360.0f;
	}
	if (angleZ > 360.0f) {
		angleZ -= 360.0f;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	string filename = "C:/Users/Maithili.Mali/source/repos/3D Geometry/stl_file.stl";
	readSTLFile(filename);
	printSTLData();

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_MULTISAMPLE);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_MODELVIEW);
	//glHint(GL_MULTISAMPLE_FILTER_HINT_NV, GL_NICEST);
	glutSetOption(GLUT_MULTISAMPLE, 8);
	glutInitWindowPosition(650, 350);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Assignment14 Stl");
	init();
	glutDisplayFunc(display);
	glutIdleFunc(idle); // Register idle function
	glutMainLoop();

	return 0;
}