/*Point.hpp
* Author: Tengxiao Fan
* A class that include a point with x- and y- coordinates.
*/

#ifndef POINT_HPP
#define POINT_HPP
#include <string>

class Point
{
private:
	//Datas, not accesible to users
	double m_x;//x-coordinate of the point
	double m_y;//y-coordinate of the point
public:
	//Member functions, accessible to users
	// 
	//Constructors and destructors
	Point();//Default
	Point(const Point& source);//Copy constructor
	Point(double initxvalue, double inityvalue);//constructor that initializes x and y
	~Point();

	//Getter functions
	double GetX();//Get the x-coordinate value
	double GetY();//Get the y-coordinate value

	//Setter functions
	void SetX(double newxvalue);//Set a new x-coordinate value
	void SetY(double newyvalue);//Set a new y-coordinate value

	//ToString function: Return a string description of the point
	std::string ToString();//

	//Distance functions
	double DistanceOrigin(); // Calculate the distance to the origin (0, 0).
	double Distance(Point p); // Calculate the distance between two points.

};

#endif
