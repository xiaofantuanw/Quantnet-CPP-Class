/*Array.cpp
* This is the source file for class Array.
* This class defines array of class Point that dynamically allocates memory.
*/
//ACCESS1: This program uses Full class name including namespace for the Point used in the Array class to access
#include "Array.hpp"

namespace Tengxiao//Wrap the definitions of member functions in namespace
{
	namespace Containers {
		Array::Array()//Default constructor
		{
			m_data = new CAD::Point[10];
			m_size = 10;
		}

		Array::Array(int size)//constructor with size
		{
			m_data = new CAD::Point[size];
			m_size = size;
		}

		Array::Array(const Array& source)//Copy constructor
		{
			m_size = source.m_size;//Copy the size
			m_data = new CAD::Point[m_size];
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
			m_data = new CAD::Point[m_size];
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

		void Array::SetElement(int index, const CAD::Point& pt)//set the element of the array
		{
			if (index < m_size && index >= 0)//If out of bound, do nothing.
			{
				m_data[index] = pt;//Set the point
			}
		}

		const CAD::Point& Array::GetElement(int index) const//Get the element of an index
		{
			if (index < m_size && index >= 0)
			{
				return m_data[index];
			}
			else//If out of bound, return the first element.
			{
				return m_data[0];
			}
		}

		CAD::Point& Array::operator [] (int index)//Square Bracket Operator for read and write
		{
			if (index < m_size && index >= 0)
			{
				return m_data[index];
			}
			else//If out of bound, return the first element.
			{
				return m_data[0];
			}
		}

		const CAD::Point& Array::operator [] (int index) const//Square Bracket Operator for read only
		{
			if (index < m_size && index >= 0)
			{
				return m_data[index];
			}
			else//If out of bound, return the first element.
			{
				return m_data[0];
			}
		}
	}
}