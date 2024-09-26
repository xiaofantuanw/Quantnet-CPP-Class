/* main.cpp
* Author: Tengxiao Fan
* Define a class of point and use the class. 
* This program modifies Distance function and Get/Set function and uses overload
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
	point1.X(x);//Test the overload set function
	point1.Y(y);
	std::cout << "The result of ToString() function: " << point1.ToString() << std::endl;//Output with Tostring func
	std::cout << "The result of X() and Y() functions: Point(" << point1.X() << ", " << point1.Y() << ")" << std::endl;
	//Output with get functions
	std::cout << "The distance between the point and origin is: " << point1.Distance() << std::endl;//Output the distance to origin
	double xp, yp;
	std::cout << "Please input the x-coordinate of point P." << std::endl;
	std::cin >> xp;//Input of x-coordinate of P
	std::cout << "Please input the y-coordinate of point P." << std::endl;
	std::cin >> yp;//Input of y-coordinate of P
	Point pointp(xp,yp); 
	std::cout << "The distance between the point and point P is: " << point1.Distance(pointp) << std::endl;//Output the distance to P.
	//Copy constructor for free without creating
	return 0;
}