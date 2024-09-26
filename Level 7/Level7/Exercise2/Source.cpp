/*Source.cpp
* Author: Tengxiao Fan
* This program creates a function that calculates the sum of a container with doubles using iterators
*/
#include <vector>
#include <map>
#include <list>
#include <iostream>

template <typename T>
double Sum(const T& container)
//This function iterates through the container of type T (vector or list) and returns the sum
{
	typename T::const_iterator iterend = container.end();//get an iterator (T::const_iterator) for the end.
	typename T::const_iterator iter;
	double result=0;
	for (iter=container.begin();iter != iterend;iter++)//iterates the container T and adds all values.
	{
		result += (*iter);
	}
	return result;//return the sum
}

template <typename T1, typename T2>
T2 Sum(const std::map<T1, T2>& container)
//This function iterates through the map container of and returns the sum of the value (not key)
{
	T2 result=0;
	typename std::map<T1, T2>::const_iterator iterend = container.end();
	typename std::map<T1, T2>::const_iterator iter;
	for (iter = container.begin();iter != iterend;iter++)
	{
		result += iter->second;
	}
	return result;
}

template <typename T>
double Sum(const typename T::const_iterator& iterstart, const typename T::const_iterator& iterend)
//This function calculates the sum between two iterators
{
	double result = 0;
	typename T::const_iterator iter;
	for (iter = iterstart;iter != iterend;iter++)//from start to end
	{
		result += (*iter);//add the value
	}
	return result;
}

template <typename T1, typename T2>
T2 Sum(const typename std::map<T1, T2>::const_iterator& iterstart, const typename std::map<T1, T2>::const_iterator& iterend)
{
	T2 result = 0;
	typename std::map<T1, T2>::const_iterator iter;
	for (iter = iterstart;iter != iterend;iter++)//from start to end
	{
		result += iter->second;//add the value, not the key
	}
	return result;
}

int main()
{
	std::vector<double> vec1;//Test the sum function for the vector
	vec1.push_back(1.5);
	vec1.push_back(2.5);
	vec1.push_back(2);//push some value
	std::cout << "Sum of the vector (1): "<<Sum<std::vector<double>>(vec1)<<std::endl;
	//Get the sum by Sum function 1
	std::cout << "Sum of the vector (2): " << Sum<std::vector<double>>(vec1.begin(),vec1.end()) << std::endl;
	//Get the sum by Sum function 2

	std::list<double> list1;//Test the sum function for the list
	list1.push_back(1.5);
	list1.push_back(2.5);
	list1.push_front(4.6);//push some value
	std::cout << "Sum of the list (1): "<<Sum<std::list<double>>(list1)<<std::endl;
	//Get the sum by function 1
	std::cout << "Sum of the list (2): " << Sum<std::list<double>>(list1.begin(), list1.end()) << std::endl;
	//Get the sum by Sum function 2

	std::map<std::string, double> map1;//Test the sum function for the map
	map1["Jack"] = 3.8;
	map1["John"] = 3.45;
	map1["Mary"] = 2.77;//push some value
	std::cout << "Sum of the map (1): " << Sum<std::string, double>(map1) << std::endl;
	//Get the sum by Sum function 1
	std::cout << "Sum of the map (2): " << Sum<std::string, double>(map1.begin(),map1.end()) << std::endl;
	//Get the sum by Sum function 2

}