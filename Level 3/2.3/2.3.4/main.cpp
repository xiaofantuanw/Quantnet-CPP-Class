/* main.cpp
* Author: Tengxiao Fan
* Define a class of point and use the class. 
* This program modifies the class and make some functions const functions
*/

#include "Point.hpp"
#include <iostream>

int main()
{
	const Point cp(1.5, 3.9);
	//The following line will cause compile error.
	//cp.X(0.3);
	// The following line will also cause compile error if X() is not a const function
	//std::cout << cp.X() << std::endl;
	std::cout << cp.X() << std::endl;//Test the const get function
	std::cout << "String Description: " << cp.ToString() << std::endl;//Test the const ToString function
	std::cout << "Distance to origin: " << cp.Distance() << std::endl;//Test the const Distance function
	const Point cp2(1, 1);
	std::cout << "Distance to (1,1): " << cp.Distance(cp2) << std::endl;//Test the const Distance function
	return 0;
}