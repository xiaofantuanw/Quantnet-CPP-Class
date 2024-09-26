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
	Point(const double initxvalue, const double inityvalue);//constructor that initializes x and y, use const value
	~Point();

	//Getter functions
	double X() const;//Get the x-coordinate value (const)
	double Y() const;//Get the y-coordinate value (const)

	//Setter functions
	void X(const double newxvalue);//Set a new x-coordinate value, use const value
	void Y(const double newyvalue);//Set a new y-coordinate value, use const value

	//ToString function: Return a string description of the point(const)
	std::string ToString() const;//

	//Distance functions
	double Distance() const; // Calculate the distance to the origin (0, 0).(const)
	double Distance(const Point& p) const; // Calculate the distance between two points.(const)

};

#endif
