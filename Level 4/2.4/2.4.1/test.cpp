#include "Line.hpp"
#include "Circle.hpp"
#include "Point.hpp"
#include <iostream>

int main()
{
	double ptx, pty, factor;
	std::cout << "Please input the x-coordinate of the start point." << std::endl;
	std::cin >> ptx;//Input of x-coordinate of the point
	std::cout << "Please input the y-coordinate of the start point." << std::endl;
	std::cin >> pty;//Input of y-coordinate of the point
	std::cout << "Please input a factor." << std::endl;
	std::cin >> factor;//Input of a factor that times the point
	Point pt(ptx, pty);//Initialize the point

	std::cout << "Negative of the point: " << (-pt).ToString() << std::endl;//Test the negative operator
	std::cout << "The point times the factor: " << (pt * factor).ToString() << std::endl;//Test the time operator
	std::cout << "The point adds (1,1): " << (pt + Point(1, 1)).ToString() << std::endl;//Test of plus operator
	
	Point pt2;//Another point
	pt2 = pt;//Test the assignment operator
	std::cout << "Another point is assigned with the value of the point: " << pt2.ToString()<<". ";
	if (pt2 == pt)
	{
		std::cout << "The points are equal." << std::endl;
	}
	else
	{
		std::cout << "The points are not equal." << std::endl;
	}//Test the compare operator
	pt2 *= factor;//Test the scale&assign operator
	std::cout << "Then change the value of the point by scaling: " << pt2.ToString() << ". ";
	if (pt2 == pt)
	{
		std::cout << "Now, the points are still equal." << std::endl;
	}
	else
	{
		std::cout << "Now, the points are not equal." << std::endl;
	}//Test the compare operator

	Line line1(pt,pt2), line2;
	line2 = line1;//Test the assignment operator of lines.
	std::cout << "Test the assignment of lines: " << line2.ToString() << std::endl;

	Circle circle1(pt, factor), circle2;
	circle2 = circle1;//Test the assignment operator of circles.
	std::cout << "Test the assignment of circles: " << circle2.ToString() << std::endl;

	return 0;
}