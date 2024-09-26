/*Test.cpp
* Author:Tengxiao Fan
* The program tests the colon syntax, and see how many constructors, destructors and assignments are called.
*/
#include "Circle.hpp"
#include "Line.hpp"
#include "Point.hpp"
#include <iostream>

int main()
{
	Line l;
	return 0;
	//If we do not use Colon Syntax. There will be (for class Point):
	//4 constructors (2 default, 2 initialized); 4 destructors and 2 assignment calls.

	//If we use Colon Syntax for class Line. There will be (for class Point):
	//2 initialized constructors and 2 destructors. 0 assignment calls.
	//std::cout << l << std::endl;//If you want to output something
}