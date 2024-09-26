/*Line.hpp
* Author: Tengxiao Fan
* A class that include two points, which are the start and end points of a line.
*/

#ifndef LINE_HPP
#define LINE_HPP
#include "Point.hpp"
#include "Shape.hpp"

class Line:public Shape
{
private:
	//Datas, not accessible to users.
	Point startpoint;//start point of the line
	Point endpoint;//end point of the line

public:
	//Member functions, accessible to users
	// 
	//Constructors and destructors
	Line();//Default
	Line(const Point& startpt, const Point& endpt);//Initialized
	Line(const Line& source);//copy
	virtual ~Line();//Destructor

	//Overload Getters
	const Point& P1() const;//Get the start point
	const Point& P2() const;//Get the end point

	//Overload Setters
	void P1(const Point& startpt);//Set the start point 
	void P2(const Point& endpt);//Set the end point

	//String Description function
	std::string ToString() const;//Output the string description of the Line

	//Line length function
	double Length() const;//Output the length of the line

	//Assignment Operator
	const Line& operator = (const Line& source);
	//PVMF that draws the shape.
	void Draw() const;

};
std::ostream& operator << (std::ostream& os, const Line& line); // Send to ostream.

#endif