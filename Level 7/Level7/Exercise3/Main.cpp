/*Main.cpp
* Author: Tengxiao Fan
* This program uses the count_if algorithm to count the number of elements smaller than a certain number.
* Using global function and function object respectively.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include "Functor_Predicate.hpp"

bool predicate(int n) 
//This function is a global function to predicate whether a number is less than a threshold
{
	int threshold = 4;
	return (n < threshold);
}

int main()
{
	std::vector<int> v = {1, 2, 3, 4, 5};//Generate a vector
	//Count how many numbers are less than threshold 4 using global function
	std::cout << count_if(v.begin(), v.end(), predicate) << " numbers are smaller that 4. (Using global function)" << std::endl;

	Functor_Predicate<int> FP(4);//A function object with int type
	 //Count how many numbers are less than threshold 4 using function object
	std::cout << count_if(v.begin(), v.end(), FP)<< " numbers are smaller that 4. (Using function object)" << std::endl;

	return 0;
}

