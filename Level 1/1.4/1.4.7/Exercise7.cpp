#include <stdio.h>

int main()
{
	char character;
	int count_0 = 0, count_1 = 0, count_2 = 0, count_3 = 0, count_4 = 0, count_others = 0;
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
	printf("Number zero appears %d times.\nNumber one appears %d times\nNumber two appears %d times\n", count_0, count_1, count_2);
	switch (count_3)
	{
	case 0:
		printf("Number three appears zero times.\n");
		break;
	case 1:
		printf("Number three appears one time.\n");
		break;
	case 2:
		printf("Number three appears two times.\n");
		break;
	default:
		printf("Number three appears more than two times.\n");
		break;
	}
	printf("Number four appears %d times\nOther characters appear %d times.\n", count_4, count_others);
	return 0;
}