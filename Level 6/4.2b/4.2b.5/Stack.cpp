/*Array.cpp
* This is the source file for template Stack.
* This class defines array of a class that dynamically allocates me
*/

#ifndef Stack_CPP
#define Stack_CPP
#include "Stack.hpp"
#include "ArrayException.hpp"
#include "StackException.hpp"
#include <iostream>

template <typename T>
Stack<T>::Stack()//Default constructor
{
	m_current = 0;//current index is zero
	m_array = Array<T>::Array();//Default array constructor
}

template <typename T>
Stack<T>::Stack(int size)//constructor with size
{
	m_current = 0;//current index is zero
	m_array = Array<T>::Array(size);//array constructor with size
}

template <typename T>
Stack<T>::Stack(const Stack<T>& source)//Copy constructor
{
	m_current = source.m_current;//current index is the same as that of the source
	m_array = Array<T>::Array(source.m_array);//use the copy constructor
	//for (int index = 0;index < source.m_array.Size();index++)
	//{
	//	m_array.SetElement(index, source.m_array.GetElement(index));//Copy the elements of the array
	//}
}

template <typename T>
Stack<T>::~Stack()//Destructor
{

}

template <typename T>
const Stack<T>& Stack<T>::operator= (const Stack<T>& source)
{
	if (this == &source)//prevent self-assignment
		return *this;
	m_current = source.m_current;
	m_array = source.m_array;//Use copy constructor of the array
	return *this;
}

template <typename T>
void Stack<T>::Push(T& element)//Push function
{
	try
	{
		m_array.SetElement(m_current, element);//Set the element of the current index
		m_current++;//Change the current index of the stack. If unsuccessful, it will not change.
	}
	catch (ArrayException& exception)//For object thrown
	{
		throw StackFullException();//Throw the exception to outer function.
	}
}

template <typename T>
const T Stack<T>::Pop()//Pop function
{
	T result;
	try
	{
		result = m_array[m_current - 1];//Get the element
		m_current--;//Change the current index
	}
	catch (ArrayException& exception)//For object thrown
	{
		m_current = 0;
		throw StackEmptyException();//Throw the exception to outer.
	}
	return result;
}

#endif