/* NumericArray.hpp
* Author: Tengxiao Fan
* This is a header file for the generic class NumericArray
* This class is an Array for numerical types such as double and int.
 
 */
#ifndef NumericArray_HPP
#define NumericArray_HPP
#include "Array.hpp"

template <typename T>
class NumericArray : public Array<T>
{
public:
	//Member functions, accessible to users
	// 
	//Constructors and destructors
	NumericArray();//Default Constructor
	NumericArray(int size);//Constructor with size
	NumericArray(const NumericArray<T>& source);//Copy constructor
	virtual ~NumericArray();//Destructor

	//Assignment operator
	const NumericArray<T>& operator= (const NumericArray<T>& source);

	//Operators
	NumericArray<T> operator+ (const NumericArray<T>& arr) const;//Add Operator
	NumericArray<T> operator* (T factor) const;//Multiply Operator, the factor should be the same type as the numbers in the array.
	T DotProduct(const NumericArray<T>& arr) const;//Dot product, return the number type T.

};

#ifndef NumericArray_CPP
#include "NumericArray.cpp"
#endif
#endif
