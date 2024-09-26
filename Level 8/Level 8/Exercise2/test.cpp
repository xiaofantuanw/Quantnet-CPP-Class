/*test.cpp
* author:Tengxiao Fan
* This is a program testing tuples in boost.
*/

#include "boost/tuple/tuple.hpp"	// Tuple class
#include "boost/tuple/tuple_io.hpp" // I/O for tuples
#include <iostream>

using boost::tuple;//using the class tuple
typedef tuple<std::string, int, double> Person;//use typedef to define Person

//Function to print person
void PrintPerson(Person p)
{
	std::cout << "Name: " <<p.get<0>()<< std::endl;//print the person's name in tuple, using get<>
	std::cout << "Age: " << p.get<1>() << std::endl;//print the person's age in tuple, using get<>
	std::cout << "Length: " << p.get<2>() << std::endl<<std::endl;//print the person's length in tuple, using get<>
}

int main()
{
	Person p1=boost::make_tuple(std::string("Mike"), 30, 1.78);
	Person p2 = boost::make_tuple(std::string("Jack"), 50, 1.87);
	Person p3 = boost::make_tuple(std::string("Mary"), 18, 1.58);//Create a few instances of person
	PrintPerson(p1);
	PrintPerson(p2);
	PrintPerson(p3);//Print the persons
	p1.get<1>()++;//Increment the age of person 1
	std::cout << "Incremented!" << std::endl;
	PrintPerson(p1);//Print the person 1 again
	return 0;
}