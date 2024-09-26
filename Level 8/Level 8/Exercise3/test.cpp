/*test.cpp
* author:Tengxioa Fan
* This program tests the variant in boost
*/

#include "boost/variant.hpp"//Include the boost::variant
#include "Point.hpp"
#include "Circle.hpp"
#include "Line.hpp"
#include "Shape.hpp"
#include "MyVisitor.hpp"
#include <iostream>

using boost::variant;//Using the class
typedef variant<Point, Line, Circle> ShapeType;//A variant that contains shape types.

ShapeType makeshape()
{
	std::cout << "Please enter the shape type to create (Point, Line or Circle)"<<std::endl;
	//The user gives the shapetype
	std::string shape;
	std::cin >> shape;
	ShapeType result;
	if (shape == "Point")//Case1: Shapetype is Point
	{
		double x, y;
		std::cout << "Input x-coordinate" << std::endl;
		std::cin >> x;
		std::cout << "Input y-coordinate" << std::endl;
		std::cin >> y;//The user gives the coordinate of the point.
		Point pt(x, y);
		result = pt;//The result will be the point created.
	}
	else if (shape == "Line")
	{
		double x1, x2, y1, y2;//The coordinate of start and end points
		std::cout << "Input start point x-coordinate" << std::endl;
		std::cin >> x1;
		std::cout << "Input start point y-coordinate" << std::endl;
		std::cin >> y1;//The user gives the coordinate of the start point.
		std::cout << "Input end point x-coordinate" << std::endl;
		std::cin >> x2;
		std::cout << "Input end point y-coordinate" << std::endl;
		std::cin >> y2;//The user gives the coordinate of the end point.
		Line line(Point(x1, y1), Point(x2, y2));
		result = line;//The result will be line created
	}
	else if (shape == "Circle")
	{
		double xc, yc, r;
		std::cout << "Input center point x-coordinate" << std::endl;
		std::cin >> xc;
		std::cout << "Input center point y-coordinate" << std::endl;
		std::cin >> yc;//The user gives the coordinate of the center point.
		std::cout << "Input the radius" << std::endl;
		std::cin >> r;//The user gives the radius of the circle.
		Circle circle(Point(xc, yc), r);
		result = circle;//The result will be the circle created
	}
	return result;
}

int main()
{
	ShapeType MyShape1 = makeshape();
	std::cout << MyShape1 << std::endl;//Print the shape
	Line line1;
	try//Try to get the shape if it is a line
	{
		line1 = boost::get<Line>(MyShape1);
		std::cout <<"This is a line. "<< MyShape1 << std::endl;//Print the line
	}
	catch (boost::bad_get& err)//If MyShape1 is not a line, catch the error
	{
		std::cout << "Error: " << err.what() << std::endl;
	}
	MyVisitor visitor1(1,1);//Test the visitor
	boost::apply_visitor(visitor1, MyShape1);//Apply the visitor
	std::cout << MyShape1 << std::endl;//Print the shape again, the value has been changed by the visitor

	return 0;
}