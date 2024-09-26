#include <stdio.h>

void printnumber(int number)
{
	int digitvalue;
	char digit;
	if (number < 0)//Deal with negative numbers: put a minus and turn it to a positive number.
	{
		putchar('-');
		number = -number;
	}
	if (number>=10)//If more than 1 digit, use recursive to print the digits
	{
		printnumber(number / 10);
	}
	digitvalue = number % 10;
	digit = digitvalue + '0';//turn int to char
	putchar(digit);
}

int main()
{
	int number = -3567;
	printnumber(number);
	return 0;
}