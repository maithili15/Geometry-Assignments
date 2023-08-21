// Point Transformation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#define M_PI 3.14
using namespace std;
struct Vector {
	double x, y, z;
	Vector(double _x, double _y, double _z) :x(_x), y(_y), z(_z) {}
};

// 1) Transform the Vector A with given transformation matrix. 
vector<vector<double>>transformationMatrix = {
		{0,0,1},
		{0,1,0},
		{-1,0,0}
};
//given vector
Vector A(10, 0, 0);
//matrix vector multiplication
Vector transformedA(
	A.x*transformationMatrix[0][0] + A.y*transformationMatrix[0][1] + A.z*transformationMatrix[0][2],
	A.x*transformationMatrix[1][0] + A.y*transformationMatrix[1][1] + A.z*transformationMatrix[1][2],
	A.x*transformationMatrix[2][0] + A.y*transformationMatrix[2][1] + A.z*transformationMatrix[2][2]
);


// 2) Prepare a transformation matrix for rotation around z axis by 45 degree.
vector<vector<double>>createRotationMatrixZ(double angleRadiansZ) {
	double cosTheta = cos(angleRadiansZ);
	double sinTheta = sin(angleRadiansZ);
	vector<vector<double>>rotationMatrixZ(3, vector<double>(3, 0.0));
	rotationMatrixZ[0][0] = cosTheta;
	rotationMatrixZ[0][1] = -sinTheta;
	rotationMatrixZ[1][0] = sinTheta;
	rotationMatrixZ[1][1] = cosTheta;
	rotationMatrixZ[2][2] = 1.0;
	return rotationMatrixZ;
}


// 3)  Prepare a transformation matrix for uniform scaling of 3.
using Matrix3 = vector<vector<double>>;
Matrix3 createScalingMatrix(double scaleFactor)
{
	Matrix3 scaleMatrix(4, vector<double>(4, 0.0));
	scaleMatrix[0][0] = scaleFactor;
	scaleMatrix[1][1] = scaleFactor;
	scaleMatrix[2][2] = scaleFactor;
	scaleMatrix[3][3] = 1.0;
	return scaleMatrix;
}
void printMatrix(const Matrix3& matrix) {
	for (const auto& row : matrix) {
		for (double value : row) {
			cout << value << " ";
		}
		cout << "\n";
	}
}


// 4) Prepare a transformation matrix for rotation by 45 deg around Y axis and also rotation by 45 deg around X axis.

vector<vector<double>>createRotationMatrixX(double angleRadiansX) {
	double cosTheta = cos(angleRadiansX);
	double sinTheta = sin(angleRadiansX);
	vector<vector<double>>rotationMatrixX(3, vector<double>(3, 0.0));
	rotationMatrixX[0][0] = 1.0;
	rotationMatrixX[1][2] = -sinTheta;
	rotationMatrixX[2][1] = sinTheta;
	rotationMatrixX[1][1] = cosTheta;
	rotationMatrixX[2][2] = cosTheta;
	return rotationMatrixX;
}

vector<vector<double>>createRotationMatrixY(double angleRadiansY) {
	double cosTheta = cos(angleRadiansY);
	double sinTheta = sin(angleRadiansY);
	vector<vector<double>>rotationMatrixY(3, vector<double>(3, 0.0));
	rotationMatrixY[0][0] = cosTheta;
	rotationMatrixY[2][0] = -sinTheta;
	rotationMatrixY[0][2] = sinTheta;
	rotationMatrixY[2][2] = cosTheta;
	rotationMatrixY[1][1] = 1.0;
	return rotationMatrixY;
}



int main()
{

	// 1) display transformation
	cout << "Transformed vector A:" << transformedA.x << "," << transformedA.y << "," << transformedA.z << "\n";
	cout << "-----------------------------------------------";
	// 2) display rotation at z
	double rotationAngleRadianZ = 45.0*(M_PI / 180.0);
	vector<vector<double>>rotationMatrixZ = createRotationMatrixZ(rotationAngleRadianZ);
	cout << "\n";
	cout << "rotationh matrix for Z angle:" << endl;
	for (const auto& row : rotationMatrixZ) {
		for (double value : row) {
			cout << value << "\t";
		}
		cout << endl;
	}
	cout << "-----------------------------------------------";

	// 3) display uniform scaling
	double scaleFactor = 3.0;
	Matrix3 scaleMatrix = createScalingMatrix(scaleFactor);
	cout << "\n";
	cout << "uniform scaling matrix:" << endl;
	printMatrix(scaleMatrix);
	cout << "-----------------------------------------------";

	// 4) display rotation at y
	double rotationAngleRadianX = 45.0*(M_PI / 180.0);
	vector<vector<double>>rotationMatrixX = createRotationMatrixX(rotationAngleRadianX);
	cout << "\n";
	cout << "rotationh matrix for X angle:" << endl;
	for (const auto& row : rotationMatrixX) {
		for (double value : row) {
			cout << value << "\t";
		}
		cout << endl;
	}
	cout << ".................................................";
	double rotationAngleRadianY = 45.0*(M_PI / 180.0);
	vector<vector<double>>rotationMatrixY = createRotationMatrixY(rotationAngleRadianY);
	cout << "\n";
	cout << "rotationh matrix for Y angle:" << endl;
	for (const auto& row : rotationMatrixY) {
		for (double value : row) {
			cout << value << "\t";
		}
		cout << endl;
	}
	cout << "-----------------------------------------------";

	return 0;
}
