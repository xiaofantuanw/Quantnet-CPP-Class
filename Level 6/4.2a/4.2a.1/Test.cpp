/* Test.cpp
* Author: Tengxiao Fan
* This program builds an array of Point class using template Array and test it
*/
#include "Point.hpp"
#include "Array.hpp"
#include "ArrayException.hpp"
#include <iostream>

int main()
{
	int size;
	std::cout << "Please input the size of the Point array" << std::endl;
	std::cin >> size;
	Array<Point> points(size);
	for (int i = 0;i < size;i++)
	{
		points.SetElement(i, Point(i, i));
	}
	std::cout << "The last element of the array: " << points.GetElement(size - 1);
}