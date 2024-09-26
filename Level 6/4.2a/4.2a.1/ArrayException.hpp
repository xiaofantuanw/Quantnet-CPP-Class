/*ArrayException.hpp
* This file defines and declares the exception class and its derived classes.
*/
#ifndef ArrayException_HPP//avoid repeated inclusion
#define ArrayException_HPP
#include <string>

class ArrayException
{
public:
	//Constructors and Destructors
	ArrayException(){}//Default constructor
	~ArrayException(){}//Destructor
	//Abstract GetMessage()
	virtual std::string GetMessage() const = 0;
};

class OutOfBoundsException:public ArrayException
{
private:
	int m_index;//Index which is out of bound.
	
public:
	//Constructors and Destructors
	OutOfBoundsException() { m_index = 0; }//Default constructor
	OutOfBoundsException(int index) { m_index = index; }//Constructor with error index
	~OutOfBoundsException() {}//Destructor
	//GetMessage Function
	std::string GetMessage() const{ return "Index out of bound."; }
};

#endif // !ArrayException_HPP
