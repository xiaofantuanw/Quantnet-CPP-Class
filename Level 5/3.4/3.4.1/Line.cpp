/*Line.cpp
* Author: Tengxiao Fan
* Definition of member function in Line class
* This file should be used with the point class
*/

#include "Line.hpp"
#include <sstream>
#include <iostream>
#include <cmath>

Line::Line():startpoint(0,0), endpoint(0,0)//Default constructor using colon syntax
{
	//startpoint = Point(0, 0);//Set the start point to be (0,0)
	//endpoint = Point(0, 0);//Set the end point to be (0,0)
}

Line::Line(const Point& startpt, const Point& endpt):startpoint(startpt),endpoint(endpt)
//Initialize with value, using colon syntax
{
	//startpoint = startpt;//Initialize with the value
	//endpoint = endpt;
}

Line::Line(const Line& source) :startpoint(source.startpoint), endpoint(source.endpoint)
//Copy constructor,using colon syntax
{
	//startpoint = source.startpoint;//Copy the startpoint
	//endpoint = source.endpoint;//Copy the endpoint
}

Line::~Line()//Destructor
{

}

const Point& Line::P1() const//Getter function for startpoint
{
	return startpoint;
}

const Point& Line::P2() const//Getter function for endpoint
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
	stream << "Line: (" << startpoint.X() << ", " << startpoint.Y() << ") to (" << endpoint.X() << ", " << endpoint.Y() << ")";//Make the stream
	result = stream.str();//Turn to string
	return result;
}

double Line::Length() const//Length function
{
	return startpoint.Distance(endpoint);
}

const Line& Line::operator = (const Line& source)//Assignment operator
{
	if (this == &source)//preclude self-assignment
	{
		return *this;
	}
	startpoint = source.startpoint;
	endpoint = source.endpoint;
	return *this;
}

std::ostream& operator << (std::ostream& os, const Line& line) // Send to ostream.
{
	os << line.ToString();//Use ToString to send information to the ostream
	return os;
}
