/*test.cpp
* author:Tengxiao Fan
* This test function tests the Template Method Pattern
*/

#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Shape.hpp"
#include <iostream>

int main()
{
	Shape* sp[3];//Give different derived types for different elements in the array.
	sp[0] = new Point(3,4);
	sp[1] = new Line;
	sp[2] = new Circle;
	//sp[0] = new Shape;
	//It is not possible to create an instance of the Shape class(ABC)
	for (int index = 0;index < 3;index++)
	{
		sp[index]->Print();//print function using Template Method Pattern
	}//It is printing the right information when point and line do not have the Print() function.
	for (int index = 0;index < 3;index++)
	{
		delete sp[index];//destructors
	}
	return 0;
	//If not using virtual in Shape class, only Shape Destructors are called.
	//If using virtual in Shape class, proper destructors are called.
}