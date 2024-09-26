/*Test.cpp
* Author:Tengxiao Fan
* The program tests the derived classes.
*/
#include "Circle.hpp"
#include "Line.hpp"
#include "Point.hpp"
#include <iostream>

int main()
{
	Shape s;// Create shape.
	Point p(10, 20);// Create point.
	Line l(Point(1, 2), Point(3, 4)); // Create line.
	std::cout << s.ToString() << std::endl;// Print shape.
	std::cout << p.ToString() << std::endl;// Print point.
	std::cout << l.ToString() << std::endl;// Print line
	std::cout << "Shape ID: " << s.ID() << std::endl; // ID of the shape.41
	std::cout << "Point ID: " << p.ID() << std::endl; // ID of the point. 18467 Does this work?Yes
	std::cout << "Line ID: " << l.ID() << std::endl; // ID of the line. 19169 Does this work?Yes
	Shape* sp; // Create pointer to a shape variable.
	sp = &p; // Point in a shape variable. Possible? Yes, A base class pointer can point to a derived object
	std::cout << sp->ToString() << std::endl;// What is printed? 18467, the id of the Point
	// Create and copy Point p to new point.
	Point p2;
	p2 = p;
	std::cout << p2 << ", " << p2.ID() << std::endl; // Is the ID copied if you do not call
	// the base class assignment in point? Yes, copied.
	return 0;
}