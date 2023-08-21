#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/GLU.h>
#include<gl/GL.h>
using namespace std;

/*
struct Vertex {
	float x, y, z;
};
struct Face {
	int v1, v2, v3;
};

vector<Vertex>vertices;
vector<Face>faces;

void parseObjFile(const string& filename) {
	ifstream objFile(filename);
	if (!objFile.is_open()) {
		cerr << "failed to open" << endl;
		return ;
	}
	string line;
	while (getline(objFile, line)) {//read each line from obj file & store in 'line' var.
		istringstream iss(line); //'iss' obj of istringstream class
		string type;//store 1st token read from the line
		iss >> type;//uses stream operator to extract data from 'iss' stream and store in 'type' var.
		
		if (type == "v") {
			Vertex vertex;
			iss >> vertex.x >> vertex.y >> vertex.z;
			vertices.push_back(vertex);
		}
		else if (type == "f") {
			Face face;
			iss >> face.v1 >> face.v2 >> face.v3;
			faces.push_back(face);
		}
	}
	objFile.close();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glBegin(GL_TRIANGLES);


	for (const Face& face : faces) {//each face represent a triangle
		cout << "face indices" << face.v1 << " " << face.v2 << " " << face.v3 << endl;
		if (face.v1<1 || face.v1 >> vertices.size() ||
			face.v2<1 || face.v2 >> vertices.size() ||
			face.v3<1 || face.v3 >> vertices.size()) {
			cerr << "invalid" << endl;
		}

		for (const Face& face : faces) {
			glVertex3f(vertices[face.v1 - 1].x, vertices[face.v1 - 1].y, vertices[face.v1 - 1].z);
			glVertex3f(vertices[face.v2 - 1].x, vertices[face.v2 - 1].y, vertices[face.v2 - 1].z);
			glVertex3f(vertices[face.v3 - 1].x, vertices[face.v3 - 1].y, vertices[face.v3 - 1].z);

		}
		glEnd();
		glutSwapBuffers();
	}
}
int main(int argc,char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutCreateWindow("open gl");
	glEnable(GL_DEPTH_TEST);
	parseObjFile("C:/Users/Maithili.Mali/source/repos/3D Geometry/Obj_file.obj");
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
*/




