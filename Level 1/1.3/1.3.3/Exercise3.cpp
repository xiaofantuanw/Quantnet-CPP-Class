/* Operators */
#include <stdio.h>
int main()
{
	int x;
	x = -3 + 4 * 5 - 6;
	printf("x=%d\n", x);//Prediction:11
	x = 3 + 4 % 5 - 6;
	printf("x=%d\n", x);//Prediction:1
	x = -3 * 4 % -6 / 5;
	printf("x=%d\n", x);//Prediction:0
	x = (7 + 6) % 5 / 2;
	printf("x=%d\n", x);//Prediction:1
	return 0;
}