/*File comments
* Author: Tengxiao Fan
* Objective: The user input a daynumber (1-7), 
the program gives the name of the daynumber (i.e. Sunday for 1)
*/
#define _CRT_SECURE_NO_WARNINGS
#define WEEKDAY 7
#include <stdio.h>
#include <string.h>


void DayName(unsigned int day)
{
	char dayname[7][10];//This array is to store the daynames.
	int currentday;
	strcpy(dayname[0], "Sunday");//Copy the daynames to the array
	strcpy(dayname[1], "Monday");
	strcpy(dayname[2], "Tuesday");
	strcpy(dayname[3], "Wednesday");
	strcpy(dayname[4], "Thursday");
	strcpy(dayname[5], "Friday");
	strcpy(dayname[6], "Saturday");
	if (day > WEEKDAY||day==0)//This case means that the input is invalid
	{
		printf("Only %d days in a week!\n",WEEKDAY);
	}
	else//Print the day
	{
		printf("%d gives: Day %d is a %s\n", day, day, dayname[day - 1]);
	}
}

int main()
{
	int daynumber;
	printf("Please input a day number:\n");
	scanf("%d", &daynumber);//The user input day number here.
	DayName(daynumber);//Print the dayname
	return 0;
}