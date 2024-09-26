/* Test.cpp
* Author: Tengxiao Fan
* This program tests the bounds checking of the array, using exception objects
*/
#include "Point.hpp"
#include "Array.hpp"
#include "ArrayException.hpp"
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
	//catch (int err)//For integer thrown, these code may be included if there is an integer throw.
	//{
	//	if (err == -1)
	//		std::cout << "Index out of bound." << std::endl;//Index out of bound error
	//}
	catch (ArrayException& exception)//For object thrown
	{
		std::cout << exception.GetMessage() << std::endl;//Use GetMessage Function to output the message
	}
	catch (...)
	{
		std::cout << "Other errors" << std::endl;//unexpected errors
	}
	return 0;
}