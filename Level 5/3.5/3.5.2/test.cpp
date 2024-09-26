/*test.cpp
* author:Tengxiao Fan
* This test function tests the Polymorphic ToString() Function.
* The ToString() in derived class uses the ToString() in base class
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
		std::cout << sp[index]->ToString() << std::endl;//Test the ToString function of different types
		//Now ID is printed
	}
	for (int index = 0;index < 4;index++)
	{
		delete sp[index];//free the memory
	}
	return 0;
}