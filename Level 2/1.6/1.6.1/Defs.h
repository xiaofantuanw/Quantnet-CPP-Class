/*File comments
* Author: Tengxiao Fan
* This is the head file for the project.
* Project objective: use macro call to print two variables
* This file gives the definition of macros 
*/
#ifndef _DEFS_H//To avoid compile error
#define _DEFS_H
#include <stdio.h>
#define PRINT1(var1) (printf("The result of PRINT1 is %d\n",var1))//Definition of PRINT1, which prints one variable
#define PRINT2(var1,var2) (printf("The result of PRINT2 is %d, %d\n",var1,var2))//Definition of PRINT1, which prints two variables


#endif // !_DEFS_H
