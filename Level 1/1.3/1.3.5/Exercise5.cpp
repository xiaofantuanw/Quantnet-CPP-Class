#include <stdio.h>

int main()
{
	int num = 3,out;
	out = ++num;
	printf("num=%d,out=%d\n", num, out);//out should be 4, num should be 4.
	out = num++;
	printf("num=%d,out=%d\n", num, out);//out should be 4, num should be 5.
	return 0;
}