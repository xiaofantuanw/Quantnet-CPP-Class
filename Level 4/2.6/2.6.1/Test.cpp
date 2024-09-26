/* Test.cpp
* Author: Tengxiao Fan
* This program tests different ways to get into a namespace
*/

#include "Point.hpp"
#include "Circle.hpp"
#include "Line.hpp"
#include "Array.hpp"//ACCESS1: Full class name including namespace for the Point used in the Array class
#include <iostream>

int main()
{
	Tengxiao::CAD::Point pt1(1, 1);//ACCESS2: the full namespace for Point class.
	std::cout << "The point is :" << pt1 << std::endl;

	using Tengxiao::CAD::Line;//ACCESS3: using declaration for using a single class (Line).
	Line line1(pt1, Tengxiao::CAD::Point(0, 0));
	std::cout << "The line is: " << line1 << std::endl;

	using namespace Tengxiao::Containers;//ACCESS4: using declaration for a complete namespace (Containers).
	Array ptarray(10);
	for (int index = 0;index < 10;index++)
	{
		ptarray.SetElement(index, Tengxiao::CAD::Point(index, index));//Set Elements
	}
	std::cout << "The first element of the array is: " << ptarray[0] << std::endl;

	namespace TxCAD=Tengxiao::CAD;//ACCESS5: using the Circle class by creating a shorter alias for the YourName::CAD namespace.
	TxCAD::Circle circle1(pt1, 1);
	std::cout << "The circle is: " << circle1 << std::endl;
}