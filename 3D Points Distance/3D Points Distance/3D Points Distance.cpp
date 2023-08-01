// 3D Points Distance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<math.h>
using namespace std;
struct distance1 {
	float x, y,z;
};
class distancePoints {
public:
float getDistance(const distance1& a, const distance1& b) {
		float cal1 = (a.x - b.x);
		float cal2 = (a.y - b.y);
		float cal3 = (a.z - b.z);
		return sqrt((cal1*cal1) + (cal2*cal2) + (cal3*cal3));
		
	}
};
int main()
{
	distancePoints d;
	distance1 d1 ,d2,d3;
	cout << "enter co-ordinates of x1, y1, z1:";
	cin >> d1.x >> d1.y>>d1.z;
	cout << "enter co-ordinates of x2, y2, z2:";
	cin >> d2.x >> d2.y>>d2.z;
	

	float result1 = d.getDistance(d1, d2);
	cout << "total distance is:"<<result1 ;

	

}

