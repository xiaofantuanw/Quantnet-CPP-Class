/* Test.cpp
* Author: Tengxiao Fan
* This program uses dynamical storage to test the class Point.
*/
#include "Point.hpp"
#include <iostream>

int main()
{
	Point* pt1;
	Point* pt2;
	Point* pt3;
	pt1 = new Point;//Dynamically Creating Objects by default constructor
	pt2 = new Point(1, 1);//Dynamically Creating Objects by constructor with coordinates
	pt3 = new Point(*pt2);//Dynamically Creating Objects by copy construtor
	std::cout << "Point 1: " << (*pt1) << std::endl;//Test the << operator.
	std::cout << "Point 2: " << (*pt2) << std::endl;//If we do not pass the dereference, it will output rubbish.
	std::cout << "Point 3: " << (*pt3) << std::endl;
	std::cout << "Distance between Point 1 and 2: " << pt1->Distance(*pt2) << std::endl;//Test the distance function
	delete pt1;//free the memory
	delete pt2;
	delete pt3;
	int size;//The length of the Point array.
	std::cout << "Please input the size of the array" << std::endl;
	std::cin >> size;
	//Point pts[size];//This will cause compile error
	pt1 = new Point[size];//Cannot use other constructors than the default constructor
	std::cout << "The last point in the array: " << pt1[size-1] << std::endl;
	delete[] pt1;
	return 0;
}