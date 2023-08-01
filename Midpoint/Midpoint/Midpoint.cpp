// Midpoint.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<cmath>
using namespace std;
struct Point {
	double x, y, z;
};
class midpoint {
public:
	double getMidpoint(Point& a,Point& b) {
		double res1 = (a.x + b.x)/2;
		double res2 = (a.y + b.y)/2;
		double res3 = (a.z + b.z)/2;
		cout <<"Midpoints of x,y,z:  "<< res1 << " " << res2 << " " << res3 << " ";
		return 0;
	}
};
int main()
{
	midpoint m;
	Point p1, p2;
	cout << "enter 2 values for x:";
	cin >> p1.x >> p2.x;
	cout << "enter 2 values for y:";
	cin >> p1.y >> p2.y;
	cout << "enter 2 values for z:";
	cin >> p1.z >> p2.z;
	double output = m.getMidpoint(p1, p2);
	//.cout << "output is:" << output;
}


