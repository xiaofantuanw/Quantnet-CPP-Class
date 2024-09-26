#include <stdio.h>

double minus(double sub_a, double sub_b)
{
	double result;
	result = sub_a - sub_b;
	printf("Difference: %f", result);//This will print the difference on the screen
	return result;
}

int main()
{
	double a = 3, b = 4;//The data type can also be int.
	minus(a, b);//Use the function
	return 0;
}