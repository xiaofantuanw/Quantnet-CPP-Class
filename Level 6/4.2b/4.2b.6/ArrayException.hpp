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
	virtual ~ArrayException(){}//Destructor
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
	virtual ~OutOfBoundsException() {}//Destructor
	//GetMessage Function
	std::string GetMessage() const{ return "Index out of bound."; }
};

class IndexNotMatchException :public ArrayException//This is the exception for adding two arrays that don't match
{
private:
	int m_index1;
	int m_index2;//The index of the two arrays that don't match
public:
	//Constructors and destructors
	IndexNotMatchException() { m_index1 = 0;m_index2 = 0; }//Default constructor
	IndexNotMatchException(int index1,int index2){ m_index1 = index1;m_index2 = index2; }//Constructor with error index
	virtual ~IndexNotMatchException() {}//Destructor
	//GetMessage Function
	std::string GetMessage() const { return "The index of two arrays don't match."; }
};

#endif // !ArrayException_HPP
