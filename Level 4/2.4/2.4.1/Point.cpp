/*Point.cpp
* Author: Tengxiao Fan
* Definition of member function
* This program modifies Distance function and Get/Set function and uses overload
*/

#include "Point.hpp"
#include <sstream>
#include <iostream>
#include <cmath>

Point::Point()//Default constructor
{
	m_x = m_y = 0;
	//std::cout << "Constructor +1" << std::endl;
}

Point::Point(const Point& source)//Copy constructor
{
	m_x = source.m_x;
	m_y = source.m_y;
	//std::cout << "Copy Constructor +1" << std::endl;
}

Point::Point(const double initxvalue, const double inityvalue)//Constructor with initialization
{
	m_x = initxvalue;
	m_y = inityvalue;
	//std::cout << "Initialized Constructor +1" << std::endl;
}

Point::~Point()//Default destructor
{
	//std::cout << "Destructor +1" << std::endl;
}

double Point::X() const//Get the value of x, return m_x
{
	return m_x;
}

double Point::Y() const//Get the value of y, return m_y
{
	return m_y;
}

void Point::X(const double newxvalue)//Set a new value for x
{
	m_x = newxvalue;
}

void Point::Y(const double newyvalue)//Set a new value for y
{
	m_y = newyvalue;
}

std::string Point::ToString() const//Output is the string description of the point
{
	std::stringstream stream;//Use a stringstream to make the string
	std::string result;
	stream << "Point(" << m_x << ", " << m_y << ")";
	result = stream.str();
	return result;
}

double Point::Distance() const//Output the distance of the point to origin(0,0)
{
	double distance = std::sqrt(m_x * m_x + m_y * m_y);//distance func
	return distance;
}

double Point::Distance(const Point& p) const//Output the distance of the point to point P.
{
	double xp, yp;
	xp = p.m_x;//Cannot use GetX() because of the const.
	yp = p.m_y;
	//The following line will cause compile error
	//p.m_x=3;
	double distance = std::sqrt((m_x - xp) * (m_x - xp) + (m_y - yp) * (m_y - yp));//distance function
	return distance;
}

Point Point::operator-() const// Negate the coordinates.
{
	return Point(-m_x, -m_y);//Return negative coordinates.
}

Point Point::operator* (double factor) const// Scale the coordinates.
{
	return Point(factor * m_x, factor * m_y);//return factor times the coordinates
}

Point Point::operator+ (const Point& p) const// Add coordinates.
{
	return Point(m_x + p.m_x, m_y + p.m_y);//return the coordinates added respectively
}

bool Point::operator == (const Point& p) const // Equally compare operator.
{
	if (m_x == p.m_x && m_y == p.m_y)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

const Point& Point::operator = (const Point& source) // Assignment operator.
{
	if (this == &source)//preclude self-assignment
	{
		return *this;
	}
	m_x = source.m_x;//copy the coordinate
	m_y = source.m_y;
	return *this;
}

const Point& Point::operator *= (double factor) // Scale the coordinates & assign.
{
	m_x *= factor;//times the factor
	m_y *= factor;
	return *this;
}