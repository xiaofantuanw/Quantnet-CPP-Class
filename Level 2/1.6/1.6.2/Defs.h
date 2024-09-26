/*File comments
* Author: Tengxiao Fan
* This is the head file for the project.
* Project objective: use macro call to return the maximal value of two or three numbers
* This file gives the definition of macros
*/
#ifndef _DEFS_H//To avoid compile error
#define _DEFS_H
#include <stdio.h>
#define MAX2(var1 , var2) ( var1 > var2 ? var1 : var2 )//Definition of MAX2, which gives the maximum of two variables
#define MAX3(var1 , var2 , var3) ( var1 > var2 ? (var1 > var3 ? var1 : var3 ) : ( var2 > var3 ? var2 : var3 )) //Definition of MAX3, which gives the maximum of three variables


#endif // !_DEFS_H

