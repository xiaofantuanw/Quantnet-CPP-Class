#include <stdio.h>

int main()
{
	char character;
	int count_0 = 0, count_1 = 0, count_2=0, count_3 = 0, count_4 = 0, count_others = 0;
	while ((character = getchar()) != EOF)
	{
		switch (character)
		{
		case '0':
			count_0++;
			break;
		case '1':
			count_1++;
			break;
		case '2':
			count_2++;
			break;
		case '3':
			count_3++;
			break;
		case '4':
			count_4++;
			break;
		default:
			count_others++;
			break;
		}
	}
	printf("The numbers of\n0: %d\n1: %d\n2: %d\n3: %d\n4: %d\nother characters: %d\n", count_0, count_1, count_2, count_3, count_4, count_others);
	return 0;
}