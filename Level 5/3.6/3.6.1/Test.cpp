/* Test.cpp
* Author: Tengxiao Fan
* This program tests the bounds checking of the array
*/
#include "Point.hpp"
#include "Array.hpp"
#include <iostream>

int main()
{
	Array ptarray(3);
	//ptarray.SetElement(3, Point(3, 4));//There will be a pop-up window showing debug error.
	try
	{
		ptarray.SetElement(2, Point(1, 2));
		ptarray.SetElement(3, Point(3, 4));//This will throw an error
	}
	catch (int err)
	{
		if (err == -1)
			std::cout << "Index out of bound." << std::endl;//Index out of bound error
	}
	catch (...)
	{
		std::cout << "Other errors" << std::endl;//unexpected errors
	}
	return 0;
}