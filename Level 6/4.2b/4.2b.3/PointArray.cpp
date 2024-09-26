/* PointArray.hpp
* Author: Tengxiao Fan
* This is a source file for the generic class PointArray
* This class is an Array for Point type.
 */

#include "PointArray.hpp"

PointArray::PointArray():Array<Point>()//Default constructor
{

}

PointArray::PointArray(int size) :Array<Point>(size)//Constructor with size
{

}

PointArray::PointArray(const PointArray& source):Array<Point>(source)//Copy Constructor
{

}

PointArray::~PointArray()//Default destructor
{

}

const PointArray& PointArray::operator= (const PointArray& source)//Assignment operator
{
	if (this == &source)//prevent self-assignment
		return *this;
	Array<Point>::operator=(source);
	return *this;
}

double PointArray::Length() const//Return the total length between the points in the array
{
	if (Size() <= 1)//If there are less than 2 points, there is not a line.
		return 0;
	double result = 0;
	for (int index = 0;index < Size()-1;index++)
	{
		result += GetElement(index).Distance(GetElement(index + 1));//Add the length to the next point
	}
	return result;
}
