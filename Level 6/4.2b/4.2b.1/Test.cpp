/* Test.cpp
* Author: Tengxiao Fan
* This program tests the static default size.
*/
#include "Point.hpp"
#include "Array.hpp"
#include "ArrayException.hpp"
#include <iostream>

int main()
{
	Array<int> intArray1;
	Array<int> intArray2;
	Array<double> doubleArray;
	//The initial Default size is 10
	std::cout << intArray1.DefaultSize() << std::endl;//10
	std::cout << intArray2.DefaultSize() << std::endl;//10
	std::cout << doubleArray.DefaultSize() << std::endl;//10
	intArray1.DefaultSize(15);
	std::cout << intArray1.DefaultSize() << std::endl;//15
	std::cout << intArray2.DefaultSize() << std::endl;//15
	std::cout << doubleArray.DefaultSize() << std::endl;//10
	//This is because changing the m_DefaultSize of intArray1 only changes the static variable of Array<int>
	//The static variable of Array<double> remains unchanged.
	return 0;
}