/* Test.cpp
* Author: Tengxiao Fan
* This program creates array of Point pointers by class Array and test them.
*/
#include "Point.hpp"
#include "Array.hpp"
#include <iostream>

int main()
{
	int size;
	std::cout << "Please input the number of points in the array." << std::endl;
	std::cin >> size;

	Array ptarray(size);//Test the constructor with size.
	for (int index = 0;index < size;index++)
	{
		ptarray.SetElement(index, Point(index, index));//Test the SetElement function, set the elements with a point.
	}

	Array ptarray2(ptarray);//Copy the ptarray
	for (int index = 0;index < size;index++)
	{
		std::cout << "Point " << index << " got by GetElement: " << ptarray2.GetElement(index)<<std::endl;
		//Test the GetElement function.
		std::cout << "Point " << index << " got by SquareBracket: " << ptarray2[index] << std::endl;
		//Test the square bracket operator
	}//By the way, test the Copy function.

	Array ptarray3;
	ptarray3 = ptarray;//Test the operator =
	for (int index = 0;index < size;index++)
	{
		std::cout << "Now change Point " << index << std::endl;
		//Test the GetElement function.
		ptarray3[index] = Point(index * 2, index);//Test the square bracket operation to change the value
		std::cout << "Point " << index << " changed: " << ptarray3[index] << std::endl;
		//Test the square bracket operator
	}//By the way, test the operator =.

	return 0;
}