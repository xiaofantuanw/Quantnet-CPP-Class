/* main.cpp
* Author: Tengxiao Fan
* Define a class of point and use the class. 
* This program modifies the class and use inline functions for getters and setters
*/

#include "Point.hpp"
#include <iostream>

int main()
{
	double x, y;
	std::cout << "Please input the x-coordinate of the point." << std::endl;
	std::cin >> x;//Input of x-coordinate
	std::cout << "Please input the y-coordinate of the point." << std::endl;
	std::cin >> y;//Input of y-coordinate
	Point pt1(x,y);//Initialize the point
	std::cout << "x-coordinate: " << pt1.X() << std::endl;//Test the inline get function
	std::cout << "y-coordinate: " << pt1.Y() << std::endl;//Test the inline get function
	std::cout << "Please input the new x-coordinate of the point." << std::endl;
	std::cin >> x;//Input of new x-coordinate
	std::cout << "Please input the new y-coordinate of the point." << std::endl;
	std::cin >> y;//Input of new y-coordinate
	pt1.X(x);//Set the new coordinate
	pt1.Y(y);
	std::cout << "x-coordinate: " << pt1.X() << std::endl;//Test the inline get function
	std::cout << "y-coordinate: " << pt1.Y() << std::endl;//Test the inline get function
	return 0;
}