#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
using namespace std;
struct Vertex {
	float x, y, z;
};
struct Face {
	int v1, v2, v3;
	int vn1, vn2, vn3;
};


int main() {
	ifstream objFile("C:/Users/Maithili.Mali/source/repos/3D Geometry/Obj_file.obj");
	if (!objFile.is_open()) {
		cerr << "failed to open" << endl;
		return 1;
	}

	vector<Vertex>vertices;
	vector<Face>faces;


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
			iss >> face.v1 >> face.vn1 >> face.vn1 >>
				face.v2 >> face.vn2 >> face.vn2 >>
				face.v3 >> face.vn3 >> face.vn3;
			faces.push_back(face);
		}

	}

	objFile.close();

	
	//print extracted data
	for (const Vertex& vertex : vertices) {
		cout << "v:" << vertex.x << " " << vertex.y << " " << vertex.z << endl;
	}
	cout << "total vertices:" << vertices.size() << endl;
	cout << "----------------------------------------"<<endl;


	for (const Face& face : faces) {
		cout << "f:" << face.v1 << " " << face.v2 << " " << face.v3 << endl;
	}
	cout << "total faces:" << faces.size() << endl;
	cout << "----------------------------------------" << endl;


	

	return 0;
}