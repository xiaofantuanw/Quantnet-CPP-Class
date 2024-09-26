/*Circle.cpp
* Author: Tengxiao Fan
* Definition of member function of the class circle
*/


#define _USE_MATH_DEFINES
#include "Circle.hpp"
#include <sstream>
#include <iostream>
#include <cmath>




Circle::Circle()//Default constructor
{
	centerpoint = Point(0, 0);//Default centerpoint
	m_radius = 1;//Default radius
}

Circle::Circle(const Circle& source)//Copy constructor
{
	centerpoint = source.Centrepoint();//Copy the centerpoint
	m_radius = source.Radius();//copy the radius
}

Circle::Circle(const Point& centerpt, const double rad)//Initialized constructor
{
	centerpoint = centerpt;//intialize the centerpoint
	m_radius = rad;//initialize the radius
}

Circle::~Circle()//Default destructor
{

}

Point Circle::Centrepoint() const//Get the centerpoint of the circle
{
	return centerpoint;
}

double Circle::Radius() const//Get the radius of the circle
{
	return m_radius;
}

void Circle::Centrepoint(const Point& centerpt)//Set the centerpoint of the circle
{
	centerpoint = centerpt;
}

void Circle::Radius(const double rad)//Set the radius of the circle
{
	m_radius = rad;
}

double Circle::Diameter() const//Calculate the diameter of the circle
{
	return 2 * m_radius;//Diameter equals to 2*radius
}

double Circle::Circumference() const//Calculate the circumference of the circle
{
	return 2 * M_PI * m_radius;//Circumference=2*pi*r
}

double Circle::Area() const//Calculate the area of the circle
{
	return M_PI * pow(m_radius, 2);//Area=pi*r^2
}

std::string Circle::ToString() const//string description of the circle
{
	std::stringstream stream;//Use a stringstream to make the string
	std::string result;
	stream << "Circle: Center: (" << centerpoint.X() << ", " << centerpoint.Y() << "); Radius:" << m_radius;//Make the stream
	result = stream.str();//Turn to string
	return result;
}