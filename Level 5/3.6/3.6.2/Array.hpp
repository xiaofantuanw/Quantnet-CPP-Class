/*Array.hpp
* This is the header file for class Array. 
* This class defines array of class Point that dynamically allocates memory.
*/
#ifndef Array_HPP//Preventing repeated including
#define Array_HPP
#include "Point.hpp"

class Array
{
private:
	//Datas, not accesible to users
	Point* m_data;//a dynamic C array of Point objects
	int m_size;//size of the array.
public:
	//Member functions, accessible to users
	// 
	//Constructors and destructors
	Array();//Default constructor
	Array(int size);//constructor with size
	Array(const Array& source);//Copy constructor
	~Array();//Default destructor
	//Assignment operator
	const Array& operator = (const Array& source);
	//Return the size
	int Size() const;
	//Set the element of the array
	void SetElement(int index, const Point& pt);
	//Get the element of an index
	const Point& GetElement(int index) const;
	//Square Bracket Operator for both read and write
	Point& operator [] (int index);
	//Square Bracket Operator for read
	const Point& operator [] (int index) const;
	//The reason that we need this read-only square bracket operator:
	//We have to ensure that we have a square bracket operator available for "const Array" type.
};




#endif // !Array_HPP
