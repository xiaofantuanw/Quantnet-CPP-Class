#include "Line.hpp"
#include "Point.hpp"
#include <iostream>

int main()
{
	double pt1x, pt1y, pt2x, pt2y;
	std::cout << "Please input the x-coordinate of the start point." << std::endl;
	std::cin >> pt1x;//Input of x-coordinate start point
	std::cout << "Please input the y-coordinate of the start point." << std::endl;
	std::cin >> pt1y;//Input of y-coordinate start point
	std::cout << "Please input the x-coordinate of the end point." << std::endl;
	std::cin >> pt2x;//Input of x-coordinate end point
	std::cout << "Please input the y-coordinate of the end point." << std::endl;
	std::cin >> pt2y;//Input of y-coordinate end point
	Point pt1(pt1x, pt1y), pt2(pt2x, pt2y);//Initialize the points
	Line line1(pt1, pt2);//Initialize the line
	std::cout << "Description: " << line1.ToString()<<std::endl;//Output the description
	std::cout << "Length: " << line1.Length()<<std::endl;//Output the length
	return 0;
}