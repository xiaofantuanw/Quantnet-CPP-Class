#include "Circle.hpp"
#include "Point.hpp"
#include <iostream>

int main()
{
	double centerptx, centerpty;
	double rad;
	std::cout << "Please input the x-coordinate of the center point." << std::endl;
	std::cin >> centerptx;//Input of x-coordinate center point
	std::cout << "Please input the y-coordinate of the center point." << std::endl;
	std::cin >> centerpty;//Input of y-coordinate center point
	std::cout << "Please input the radius of the circle." << std::endl;
	std::cin >> rad;//Input of x-coordinate end point
	
	Point centerpt(centerptx, centerpty);//Initialize the center points
	Circle circle1(centerpt, rad);//Initialize the circle
	std::cout << "Description: " << circle1.ToString()<<std::endl;//Output the description
	std::cout << "Diameter: " << circle1.Diameter() << std::endl;//Output the diameter
	std::cout << "Area: " << circle1.Area() << std::endl;//Output the area
	std::cout << "Circumference: " << circle1.Circumference() << std::endl;//Output the circumference
	return 0;
}