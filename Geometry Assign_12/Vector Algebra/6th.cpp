//double angleBetweenVectors(const Vector& a, const Vector& b) {
//	return std::acos(dotProduct(a, b) / (magnitude(a) * magnitude(b)));
//}


#include <GL/glut.h>
#include <cmath>
#include<iostream>
#define M_PI 3.141592653589793238463
using namespace std;
struct Vector {
	double x, y, z;
	Vector(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}
};


double dotProduct(const Vector& a, const Vector& c) {
	return a.x * c.x + a.y * c.y + a.z * c.z;
}

double magnitude(const Vector& v) {
	return std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

double angleBetweenVectors(const Vector& a, const Vector& c) {
	double radians= acos(dotProduct(a, c) / (magnitude(a) * magnitude(c)));
	double degrees = radians * (180.0 / M_PI);
	return degrees;
	
}


int main() {
	Vector A(10,0,0);
	Vector B(0, 10, 0);
	Vector C(10, 10, 0);
	
	double dotAC = dotProduct(A, C);
	
	double angleAC = angleBetweenVectors(A, C);

	cout << "Dot product of A and C: " << dotAC << "\n";
	cout << "Angle between A and C: " << angleAC << " degree\n";

	return 0;
}