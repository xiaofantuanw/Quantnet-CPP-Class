/*Array.cpp
* This is the source file for class Array.
* This class defines array of class that dynamically allocates memory.
*/
#ifndef ARRAY_CPP
#define ARRAY_CPP
#include "Array.hpp"
#include "ArrayException.hpp"
#include <iostream>

template <typename T>
Array<T>::Array()//Default constructor
{
	m_data = new T[m_DefaultSize];
	m_size = m_DefaultSize;
}

template <typename T>
Array<T>::Array(int size)//constructor with size
{
	m_data = new T[size];
	m_size = size;
}

template <typename T>
Array<T>::Array(const Array<T>& source)//Copy constructor
{
	m_size = source.m_size;//Copy the size
	m_data = new T[m_size];
	for (int i = 0;i < m_size;i++)//Copy the elements
	{
		m_data[i] = source[i];
	}
}

template <typename T>
Array<T>::~Array()//Default destructor
{
	delete[] m_data;
	//std::cout << "Deleted" << std::endl;
}

template <typename T>
const Array<T>& Array<T>::operator = (const Array<T>& source)//Assignment Operator
{
	if (this == &source)//prevent self-assignment
		return *this;
	delete[] m_data;
	m_size = source.m_size;//Copy the size
	m_data = new T[m_size];
	for (int i = 0;i < m_size;i++)//Copy the elements
	{
		m_data[i] = source[i];
	}
	return *this;
}

template <typename T>
int Array<T>::Size() const//return the size
{
	return m_size;
}

template <typename T>
void Array<T>::SetElement(int index, const T& pt)//set the element of the array
{
	if (index < m_size && index >= 0)
	{
		m_data[index] = pt;//Set the point
	}
	else//If out of bound, throw error
	{
		throw OutOfBoundsException(index);
	}
}

template <typename T>
const T& Array<T>::GetElement(int index) const//Get the element of an index
{
	if (index < m_size && index >= 0)
	{
		return m_data[index];
	}
	else//If out of bound, throw error
	{
		throw OutOfBoundsException(index);
	}
}

template <typename T>
T& Array<T>::operator [] (int index)//Square Bracket Operator for read and write
{
	if (index < m_size && index >= 0)
	{
		return m_data[index];
	}
	else//If out of bound, throw error
	{
		throw OutOfBoundsException(index);
	}
}

template <typename T>
const T& Array<T>::operator [] (int index) const//Square Bracket Operator for read only
{
	if (index < m_size && index >= 0)
	{
		return m_data[index];
	}
	else//If out of bound, throw error
	{
		throw OutOfBoundsException(index);
	}              
}

template <typename T>
int Array<T>::DefaultSize()
{
	return m_DefaultSize;
}

template <typename T>
void Array<T>::DefaultSize(int size)
{
	m_DefaultSize = size;
}

template <typename T>
int Array<T>::m_DefaultSize = 10;

#endif