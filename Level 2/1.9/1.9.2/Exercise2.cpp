/*File comments
* Author: Tengxiao Fan
* Objective: This program reads the characters input by the user and show them
* in a file. It can be ended with Ctrl+A (Ctrl+Shift+A).
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
/* main function*/
{
	char character;
	FILE* fp;//File pointer
	fp = fopen("file.txt", "w");//Open(or create) a file.
	if (fp == NULL)//Judge whether the file pointer is NULL
	{
		printf("Can't open file.");
		return -1;//This is a wrong case
	}
	while ((character = getchar()) != 1 && character != EOF)//read the character, if not ended, show it.
	{
		fputc(character,fp);//Put the character into a file
	}
	if (character == 1)//Judge whether the program is ended properly. Also put the result in the file.
	{
		fprintf(fp,"CTRL + A is a correct ending.\n");
	}
	else//EOF is not a correct ending
	{
		fprintf(fp,"Wrong ending.\n");
	}
	fclose(fp);//Close the file.
	return 0;
}