/*
vector<int>vertices;
vector<int>indices;
vector<float>normal;
vector<int>line;


void parseObjFile(const string& filename) {
	ifstream objFile(filename);
	if (!objFile.is_open()) {
		cerr << "failed to open" << endl;
		return;
	}
	string line;
	while (getline(objFile, line)) {//read each line from obj file & store in 'line' var.
		istringstream iss(line); //'iss' obj of istringstream class
		string type;//store 1st token read from the line
		iss >> type;//uses stream operator to extract data from 'iss' stream and store in 'type' var.

		if (type == "v") {
			int x, y, z;
			vertices.push_back(x);
			vertices.push_back(y);
			vertices.push_back(z);

		}
		else if (type == "f") {
			int v1, v2, v3;
			iss >> v1 >> v2 >> v3;
			indices.push_back(v1);
			indices.push_back(v2);
			indices.push_back(v3);
		}
		else if (type == "vn") {
			int vn1, vn2, vn3;
			iss >> vn1 >> vn2 >> vn3;
			indices.push_back(vn1);
			indices.push_back(vn2);
			indices.push_back(vn3);
		}
		else if (type == "l") {
			int l1, l2, l3;
			iss >> l1 >> l2 >> l3;
			indices.push_back(l1 );
			indices.push_back(l2 );
			indices.push_back(l3);
		}
	}
	objFile.close();
	glutSwapBuffers();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	if (vertices.size() % 3 == 0 && indices.size() % 3 == 0 && normal.size() % 3 == 0) {
		//vertices
		glPointSize(10.0f);
		glBegin(GL_POINTS);
		//cout << vertices << endl;
		glColor3f(1.0f, 0.0f, 0.0f); //red color
		for (size_t i = 0; i < vertices.size(); i += 3) {
			glVertex3f(vertices[i], vertices[i + 1], vertices[i + 2]);
		}
		glEnd();


		//faces
		size_t i = 0;
		int index1 = (indices[i] - 1) * 3;
		int index2 = (indices[i + 1] - 1) * 3;
		int index3 = (indices[i + 2] - 1) * 3;
		if (index1 < vertices.size() && index2 < vertices.size() && index3 < vertices.size()) {
		glBegin(GL_TRIANGLES);
		glColor3f(0.0f, 1.0f, 0.0f); //gren color
			for (size_t i = 0; i < indices.size(); i += 3) {
				glVertex3f(vertices[index1], vertices[index1 + 1], vertices[index1 + 2]);
				glVertex3f(vertices[index2], vertices[index2 + 1], vertices[index2 + 2]);
				glVertex3f(vertices[index3], vertices[index3 + 1], vertices[index3 + 2]);
			}
		}
		glEnd();


		//normal as lines
		glBegin(GL_LINES);
		glColor3f(1.0f, 1.0f, 1.0f);//white
		for (size_t i = 0; i < line.size(); i += 2) {
			int index1 = (line[i] - 1) * 3;
			int index2 = (line[i + 1] - 1) * 3;
			if (index1 < vertices.size() && index2 < vertices.size()) {
				glVertex3f(vertices[index1], vertices[index1 + 1], vertices[index1 + 2]);
				glVertex3f(vertices[index2], vertices[index2 + 1], vertices[index2 + 2]);
			}
		}
		glEnd();
		glutSwapBuffers();
	}
}

int main(int argc,char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutCreateWindow("opengl");
	glEnable(GL_DEPTH_TEST);
	parseObjFile("C:/Users/Maithili.Mali/source/repos/3D Geometry/Obj_file.obj");
	glutDisplayFunc(display);
	glutMainLoop();
}
*/
//
//struct Vertex {
//	float x, y, z;
//};
//
//class Cube {
//private:
//	const vector<Vertex>& vertices;
//	const vector<int>& indices;
//public:
//	Cube(const vector<Vertex>& verts, const vector<int>& inds):vertices(verts),indices(inds) {
//
//	}
//	void draw()const {
//		glBegin(GL_TRIANGLES);
//		for (size_t i = 0; i < indices.size(); i += 3) {
//			int index1 = indices[i] - 1;
//			int index2 = indices[i + 1] - 1;
//			int index3 = indices[i + 2] - 1;
//
//			glVertex3f(vertices[index1].x, vertices[index1].y, vertices[index1].z);
//			glVertex3f(vertices[index2].x, vertices[index2].y, vertices[index2].z);
//			glVertex3f(vertices[index3].x, vertices[index3].y, vertices[index3].z);
//
//
//			
//		}
//		glEnd();
//	}
//};
//
//vector<Vertex>vertices;
//vector<int>indices;
//void parseObjFile(const string& filename) {
//	ifstream objFile(filename);
//	if (!objFile.is_open()) {
//		cerr << "failed" << endl;
//		return;
//	}
//
//	string line;
//	while (getline(objFile, line)) {
//		istringstream iss(line);
//		string type;
//		float x, y, z;
//		int v1, v2, v3;
//		if (type == "v") {
//			
//			iss >> x >> y >> z;
//			vertices.push_back({ x,y,z });
//			
//		}
//		else if (type == "f") {
//			
//			iss >> v1 >> v2 >> v3;
//			indices.push_back(v1);
//			indices.push_back(v2);
//			indices.push_back(v3);
//		}
//	
//		
//	}
//	
//	objFile.close();
//}
//
//Cube cube(vertices, indices);
//
//
//
//void display() {
//	glClear(GL_COLOR_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	cube.draw();
//	glutSwapBuffers();
//	glTranslatef(0.0f, -30.0f, -500.0f);
//	glRotatef(30.0f, 1.0f, -1.0f, 0.0f);
//	glScalef(50.0f, 50.0f, 50.0f);
//}
//
//
//
//
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
//	glutInitWindowSize(800, 800);
//	glutCreateWindow("open gl");
//	glEnable(GL_DEPTH_TEST);
//	parseObjFile("C:/Users/Maithili.Mali/source/repos/3D Geometry/obj_file.obj");
//	glutDisplayFunc(display);
//	glutMainLoop();
//
//
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//	GLfloat light_pos[] = { -1.0f, 10.0f, 100.0f, 1.0f };
//	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
//	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(20.0, 1.0, 1.0, 2000.0);
//	glMatrixMode(GL_MODELVIEW);
//	glEnable(GL_BLEND);
//	return 0;
//}
//










#include <fstream>
#include <math.h>
#include <time.h>
#include <vector>
#include <GL/freeglut.h>
#define WIDTH 600
#define HEIGHT 600
#define _CRT_SECURE_NO_WARNINGS //avoid warnings
using namespace std;
class Model {
	private:
	class Face {
	public:
		int edge;
		int* vertices;//hold indices of vertices that make up face
		int normal;
		Face(int edge, int* vertices, int normal = -1) //normal=-1, defualt value represent index of normal
		{
			this->edge = edge;
			this->vertices = vertices;
			this->normal = normal;
		}
	};

	vector<float*> vertices;//store pointers to 3 floating point values(x,y,z)coordinates
	vector<float*> normals;// is a vector i.e perpendicular to surface at specific point. 
	//help to determine how light interacts with surface of object, affect color, rendering and shading
	vector<Face> faces;//associated with polygons . set of vertices connected by edges
	GLuint list;//used to render model store all list id 

