/*MyVisitor.hpp
* Author: Tengxiao Fan
* This is the header file of a visitor class MyVisitor. This visitor moves the coordinates of the object
*/
#ifndef MyVisitor_HPP
#define MyVisitor_HPP

#include "boost/variant.hpp"//Include the boost::variant
#include "Point.hpp"
#include "Circle.hpp"
#include "Line.hpp"
#include "Shape.hpp"

class MyVisitor :boost::static_visitor<void>
{
private://data members
	double m_dx;//x offset
	double m_dy;//y offset
public://Member functions
	//Constructors and destructors
	MyVisitor();//Default Constructor
	MyVisitor(double dx, double dy);//Constructor with offset coordinates
	MyVisitor(const MyVisitor& source);//Copy constructor
	virtual ~MyVisitor();//Destructor

	//operator()
	void operator() (Point& p) const;//For class Point
	void operator() (Line& l) const;//For class Line
	void operator() (Circle& c) const;//For class Circle
};

#endif