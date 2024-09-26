/*Shape.hpp
* Author: Tengxiao Fan
* Shape class is the superior hierarchy of Point, Line and Circle
*/
#ifndef SHAPE_HPP
#define SHAPE_HPP
#include<string>

class Shape
{
private:
	//Datas, not accesible to users
	int m_id;//ID of the shape.
public:
	//Member functions, accessible to users
	// 
	//Constructors and destructors
	Shape();//Default constructors
	Shape(const Shape& source);//Copy constructor
	~Shape();//Default destructor

	//Assignment operator
	const Shape& operator = (const Shape& source); // Assignment operator.

	//ToString function
	std::string ToString() const;//Turn the ID to a string

	//ID Getter
	int ID() const;//Get the id
};


#endif