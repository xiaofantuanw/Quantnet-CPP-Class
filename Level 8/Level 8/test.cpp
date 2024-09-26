//test.cpp
//Author:Tengxiao Fan
//This is the test file for C++ tuple and span.
#include <iostream>
#include <tuple>
#include <string>
#include <list>
#include <algorithm>
#include <span>
#include <array>
#include <boost/date_time/gregorian/gregorian.hpp>

//Define the tuple of string, string, date a person
using namespace boost::gregorian;
typedef std::tuple<std::string, std::string, date> Person;

//Function to print the information of person
void prtPerson(Person p)
{
	std::cout << "Name: " << std::get<0>(p) << std::endl;//Name
	std::cout << "Address: " << std::get<1>(p) << std::endl;//Address
	std::cout << "Date of Birth: " << std::get<2>(p) << std::endl;//Date of Birth
}

//This is the template function for sorting the vector of person with some index
template <int index>
void SortPerson(std::vector <Person>& listp)
{
	//A lambda function criterion
	auto myfunc = [](Person p1, Person p2) {return std::get<index>(p1) < std::get<index>(p2);};
	std::sort(listp.begin(), listp.end(), myfunc);
}

//Print span using range-based for loop
template <typename T>
void prtspan1(const std::span<T>& sp1)
{
	for (auto const& ele : sp1)
	{
		std::cout << ele << ",";
	}
	std::cout << std::endl;
}

//Print span using iterators
template <typename T>
void prtspan2(const std::span<T>& sp1)
{
	for (auto i = std::begin(sp1); i != std::end(sp1); i++)
	{
		std::cout << *i << ",";
	}
	std::cout << std::endl;
}

//Print span using indexing operator
template <typename T>
void prtspan3(const std::span<T>& sp1)
{
	for (int i = 0; i < sp1.size(); i++)
	{
		std::cout << sp1[i] << ",";
	}
	std::cout << std::endl;
}

//Get the first and last N elements of a span
//Also a test function for subspan
template <typename T>
std::tuple<std::span<T>,std::span<T>> getFirstLast(const std::span<T>& sp1,int N)
{
	auto first = sp1.subspan(0, N);//First N elements
	auto last = sp1.subspan(sp1.size() - N);//Last N elements
	std::tuple<std::span<T>, std::span<T>> t(first, last);//Return a tuple
	return t;
}

int main()
{
	//Person data
	Person p1("Jack", "Address1", date(2000,10,5));
	Person p2("Mike", "Address2", date(2001, 3, 3));
	Person p3("Lisa", "Address3", date(1999, 9, 11));

	//Test the print function
	prtPerson(p1);
	//Vector of person
	std::vector<Person> vecp;
	vecp.push_back(p1);
	vecp.push_back(p2);
	vecp.push_back(p3);
	//Test the sort function and print it
	SortPerson<2>(vecp);
	std::for_each(vecp.begin(), vecp.end(), prtPerson);

	//Test of span
	std::array<int,5> a1 = { 1,2,3,4,5 };
	std::vector<int> a2 = { 1,2,3,4,5 };
	std::span<int> sp1(a1);//fixed size
	std::span<int> sp2(a2);//variable size
	//Span is not read-only! Modify it
	sp1[3] = -1;
	sp2[3] = -1;

	//Test the three print functions
	prtspan1<int>(sp1);
	prtspan2<int>(sp2);
	prtspan3<int>(sp2);
	//Get the first and last N elements
	auto t = getFirstLast(sp1, 4);
	prtspan1<int>(std::get<0>(t));
	prtspan1<int>(std::get<1>(t));

	// Bytes stuff
	float data[1]{ 3.141592f };
	auto const const_bytes = std::as_bytes(std::span{ data });
	for (auto const b : const_bytes)
	{
		std::cout << std::setw(2)
			<< std::hex
			<< std::uppercase
			<< std::setfill('0')
			<< std::to_integer<int>(b) << ' ';
	}
	// Exx. test
	//std::as_writable_bytes

	auto const const_writable_bytes = std::as_writable_bytes(std::span{ data });
	for (auto const b : const_writable_bytes)
	{
		std::cout << std::setw(2)
			<< std::hex
			<< std::uppercase
			<< std::setfill('0')
			<< std::to_integer<int>(b) << ' ';
	}
	return 0;
}