#define _CRT_SECURE_NO_WARNINGS//Safe for scanf
#include <stdio.h>

int main()
{
	int num, arithmetic_right, logical_right,test;
	printf("Please input an integer.");
	scanf("%d", &num);//Get the integer
	arithmetic_right = num >> 2;//arithmetic shift for int
	logical_right = (unsigned int)num >> 2;//logical shift for unsigned int
	printf("arithmetic right shift for 2 digits: %d \nlogical right shift for 2 digits: %d \n", arithmetic_right, logical_right);
	return 0;
	
}