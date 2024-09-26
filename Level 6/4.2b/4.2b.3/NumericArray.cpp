/* NumericArray.cpp
* Author: Tengxiao Fan
* This is a source file for the generic class NumericArray
* This class is an Array for numerical types such as double and int.
 */
#ifndef NumericArray_CPP
#define NumericArray_CPP

#include "NumericArray.hpp"

template <typename T>
NumericArray<T>::NumericArray():Array<T>()//Default Constructor
{

}

template <typename T>
NumericArray<T>::NumericArray(int size):Array<T>(size)//Constructor with size
{

}

template <typename T>
NumericArray<T>::NumericArray(const NumericArray<T>& source):Array<T>(source)//Copy constructor
{

}

template <typename T>
NumericArray<T>::~NumericArray()//Destructor
{
	
}

template <typename T>
const NumericArray<T>& NumericArray<T>::operator= (const NumericArray<T>& source)//Assignment operator
{
	if (this == &source)//prevent self-assignment
		return *this;
	Array<T>::operator= (source);
	return *this;
}

template <typename T>
NumericArray<T> NumericArray<T>::operator+ (const NumericArray<T>& arr) const//Add Operator
{
	if (Array<T>::Size() != arr.Size())
		throw IndexNotMatchException(Array<T>::Size(), arr.Size());//The exception for index not match
	NumericArray<T> result(Array<T>::Size());
	for (int index = 0;index < Array<T>::Size();index++)
	{
		result.SetElement(index, Array<T>::GetElement(index) + arr.GetElement(index));//add the elements
	}
	return result;
}

template <typename T>
NumericArray<T> NumericArray<T>::operator* (T factor) const//Multiply Operator
{
	NumericArray<T> result(Array<T>::Size());
	for (int index = 0;index < Array<T>::Size();index++)
	{
		result.SetElement(index, Array<T>::GetElement(index)*factor );//scale the elements
	}
	return result;
}

template <typename T>
T NumericArray<T>::DotProduct(const NumericArray<T>& arr) const//Dot product
{
	if (Array<T>::Size() != arr.Size())
		throw IndexNotMatchException(Array<T>::Size(), arr.Size());//The exception for index not match
	T result = 0;
	for (int index = 0;index < Array<T>::Size();index++)
	{
		result += (Array<T>::GetElement(index) * arr.GetElement(index));
	}
	return result;
}

#endif