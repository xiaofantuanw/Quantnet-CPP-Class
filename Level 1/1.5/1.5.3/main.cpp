#include <stdio.h>

void print(double i);//Declare the function defined in another source file.

int main()
{
	
	double i = 3.4;
	print(i);
	return 0;
}