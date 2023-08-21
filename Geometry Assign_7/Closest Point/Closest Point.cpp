// Closest Point.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

struct Point {
	double x, y;
};

//fn to calculate distance between 2 points
double distance(Point A, Point B) {
	double dx = A.x - B.x;
	double dy = A.y - B.y;
	return sqrt(dx*dx + dy * dy);
}

//fn to calculate dot product
//dot prodcut--- 
double dotProcudt(Point A, Point B) {
	return A.x*B.x + A.y*B.y;
}

//fn to find  point on line segment AB to point P
Point PointOnLine(Point A, Point B, Point P) {
	Point AB = { B.x - A.x,B.y - A.y };       //vector calculation
	Point AP = { P.x - A.x,P.y - A.y };      //vector calculation
	double dot = dotProcudt(AB, AP);        //dot product calculation
	double lenAB = distance(A, B);		   //calculate length of AB
	double t = dot / (lenAB*lenAB);        
	t = max(0.0, min(t, 1.0));            //[0 to 1 range] i.e point Q lies within bounds of segment AB
	Point Q = { A.x + t * AB.x,A.y + t * AB.y };  //calculate closest point using formula
	return Q;

}

Point findClosestPointToLine(Point A, Point B, vector<Point>& points) {
	Point closestPoint;  //store co-ordinates of closest point
	double minDistance = numeric_limits<double>::max();   //fun return max number
	for (const auto& P : points) {
		Point Q = PointOnLine(A, B, P);
		double dist = distance(P, Q); //store current position pf PQ
		if (dist < minDistance) { //check current pos.  is less than current min. pos  //if true , current pos. P is closer to AB
			minDistance = dist;   //update mindistance to store new co-ordinates 
			closestPoint = Q;      //update with new point
		}
	}
	return closestPoint;
}
int main()
{
	Point A = { 2,2 };
	Point B = { 10,10 };
	vector<Point>points = {
		{4,4},{5,5},{6,6},{7,7}, {8,8},{9,9}
	};
	Point closestPoint = findClosestPointToLine(A, B, points);
	cout << " point p: " << closestPoint.x << " " << closestPoint.y<< endl;
}



















/*
#include <iostream>
#include <vector>
#include <cmath>
struct Point
{
	double x;
	double y;
};

// Function to calculate the squared distance between two points
double distance_squared(const Point &p1, const Point &p2)
{
	double dx = p1.x - p2.x;
	double dy = p1.y - p2.y;
	return dx * dx + dy * dy;
}
// Function to find the closest point to a line segment from a list of points
Point find_closest_point(const Point &S, const Point &E, const std::vector<Point> &points)
{
	// Step 1: Represent the line segment as a vector
	Point vector_SE = { E.x - S.x, E.y - S.y };
	// Initialize variaes to store the closest point and its squared distance
	Point closest_point = points[0];
	double closest_distance_squared = distance_squared(points[0], S);
	for (const Point &P : points)
	{
		// Step 2: Calculate the projection of point P onto the line segment
		Point vector_SP = { P.x - S.x, P.y - S.y };
		double dot_product = vector_SP.x * vector_SE.x + vector_SP.y * vector_SE.y;
		double t = dot_product / distance_squared(S, E);
		Point projection;
		if (t <= 0.0)
		{
			// Point P projects outside the line segment and is closest to the start point S
			projection = S;
		}
		else if (t >= 1.0)
		{
			// Point P projects outside the line segment and is closest to the end point E
			projection = E;
		}
		else
		{
			// Point P projects inside the line segment
			projection = { S.x + t * vector_SE.x, S.y + t * vector_SE.y };
		}
		// Step 4: Check if the projection point is closer than the current closest point
		double distance_squared_to_projection = distance_squared(P, projection);
		if (distance_squared_to_projection < closest_distance_squared)
		{
			closest_distance_squared = distance_squared_to_projection;
			closest_point = projection;
		}
	}
	return closest_point;
}

int main()
{
	Point S = { 1.0, 1.0 }; // Starting point
	Point E = { 5.0, 3.0 }; // End point of the line segment
	std::vector<Point> points = {
		{2.0, 4.0},
		{3.0, 1.0},
		{6.0, 2.0} };
	Point closest_point = find_closest_point(S, E, points);
	std::cout << "Closest point: (" << closest_point.x << ", " << closest_point.y << ")" << std::endl;
	return 0;
}
*/