// Intersecting points.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
bool isInteresecting(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4,double& x,double& y) {
	double a1 = y2 - y1;
	double b1 = x1 - x2;
	double c1 = a1 * x1 + b1 * y1;

	double a2 = y4 - y3;
	double b2 = x3 - x4;
	double c2 = a2 * x3 + b2 * y3;

	double determinant = a1 * b2 - a2 * b1;

	if (determinant == 0) {
		return false;
	}
	else {
		x = (c1*b2 - c2 * b1) / determinant;
		y = (a1*c2 - a2 * c1) / determinant;
		return true;
	}
}
int main()
{
	double x1, y1, x2, y2, x3, y4,y3,x4;
	cout << "enter start and end points of first line i.e(x1 y1 x2 y2):";
	cin >> x1 >> y1 >> x2 >> y2 ;

	cout << "enter start and end points of second line i.e(x3 y3 x4 y4):";
	cin >> x3 >> y3 >> x4 >> y4;

	double intersectionX, intersectionY;
	bool isParallel = isInteresecting(x1, y1, x2, y2, x3, y3, x4, y4, intersectionX, intersectionY);

	if (isParallel) {
		cout << "lines are not parallel." << endl;
		cout << "intersection point p:" << intersectionX << " ," << intersectionY << endl;
	}
	else
	{
		cout << "lines are parallel" << endl;
	}
	return 0;
}
