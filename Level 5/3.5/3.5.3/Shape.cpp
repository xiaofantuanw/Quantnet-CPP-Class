/*Shape.hpp
* Author: Tengxiao Fan
* Shape class is the superior hierarchy of Point, Line and Circle.
*/

#include "Shape.hpp"
#include <sstream>
#include <iostream>
#include <cmath>
#include <cstdlib>

Shape::Shape()//Default constructors
{
	m_id = rand();
}

Shape::Shape(const Shape& source):m_id(source.m_id)//Copy constructor,using colon
{
	
}

Shape::~Shape()//Destructor
{
	std::cout << "Shape Destructor." << std::endl;
}

const Shape& Shape::operator = (const Shape& source) // Assignment operator.
{
	if (this == &source)//preclude self-assignment
	{
		return *this;
	}
	m_id = source.m_id;
	return *this;
}

std::string Shape::ToString() const//Turn the ID to a string
{
	std::stringstream stream;//Use a stringstream to make the string
	std::string result;
	stream << "ID: " << m_id;
	result = stream.str();
	return result;
}

int Shape::ID() const//Get the id
{
	return m_id;
}



