/*File comment
* Author: Tengxiao Fan
* Objective: Define a structure Ariticle and print the infomation about it.
*/
#include <stdio.h>

struct Article
/*A structure Article include Article number, Quantity and Description*/
{
	int Article_number;
	int Quantity;
	char Description[21];//A string of at most 20 characters.
};

void Print(struct Article* particle)
/*A function to print the information of the structure*/
{
	printf("Article number: %d\nQuantity: %d\nDescription: %s\n", particle->Article_number, particle->Quantity, particle->Description);
}

int main()
{
	struct Article myarticle= { 3,5,"An article about C." };//Initialization
	Print(&myarticle);//Print the information
	return 0;
}