	public:
	void load(const char* filename) {
		string line;
		vector<string> lines;
		ifstream in(filename);
			if (!in.is_open()) {
				printf("Cannot load model %s\n", filename);
				return;
			}
		while (!in.eof())
		{
			getline(in, line);
			lines.push_back(line);
		}
		in.close();
		float a, b, c;
		for (string& line : lines)//iterate each line from obj file
		{
			if (line[0] == 'v') {
				if (line[1] == ' ') //if line contain space i.e this is vertex data
				{
					sscanf_s(line.c_str(), "v %f %f %f", &a, &b, &c);//parse then line based on format string and extract 3 values
					vertices.push_back(new float[3]{ a, b, c });//create dynamically array of 3 points n push into vertices vector
				} 
				else if (line[1] == 'n') {
					sscanf_s(line.c_str(), "vn %f %f %f", &a, &b, &c);//parse then line based on format string and extract 3 values
					normals.push_back(new float[3]{ a, b, c });//create dynamically array of 3 points n push into vertices vector
				}
			}
			else if (line[0] == 'f') {
				int v0, v1, v2, n;//store vertex indices-v0,v1,v2 and normal indices-n parsed from 'f' line
				sscanf_s(line.c_str(), "f %d//%d %d//%d %d//%d", &v0, &n, &v1, &n, &v2, &n);//parse then line based on format string and extract 3 values
				int* v = new int[3]{ v0 - 1, v1 - 1, v2 - 1 };//dynamic array to store adjusted vertex-1 to 0-based indices
				faces.push_back(Face(3, v, n - 1));//create face object with 3 edges ,array of vertex indices and adjusted normal index and add to face
			}
		}

		list = glGenLists(1);//generate new display list for rendering and allow you to compile 
		glNewList(list, GL_COMPILE);//indicate list is in compile mode
		for (Face& face : faces) //represent polygon face of 3d object
		{
			if (face.normal != -1)//if object has valid normal then set current normal vector,essential for rendering obj
				glNormal3fv(normals[face.normal]);//set current normal vector,essential for rendering obj
			else
				glDisable(GL_LIGHTING);//if normal is not valid means(-1),it disable lightling when rendering lines

			glBegin(GL_LINE_LOOP);//defining series of vertices for line,draw edges of face
			for (int i = 0; i < face.edge; i++)//within glbegin and glend-- loop iterate through vertices of current 'face', 
				glVertex3fv(vertices[face.vertices[i]]);//for each vertex it sets coordinates based on vertex indices stored in face.vertices()
			glEnd();

			/*if (face.normal == -1)
				glEnable(GL_LIGHTING);*/
		}
		glEndList();
		printf("Model In Drive: %s\n", filename);
		printf("Vertices In Obj File is: %d\n", vertices.size());
		printf("Normals In Obj File is: %d\n", normals.size());
		printf("Faces In Obj File is: %d\n", faces.size());
		for (float* f : vertices) //dynamically allocated to float,used to store vertex pos.
			delete f;//free up space for storing vertex pos.
		vertices.clear();
		for (float* f : normals)
			delete f;
		normals.clear();
		faces.clear();
	}
	void draw() {
		glCallList(list);//rendering model by calling list
	}
};

Model model;
void init() {
	/*glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);*/ //if its enabled then it shows color as lightning with black
	//GLfloat light_pos[] = { -1.0f, 10.0f, 100.0f, 1.0f };
	//glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
	glMatrixMode(GL_PROJECTION);//select matrix - 1)Model maps from an object's local coordinate space into world space, 
								// 2)view from world space to camera space, 3)projection from camera to screen.
	glLoadIdentity();
	gluPerspective(20.0, 1.0, 1.0, 2000.0);
	glMatrixMode(GL_MODELVIEW);// translates it to "world space" by multiplying it with the MODELVIEW, 
	glEnable(GL_BLEND);//blend incoming RGBA values with already stored RGBA values in buffer
	glEnable(GL_DEPTH_TEST);
	model.load("C:/Users/Maithili.Mali/source/repos/3D Geometry/obj_file.obj");
}

void display() {
	glClearColor(0.7, 0, 0, 1);//red bg color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();//translating from start over at the origin
	glTranslatef(0.0f, -30.0f, -500.0f);//translating from the matrix's current 'position'
	glRotatef(30.0f, 1.0f, -1.0f, 0.0f);//translating from the matrix which is now oriented in the default direction
	glScalef(50.0f, 50.0f, 50.0f);
	model.draw();
	glutSwapBuffers();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_MULTISAMPLE);
	glEnable(GL_MULTISAMPLE);
	glutSetOption(GLUT_MULTISAMPLE, 8);
	glutInitWindowPosition(650, 350);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Assignment14Obj");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}