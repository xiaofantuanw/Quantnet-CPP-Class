/* main.cpp
* Author: Tengxiao Fan
* Define a class of point and use the class. 
* A test that shows how many constructors and destructors are called when default constructors are used
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
	Point point1;//Initialize the point, constructor +1
	point1.SetX(x);//Set x and y coordinate value
	point1.SetY(y);
	double xp, yp;
	std::cout << "Please input the x-coordinate of point P." << std::endl;
	std::cin >> xp;//Input of x-coordinate of P
	std::cout << "Please input the y-coordinate of point P." << std::endl;
	std::cin >> yp;//Input of y-coordinate of P
	Point pointp; //Constructor +1.
	pointp.SetX(xp);//Set x and y coordinate value for point P.
	pointp.SetY(yp);
	std::cout << "The distance between the point and point P is: " << point1.Distance(pointp) << std::endl;//Output the distance to P.
	//Copy constructor for free without creating
	//Result: 2 constructors, 3 destructors, not the same.
	return 0;
}