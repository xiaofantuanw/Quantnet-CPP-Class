/* Author: Tengxiao Fan
* Objective: build a function to swap two variables (i.e. integers).
* Use pointers to build the function
*/

#include<stdio.h>

int swap(int* address1, int* address2)
/*Function: swap
* This function swap the value of the variables in two different addresses, using pointers.
* It will return an integer to indicate whether the swap succeed.
* If one of the pointer is a NULL pointer, it will fail and return -1.
*/
{
	int temp;
	if (address1 == NULL || address2 == NULL)//If one of the pointers is NULL, the swap fails and return -1.
	{
		return -1;
	}
	else//Other cases, the numbers will be swapped
	{
		temp = (*address1);//Use a temp to store the value of one of the varibles.
		(*address1) = (*address2);
		(*address2) = temp;
		return 0;
	}
}

int main()
/*Main function
* You can change the value of i and j
*/
{
	int i = 123, j = 456, success;//Give value to two variables, and an indicator of whether the function succeeds.
	success=swap(&i, &j);//Swap the variables
	if (success == 0)//Output the result.
	{
		printf("Result: i=%d, j=%d\n", i, j);
	}
	else
	{
		printf("Swap unsuccess: null pointer.\n");
	}
	return 0;
}