/*Point.cpp
* Author: Tengxiao Fan
* Definition of member function
*/

#include "Point.hpp"
#include <sstream>

Point::Point()//Default constructor
{
	m_x = m_y = 0;
}

Point::~Point()//Default destructor
{

}

double Point::GetX()//Get the value of x, return m_x
{
	return m_x;
}

double Point::GetY()//Get the value of y, return m_y
{
	return m_y;
}

void Point::SetX(double newxvalue)//Set a new value for x
{
	m_x = newxvalue;
}

void Point::SetY(double newyvalue)//Set a new value for y
{
	m_y = newyvalue;
}

std::string Point::ToString()//Output is the string description of the point
{
	std::stringstream stream;//Use a stringstream to make the string
	std::string result;
	stream << "Point(" << m_x << ", " << m_y << ")";
	result = stream.str();
	return result;
}
