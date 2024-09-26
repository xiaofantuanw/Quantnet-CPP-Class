/*Functor_Predicate.hpp
* Author: Tengxiao Fan
* This file is the source of a template which is a function object to judge whether a number is less than a threshold
*/

#ifndef Functor_Predicate_CPP
#define Functor_Predicate_CPP
#include "Functor_Predicate.hpp"

template <typename T>
bool Functor_Predicate<T>::operator () (T num)
//An operator function that compares the number entered to the threshold
{
	return (num < m_threshold);//Compare with threshold
}

template<typename T>
Functor_Predicate<T>::Functor_Predicate()//Default constructor
{
	m_threshold = 0;//Default threshold is zero
}

template<typename T>
Functor_Predicate<T>::Functor_Predicate(T threshold)//constructor with threshold
{
	m_threshold = threshold;
}

template<typename T>
Functor_Predicate<T>::Functor_Predicate(const Functor_Predicate& source)//copy constructor
{
	m_threshold = source.m_threshold;
}

template<typename T>
Functor_Predicate<T>::~Functor_Predicate()//Destructor
{

}

#endif