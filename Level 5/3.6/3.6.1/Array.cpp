/*Array.cpp
* This is the source file for class Array.
* This class defines array of class Point that dynamically allocates memory.
*/
#include "Array.hpp"

Array::Array()//Default constructor
{
	m_data = new Point[10];
	m_size = 10;
}

Array::Array(int size)//constructor with size
{
	m_data = new Point[size];
	m_size = size;
}

Array::Array(const Array& source)//Copy constructor
{
	m_size = source.m_size;//Copy the size
	m_data = new Point[m_size];
	for (int i = 0;i < m_size;i++)//Copy the elements
	{
		m_data[i] = source[i];
	}
}

Array::~Array()//Default destructor
{
	delete[] m_data;
}

const Array& Array::operator = (const Array& source)//Assignment Operator
{
	if (this == &source)//prevent self-assignment
		return *this;
	delete[] m_data;
	m_size = source.m_size;//Copy the size
	m_data = new Point[m_size];
	for (int i = 0;i < m_size;i++)//Copy the elements
	{
		m_data[i] = source[i];
	}
	return *this;
}

int Array::Size() const//return the size
{
	return m_size;
}

void Array::SetElement(int index, const Point& pt)//set the element of the array
{
	if (index < m_size && index >= 0)
	{
		m_data[index] = pt;//Set the point
	}
	else//If out of bound, throw error
	{
		throw -1;
	}
}

const Point& Array::GetElement(int index) const//Get the element of an index
{
	if (index < m_size && index >= 0)
	{
		return m_data[index];
	}
	else//If out of bound, throw error
	{
		throw -1;
	}
}

Point& Array::operator [] (int index)//Square Bracket Operator for read and write
{
	if (index < m_size && index >= 0)
	{
		return m_data[index];
	}
	else//If out of bound, throw error
	{
		throw -1;
	}
}

const Point& Array::operator [] (int index) const//Square Bracket Operator for read only
{
	if (index < m_size && index >= 0)
	{
		return m_data[index];
	}
	else//If out of bound, throw error
	{
		throw -1;
	}              
}