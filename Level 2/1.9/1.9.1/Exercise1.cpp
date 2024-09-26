/*File comments
* Author: Tengxiao Fan
* Objective: This program reads the characters input by the user and show them
* on the screen. It can be ended with Ctrl+A (Ctrl+Shift+A).
*/
#include <stdio.h>

int main()
/* main function*/
{
	char character;
	while ((character = getchar()) != 1 && character != EOF)//read the character, if not ended, show it.
	{
	putchar(character);
	}
	if (character == 1)//Judge whether the program is ended properly.
	{
		printf("CTRL + A is a correct ending.\n");
	}
	else//EOF is not a correct ending
	{
		printf("Wrong ending.\n");
	}
	return 0;
}