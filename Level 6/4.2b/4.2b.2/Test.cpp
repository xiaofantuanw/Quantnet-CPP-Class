/* Test.cpp
* Author: Tengxiao Fan
* This program tests the generic class NumericArray.
*/
#include "Point.hpp"
#include "Array.hpp"
#include "NumericArray.hpp"
#include "ArrayException.hpp"
#include <iostream>

int main()
{
	NumericArray<int> intArray1;//Three numeric arrays
	NumericArray<int> intArray2;
	NumericArray<int> intArray3(15);
	int factor = 5;
	for (int index = 0;index < 10;index++)//Initialize
	{
		intArray1.SetElement(index, index);
		intArray2.SetElement(index, index * 2);
	}
	for (int index = 0;index < 15;index++)//Initialize
	{
		intArray3.SetElement(index, index * 3);
	}
	std::cout << "The last element of sum of array 1 and 2: " << (intArray1 + intArray2)[9] << std::endl;
	//Test the add operator
	intArray1 = intArray2;//Test the assignment operator
	std::cout << "The last element of scaling array 1 with factor: " << (intArray1 * factor)[9] << std::endl;
	//Test the multiply operator
	std::cout << "The dot product of array 1 and 2: " << intArray1.DotProduct(intArray2) << std::endl;
	//Test the dot product 
	try
	{
		NumericArray<int> temp = intArray1 + intArray3;//Try the invalid add of two arrays not the same size
	}
	catch (const ArrayException& exception)
	{
		std::cout << exception.GetMessage() << std::endl;//Use GetMessage Function to output the message
	}
	//NumericArray<Point> PointArray1(10);
	//This line can compile, but we cannot do some of the operators for numeric arrays.
	//Assumptions of type used as template argument: numeric types.
	return 0;
}