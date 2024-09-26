/*File comments
* Author: Tengxiao Fan
* Objective: use macro call to print two variables
* Applicable changes: change variable a and b
*/
#include "Defs.h"
int main()
{
/*
* main function: give value to a and b
*/
	int a = 10 , b = 20 ;
	PRINT1(a);//Call macro PRINT1
	PRINT2(a, b);//Call macro Print2
	return 0;
}