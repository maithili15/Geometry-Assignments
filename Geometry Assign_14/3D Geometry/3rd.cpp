#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
using namespace std;
struct Vertex {
	float x, y, z;
};
struct Triangle {
	Vertex normal;
	Vertex v1, v2, v3;
};
int main() {
	ifstream stlFile("C:/Users/Maithili.Mali/source/repos/3D Geometry/stl_file.stl");
	if (!stlFile.is_open()) {
		cerr << "failed to open" << endl;
		return 1;
	}

	vector<Triangle>triangles;

	string line;
	while (getline(stlFile, line)) {//read each line from obj file & store in 'line' var.
		istringstream iss(line); //'iss' obj of istringstream class
		string keyword;//store 1st token read from the line
		iss >> keyword;//uses stream operator to extract data from 'iss' stream and store in 'type' var.
		if (keyword == "facet") {   
			Triangle triangle;
			iss >> keyword>> keyword>> triangle.normal.x >> triangle.normal.y>> triangle.normal.z;
			getline(stlFile,line);
			for (int i = 0; i < 3; i++) {
				iss.clear();
				getline(stlFile, line);
				iss.str(line);
				iss >> keyword >> triangle.v1.x >> triangle.v1.y >> triangle.v1.z;

				iss.clear();
				getline(stlFile, line);
				iss.str(line);
				iss >> keyword >> triangle.v2.x >> triangle.v2.y >> triangle.v2.z;

				iss.clear();
				getline(stlFile, line);
				iss.str(line);
				iss >> keyword >> triangle.v3.x >> triangle.v3.y >> triangle.v3.z;

				getline(stlFile, line);
				getline(stlFile, line);

				triangles.push_back(triangle);
			}
		}
	}
	stlFile.close();

	//print extracted data
	for (const Triangle& triangle : triangles) {
		cout << "normal1:" << triangle.normal.x << triangle.normal.y << triangle.normal.z<<endl;
		cout << "vertex 1:" << triangle.v1.x << triangle.v1.y << triangle.v1.z << endl;
		cout << "vertex 2:" << triangle.v2.x << triangle.v2.y << triangle.v2.z << endl;
		cout << "vertex 3:" << triangle.v3.x << triangle.v3.y << triangle.v3.z << endl;
		cout << endl;
	}
	return 0;
}