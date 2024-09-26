#include <stdio.h>
#include <ctype.h>


int main()
{
	char c, former_c = ' ';
	int character = 0, word = 0, lines = 1;//The first line should be counted.
	while ((c = getchar()) != EOF && c != 4)//Get the character, if it is not EOF or Ctrl_D
	{
		switch (former_c)
		{
		case ' ': //The same as isspace, for blanks.
		case '\t':
		case '\n':
		case '\v':
		case '\f':
		case '\r':
			switch (c)//If another character other than blanks follows a blank, add a word.
			{
			case '\n':
				lines++;
				break;
			case ' ':
			case '\t':
			case '\v':
			case '\f':
			case '\r':
				break;
			default:
				word++;
			}
			break;

		default:
			switch (c)
			{
			case '\n':
				lines++;
				break;
			default:
				break;
			}
			break;
		}
		
		
		character++;//Any characters should be counted
		former_c = c;//Record the last character
	}
	printf("Characters: %d\nWords: %d\nLines: %d", character, word, lines);
	return 0;
}