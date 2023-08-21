// Circle Points and Co-ordinates.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
	double x1, y1,r,x2,y2;
	double dx, dy, d;
	cout << "Enter the center co-ordinates of circle: ";
	cin >> x1 >> y1;
	cout << "Enter the radius: ";
	cin >> r;
	cout << "Enter point co-ordinates: ";
	cin >> x2 >> y2;

	//distance between center point and point
	
		dx = x2 - x1;
		dy = y2 - y1;
		d =sqrt(dx*dx + dy * dy);
		//cout << "Distnace between point and center of circle: " << d;
	
	
	if (d > r)
		cout << "Point " << x2 << " " << y2 << " lies outside the circle."<<endl;

	if (d < r)
		cout << "Point " << x2 << " " << y2 << " lies inside the circle." << endl;

	if (d == r)
		cout << "Point " << x2 << " " << y2 << " lies on the circle." << endl;
}
