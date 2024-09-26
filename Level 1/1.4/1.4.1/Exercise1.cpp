#include <stdio.h>
#include <ctype.h>


int main()
{
	char c,former_c=' ';
	int character = 0, word = 0, lines = 1;//The first line should be counted.
	while ((c = getchar()) != EOF&& c!=4)//Get the character, if it is not EOF or Ctrl_D
	{
		if (isalnum(c)&&isspace(former_c))//This means that the character is the first character of a new word. Count the word.
		{
			word++;
		}
		if (c == '\n')//A new line begins.
		{
			lines++;
		}
		
		character++;//Any characters should be counted, including alphabets numbers blanks and controls.
		former_c = c;//Record the last character
	}
	printf("Characters: %d\nWords: %d\nLines: %d", character, word, lines);
	return 0;
}