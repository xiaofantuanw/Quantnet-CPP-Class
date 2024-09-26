#define _CRT_SECURE_NO_WARNINGS//Safe for scanf
#include<stdio.h>


int main()
{
	double base, height, surface; //Declare variables.
	printf("Please enter the base: ");
	scanf("%lf", &base);
	printf("Please enter the height: ");
	scanf("%lf", &height);//Scan the input by the user

	if (base>0 && height>0)//If the inputs are not positive numbers, then it is not a triangle.
	{
		surface = 0.5 * base * height;//Calculate the surface
		printf("Surface of the triangle: %f", surface);
	}
	else
	{
		printf("Input error.\n");
	}
	return 0;
}