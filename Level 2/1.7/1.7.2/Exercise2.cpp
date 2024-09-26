/* Calculate the length of a string */
#include <stdio.h>
#define MAXLINE 30
// String lenght declaration
int Length(char str[]);
int main()
{
	char string[MAXLINE + 1]; // Line of maxium 30 chars + \0
	int c; // The input character
	int i = 0; // The counter
	// Print intro text
	printf("Type up to %d chars. Exit with ^Z\n", MAXLINE);
	// Get the characters
	while ((c = getchar()) != EOF && i < MAXLINE)
	{
		// Append entered character to string
		string[i++] = (char)c;
	}
	string[i] = '\0'; // String must be closed with \0
	//printf("%s\n", string);
	printf("String length is %d\n", Length(string));
	return 0;
}
/* Implement the Length() function here */
int Length(char str[])
/*Fuction: length
* Return the length of an array
*/
{
	int count=0;//initialize the count to be zero.
	while (count < MAXLINE && str[count] != '\0')
	/*If we don't meet the upper length bound of the string or the end of the string, move on*/
	{
		count++;
	}
	return count;//return the length
}