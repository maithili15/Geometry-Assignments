// Rotating Line.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#define M_PI (3.14159265358979323846)
using namespace std;
struct Point {
	double x, y;
};
Point rotatePoint(Point p, double angle) {
	//angle convert degrees to radians
	double theta = angle * M_PI / 180.0;

	//calculate cos and sin
	double cosTheta = cos(theta);
	double sinTheta = sin(theta);

	//rotate point around origin using formula for 2d rotation.
	double xNew = p.x*cosTheta - p.y*sinTheta;
	double yNew = p.y*sinTheta + p.y*cosTheta;
	return { xNew,yNew };
}

Point rotateLineSegment(Point s, Point e1, double angle) {
	//calculate relative point e1 by substracting s from e1
	Point e1Relative = { e1.x - s.x,e1.y - s.y };

	//call rotatePoint() with e1relative and angle to get e2relative after rotation around origin
	Point e2Relative = rotatePoint(e1Relative, angle);

	//moves rotated endpoints e2relative back to its original position with respect to s and 
	//its done by adding s coordinates to e2relative
	Point e2 = { e2Relative.x + s.x,e2Relative.y + s.y };
	return e2;
}
int main()
{
	Point s, e1;
	double angle;
	cout << "enter co-ordinate points for s (x,y):";
	cin >> s.x >> s.y;
	cout << "enter co-ordinate points for e1 (x,y):";
	cin >> e1.x >> e1.y;
	cout << "enter angle:";
	cin >> angle;
	Point e2 = rotateLineSegment(s, e1, angle);
	cout << "E2 is:" << e2.x << " " << e2.y;
}

