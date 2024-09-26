#include <stdio.h>

int factorial(int base)
{
	if (base < 0)//Not valid for negative numbers, just use a negative return
		return -1;
	if (base == 0)
		return 1;
	if (base > 0)//Recursive, n!=n*(n-1)!
		return base * factorial(base - 1);
}

int main()
{
	int base,fact,maxbase=10;
	for (base = 0;base <= maxbase;base++)//Print the factorial of 1 to maxbase.
	{
		fact = factorial(base);
		printf("The factorial of %d is %d\n", base, fact);
	}
	return 0;
}