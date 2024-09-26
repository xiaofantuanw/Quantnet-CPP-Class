/*Functor_Predicate.hpp
* Author: Tengxiao Fan
* This file declares a template which is a function object to judge whether a number is less than a threshold
*/
#ifndef Functor_Predicate_HPP
#define Functor_Predicate_HPP

template <typename T>
class Functor_Predicate
{
private:
	//Private, data members
	T m_threshold;//a threshold that requires to be compared, of type T
public:
	Functor_Predicate();//Default constructor
	Functor_Predicate(T threshold);//Constructor with threshold
	Functor_Predicate(const Functor_Predicate& source);//Copy constructor
	~Functor_Predicate();//Destructor
	bool operator () (T num);//An operator function that compares the number entered to the threshold
};

#ifndef Functor_Predicate_CPP
#include "Functor_Predicate.cpp"
#endif // !Functor_Predicate_CPP



#endif // !Functor_Predicate_HPP
