/*ArrayException.hpp
* This file defines and declares the exception class of stack and its derived classes.
*/
#ifndef StackException_HPP
#define StackException_HPP
#include <string>

class StackException
{
public:
	//Constructors and Destructors
	StackException() {}//Default constructor
	virtual ~StackException() {}//Destructor
	//Abstract GetMessage()
	virtual std::string GetMessage() const = 0;
};

class StackFullException :public StackException
{
public:
	//Constructors and Destructors
	StackFullException() {}//Default constructor
	virtual ~StackFullException() {}//Destructor
	//GetMessage Function
	std::string GetMessage() const { return "Stack Full."; }
};

class StackEmptyException :public StackException
{
public:
	//Constructors and Destructors
	StackEmptyException() {}//Default constructor
	virtual ~StackEmptyException() {}//Destructor
	//GetMessage Function
	std::string GetMessage() const { return "Stack Empty."; }
};

#endif // !StackException_HPP
