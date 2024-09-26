/* Test.cpp
* Author: Tengxiao Fan
* This program creates array of Point pointers and test them.
*/
#include "Point.hpp"
#include <iostream>

int main()
{
	Point** ptpointers;
	ptpointers = new Point*[3];//An array of Point pointers
	for (int i = 0;i < 3;i++)
	{
		ptpointers[i] = new Point(i, i);//Create for each element in the array a point on the heap.
	}
	for (int i = 0;i < 3;i++)//Iterate the array and print each point in the array.
	{
		std::cout << "Point " << i + 1 << ": " << (*ptpointers[i]) << std::endl;
	}
	for (int i = 0;i < 3;i++)//Iterate the array again and delete each point in the array.
	{
		delete ptpointers[i];
	}
	delete[] ptpointers;//Delete the array itself.
}