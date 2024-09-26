/*Shape.hpp
* Author: Tengxiao Fan
* Shape class is the superior hierarchy of Point, Line and Circle, with virtual ToString function.
* It is an Abstract Base Class!
* Add the Print() function using Template Method Pattern.
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
	virtual ~Shape();//Default destructor

	//Assignment operator
	const Shape& operator = (const Shape& source); // Assignment operator.

	//ToString function
	virtual std::string ToString() const;//Turn the ID to a string

	//ID Getter
	int ID() const;//Get the id

	//PVMF that draws the shape.
	virtual void Draw() const = 0;

	//Print function using Template Method Pattern
	void Print() const;
};


#endif