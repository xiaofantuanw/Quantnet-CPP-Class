/* Test.cpp
* Author: Tengxiao Fan
* This program aims at testing the explicit and implicit constructor.
*/
#include "Point.hpp"
#include <iostream>

int main()
{
	Point p(1.0, 1.0);
	//if (p == 1.0)
	//	std::cout << "Equal!" << std::endl;
	//else
	//	std::cout << "Not equal" << std::endl;
	
	//The above program will return "Equal!" in the output, if the constructor is not explicit.
	//Because when calling the operator ==, The RHS will be constructed to a Point(1.0,1.0) implicitly
	// and automatically. So the two points are equal.
	if (p == (Point)1.0)
	{
		std::cout<< "Equal!" << std::endl;
	}
	else
	{
		std::cout << "Not equal" << std::endl;
	}


	return 0;
}