/*Line.cpp
* Author: Tengxiao Fan
* Definition of member function in Line class
* This file should be used with the point class
*/

#include "Line.hpp"
#include <sstream>
#include <iostream>
#include <cmath>

Line::Line()//Default constructor
{
	startpoint = Point(0, 0);//Set the start point to be (0,0)
	endpoint = Point(0, 0);//Set the end point to be (0,0)
}

Line::Line(const Point& startpt, const Point& endpt)//Initialize with value
{
	startpoint = startpt;//Initialize with the value
	endpoint = endpt;
}

Line::Line(const Line& source)//Copy constructor
{
	startpoint = source.P1();//Copy the startpoint
	endpoint = source.P2();//Copy the endpoint
}

Line::~Line()//Destructor
{

}

Point Line::P1() const//Getter function for startpoint
{
	return startpoint;
}

Point Line::P2() const//Getter function for endpoint
{
	return endpoint;
}

void Line::P1(const Point& startpt)//Setter function for startpoint
{
	startpoint = startpt;
}

void Line::P2(const Point& endpt)//Setter function for endpoint
{
	endpoint = endpt;
}

std::string Line::ToString() const//Make a string that describe the Line
{
	std::stringstream stream;//Use a stringstream to make the string
	std::string result;
	stream << "Line: (" << startpoint.X() << ", " << startpoint.Y() << ") to ("<<endpoint.X()<<", "<<endpoint.Y()<<")";//Make the stream
	result = stream.str();//Turn to string
	return result;
}

double Line::Length() const
{
	return startpoint.Distance(endpoint);
}
