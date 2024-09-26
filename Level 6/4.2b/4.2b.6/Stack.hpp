/*Array.hpp
* This is the header file for template Stack.
* This class defines array of a class that dynamically allocates memory.
*/
#ifndef Stack_HPP
#define Stack_HPP
#include "Array.hpp"

template <typename T, int size>
class Stack
{
private:
	//Data members, invisible to users
	Array<T> m_array;//The array data member
	int m_current;//Current index
public:
	//menmer functions
	//Constructors and destructors
	Stack();//Defalt constructor
	Stack(const Stack<T,size>& source);//Copy constructor
	~Stack();//Destructor

	//Assignment operator
	const Stack<T,size>& operator= (const Stack<T,size>& source);
	//Push and Pop functions
	void Push(T& element);//Push function
	const T Pop();//Pop function
};

#ifndef Stack_CPP
#include "Stack.cpp"
#endif // !Stack_CPP

#endif // !Stack_HPP
