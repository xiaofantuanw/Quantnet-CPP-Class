/*Array.hpp
* This is the header file for template Array. 
* This class defines array of a class that dynamically allocates memory.
*/
#ifndef Array_HPP//Preventing repeated including
#define Array_HPP


template <typename T>
class Array
{
private:
	//Datas, not accesible to users
	T* m_data;//a dynamic C array of Point objects
	int m_size;//size of the array.
public:
	//Member functions, accessible to users
	// 
	//Constructors and destructors
	Array();//Default constructor
	Array(int size);//constructor with size
	Array(const Array<T>& source);//Copy constructor
	~Array();//Default destructor
	//Assignment operator
	const Array<T>& operator = (const Array<T>& source);
	//Return the size
	int Size() const;
	//Set the element of the array
	void SetElement(int index, const T& pt);
	//Get the element of an index
	const T& GetElement(int index) const;
	//Square Bracket Operator for both read and write
	T& operator [] (int index);
	//Square Bracket Operator for read
	const T& operator [] (int index) const;
	//The reason that we need this read-only square bracket operator:
	//We have to ensure that we have a square bracket operator available for "const Array" type.
};

#ifndef ARRAY_CPP // Must be the same name as in source file #define
#include "Array.cpp"
#endif//These lines can include the source file of the template
#endif // !Array_HPP
