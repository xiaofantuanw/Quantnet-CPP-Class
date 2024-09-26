/*Point.hpp
* Author: Tengxiao Fan
* A class that defines a circle with a center point and radius.
*/

#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "Point.hpp"
#include "Shape.hpp"

class Circle:public Shape
{
private:
	//Datas, not accesible to users
	Point centerpoint;//Center point of the circle
	double m_radius;//radius of the circle
public:
	//Member functions, accessible to users
	// 
	//Constructors and destructors
	Circle(); //Default constructor
	Circle(const Circle& source);//Copy constructor
	Circle(const Point& centerpt, const double rad);//Initialized constructor
	virtual ~Circle();//Destructor
	//Getter functions
	const Point& Centrepoint() const;//return the centerpoint of the Circle
	double Radius() const;//return the radius of the Circle
	//Setter functions
	void Centrepoint(const Point& centerpt);//Set the centerpoint of the Circle
	void Radius(const double rad);//Set the radius of the Circle
	//Calculating functions
	double Diameter() const;//return the diameter of the Circle
	double Circumference() const;//return the circumference of the Circle
	double Area() const;//return the area of the circle
	//String description of the function
	std::string ToString() const;//Get the string description of the function
	//Assignment Operator
	const Circle& operator = (const Circle& source);
};
std::ostream& operator << (std::ostream& os, const Circle& circle); // Send to ostream.

#endif // !

