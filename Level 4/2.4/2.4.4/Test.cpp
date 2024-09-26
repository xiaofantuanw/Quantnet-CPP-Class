/* Test.cpp
* Author: Tengxiao Fan
* This program aims at testing the output functions for classes Point, Line, Circle, using friend keyword.
*/
#include "Line.hpp"
#include "Circle.hpp"
#include "Point.hpp"
#include <iostream>

int main()
{
	Point pt(1, 2);
	Line line(pt, pt + Point(1, 1));
	Circle circle(pt, 1);
	std::cout << "The point is: " << pt<<std::endl;//Test the point output
	std::cout << "The line is: " << line << std::endl;//Test the line output
	std::cout << "The circle is: " << circle << std::endl;//Test the circle output
	return 0;
}