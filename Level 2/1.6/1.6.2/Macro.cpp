/*File comments
* Author: Tengxiao Fan
* Objective: use macro call to return the maximal value of two or three numbers
* Applicable changes: change variable x y and z
*/
#include "Defs.h"
int main()
{
	/*
	* main function: give value to x y z
	*/
	double x = 3.5, y = 7.8, z = 12, mx2, mx3=0;//mx2 and mx3 are maximum of two or three nums
	mx2 = MAX2(x, y); //Call macro MAX2
	mx3 = MAX3(x, y, z);  //Call macro MAX3
	printf("The maximum of x and y: %f\nThe maximum of x, y, and z: %f", mx2, mx3);//Print the results
	return 0;
}