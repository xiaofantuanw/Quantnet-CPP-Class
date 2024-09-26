/* PointArray.hpp
* Author: Tengxiao Fan
* This is a header file for the generic class PointArray
* This class is an Array for Point type.
 */
#ifndef PointArray_HPP
#define PointArray_HPP
#include "Array.hpp"
#include "Point.hpp"

class PointArray :public Array<Point>
//Class PointArray, derived from Array<Point>.
{
public:
	//Member functions, accessible to users
	// 
	//Constructors and destructors
	PointArray();//Default constructor
	PointArray(int size);//Constructor with size
	PointArray(const PointArray& source);//Copy constructor
	virtual ~PointArray();//Destructor

	//Assignment Operator
	const PointArray& operator= (const PointArray& source);

	//Length function
	double Length() const;//Return the total length between the points in the array
};



#endif // !PointArray_HPP

