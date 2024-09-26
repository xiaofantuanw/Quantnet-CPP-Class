/* main.cpp
* Author: Tengxiao Fan
* Define a class of point and use the class
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
	Point point1;//Initialize the point
	point1.SetX(x);//Set x and y coordinate value
	point1.SetY(y);
	std::cout << "The result of ToString() function: " << point1.ToString() << std::endl;//Output with Tostring func
	std::cout << "The result of GetX() and GetY() functions: Point(" << point1.GetX() << ", " << point1.GetY() << ")" << std::endl;
	//Output with get functions
}