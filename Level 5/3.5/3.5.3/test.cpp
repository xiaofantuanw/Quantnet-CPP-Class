/*test.cpp
* author:Tengxiao Fan
* This test function tests the virtual destructors
*/

#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Shape.hpp"
#include <iostream>

int main()
{
	Shape* sp[4];//Give different derived types for different elements in the array.
	sp[0] = new Shape;
	sp[1] = new Point(3,4);
	sp[2] = new Line;
	sp[3] = new Circle;
	
	for (int index = 0;index < 4;index++)
	{
		delete sp[index];//destructors
	}
	return 0;
	//If not using virtual in Shape class, only Shape Destructors are called.
	//If using virtual in Shape class, proper destructors are called.
}