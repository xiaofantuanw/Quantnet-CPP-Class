/* Test.cpp
* Author: Tengxiao Fan
* This program tests the class PointArray.
*/
#include "Point.hpp"
#include "Array.hpp"
#include "NumericArray.hpp"
#include "PointArray.hpp"
#include "ArrayException.hpp"
#include <iostream>

int main()
{
	int size;
	std::cout << "Please enter the size of the point array." << std::endl;
	std::cin >> size;//Get the size of the array.
	PointArray ptarr(size);
	for (int index = 0;index < size;index++)//Initialize
	{
		ptarr[index] = Point(index, index);
	}
	std::cout << "The length of the array is: " << ptarr.Length()<<std::endl;
	return 0;
}