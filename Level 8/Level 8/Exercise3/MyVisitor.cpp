/*MyVisitor.cpp
* Author: Tengxiao Fan
* This is the source file of a visitor class MyVisitor. This visitor moves the coordinates of the object
*/

#include "MyVisitor.hpp"

MyVisitor::MyVisitor():boost::static_visitor<void>(),m_dx(0),m_dy(0)
//Default constructor, set the offset to be 0
{

}

MyVisitor::MyVisitor(double dx, double dy) :boost::static_visitor<void>(), m_dx(dx), m_dy(dy)
//constructor with coordinates
{

}

MyVisitor::MyVisitor(const MyVisitor& source):boost::static_visitor<void>(source), m_dx(source.m_dx),m_dy(source.m_dy)
//Copy constructor
{

}

MyVisitor::~MyVisitor()
{

}

void MyVisitor::operator() (Point& p) const//For class Point
{
	p.X(p.X() + m_dx);
	p.Y(p.Y() + m_dy);//Change the coordinate of the shapes
}

void MyVisitor::operator() (Line& l) const//For class Line
{
	l.P1(Point(l.P1().X() + m_dx, l.P1().Y() + m_dy));
	l.P2(Point(l.P2().X() + m_dx, l.P2().Y() + m_dy));//Change the coordinates of the start and end points
}

void MyVisitor::operator() (Circle& c) const//For class Circle
{
	c.Centrepoint(Point(c.Centrepoint().X()+m_dx, c.Centrepoint().Y()+m_dy));//Change the coordinate of the center point
}