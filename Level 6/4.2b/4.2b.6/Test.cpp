/* Test.cpp
* Author: Tengxiao Fan
* This program tests the Stack.
*/
#include "Point.hpp"
#include "Array.hpp"
#include "ArrayException.hpp"
#include "Stack.hpp"
#include "StackException.hpp"
#include <iostream>

int main()
{
	int n = 10;
	Stack<int, 10> intstack;//Build a stack, cannot use variable in template!
	try//Try valid push
	{
		for (int index = 0;index < n;index++)
		{
			intstack.Push(index);//Valid push
		}
		std::cout << "Valid Push Succeed." << std::endl;
	}
	catch (StackException& exception)//For object thrown
	{
		std::cout << exception.GetMessage() << std::endl;//Use GetMessage Function to output the message
	}
	catch (...)
	{
		std::cout << "Other errors" << std::endl;//unexpected errors
	}


	try//Try invalid push
	{
		int index = n;
		intstack.Push(index);//Invalid push
	}
	catch (StackException& exception)//For object thrown
	{
		std::cout << exception.GetMessage() << std::endl;//Use GetMessage Function to output the message
	}
	catch (...)
	{
		std::cout << "Other errors" << std::endl;//unexpected errors
	}

	//Stack<int, 5> intstack2;
	//intstack2 = intstack;//Invalid

	try//Try valid pop
	{
		for (int i = 1;i <= n;i++)
		{
			std::cout << "Pop " << i << ": " << intstack.Pop() << std::endl;
		}
	}
	catch (StackException& exception)//For object thrown
	{
		std::cout << exception.GetMessage() << std::endl;//Use GetMessage Function to output the message
	}
	catch (...)
	{
		std::cout << "Other errors" << std::endl;//unexpected errors
	}

	try//Try invalid pop
	{
		int i = n+1;
		std::cout << "Pop " << i << ": " << intstack.Pop() << std::endl;
	}
	catch (StackException& exception)//For object thrown
	{
		std::cout << exception.GetMessage() << std::endl;//Use GetMessage Function to output the message
	}
	catch (...)
	{
		std::cout << "Other errors" << std::endl;//unexpected errors
	}

	return 0;
}