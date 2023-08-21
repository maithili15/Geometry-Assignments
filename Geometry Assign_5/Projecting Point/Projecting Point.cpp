// Projecting Point.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
struct Point {
	double x, y;
};
Point projectPointOnLine(Point S, Point E, Point G) {
	Point P;

	//1.slope of line
	//y=mx+c
	//m=y/x
	double lineSlope = (E.y - S.y) / (E.x - S.x);

	//2. slope of perpendicular line
	double perpendicularSlope = -1.0 / lineSlope;

	//3.equation of line passing through G and perpendicular line SE  
	double perpendicularIntercept = G.y - perpendicularSlope * G.x;  //y-y1=m(x-x1)

	//4.intersection point of 2 line
	P.x = (perpendicularIntercept - S.y + lineSlope * S.y) / (lineSlope - perpendicularSlope);
	P.y = lineSlope * (P.x - S.x) + S.y;
	return P;



}
int main()
{
	Point S, E, G;
	cout << "enter co-ordinate of start point (s) (x,y):";
	cin >> S.x >> S.y;
	cout << "Enter co-ordinate of end point (e) (x,y):";
	cin >> E.x >> E.y;
	cout << "Enter co-ordinate of point (g)(x,y):";
	cin >> G.x >> G.y;
	Point p = projectPointOnLine(S, E, G);
	cout << "Project point:" << p.x << "," << p.y << endl;
	return 0;
}

