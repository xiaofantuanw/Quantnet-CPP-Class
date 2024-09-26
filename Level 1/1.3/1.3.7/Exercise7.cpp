#include <stdio.h>

int main()
{
	int num, power;
	num = 13;
	power = 5;//Caution: If the power is too large, there might be overflow.
	num = num << power;//shift the digits to the left for some.
	printf("Result: %d", num);
	return 0;
}