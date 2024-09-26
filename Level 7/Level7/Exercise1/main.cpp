/*Main.cpp
* Author: Tengxiao Fan
* This file tests different STL containers: list, vector and map.
*/

#include <iostream>
#include <list>
#include <vector>
#include <map>

int main()
{
	//Test std::list
	std::cout << "Test of list." << std::endl;
	std::list<double> l;//Create a list of doubles
	l.push_back(1.5);
	l.push_back(2.5);
	l.push_front(3.5);//Add some data
	std::cout << "The first element of list l: " << l.front() << std::endl;
	std::cout << "The last element of list l: " << l.back() << std::endl;
	l.clear();//Clear the list
	std::cout << "End of Test of list." << std::endl<<std::endl;
	//Use the front() and back() functions to access the first and last element.
	
	//Test std::vector
	std::cout << "Test of vector." << std::endl;
	std::vector<double> vec;//Create a vector of doubles
	for (int i = 1;i <= 10;i++)//push 10 elements to the vector
	{
		vec.push_back(i+0.5);
		std::cout << "Capacity: "<<vec.capacity() << std::endl;
		//Show the capacity of the vector. The capacity is growing
	}
	std::cout << "The first element of the vector: " << vec[0] << std::endl;
	std::cout << "The sixth element of the vector: " << vec[5] << std::endl;//use the index operator to access some elements
	vec.clear();//Clear the vector
	std::cout << "End of Test of vector." << std::endl << std::endl;

	//Test std::map
	std::cout << "Test of map." << std::endl;
	std::map<std::string, double> map1;//Create a map that maps strings to doubles
	map1["Jack"] = 3.8;
	map1["John"] = 3.45;
	map1["Mary"] = 2.77;//Fill the map using the square bracket operator.
	std::cout << "Map of \"Jack\": " << map1["Jack"]<<std::endl;//access elements using the square bracket operator.
	map1.clear();//Clear the map
	std::cout << "End of Test of map." << std::endl ;
}