/* CS261- Assignment 1 - Q.2*/
/* Name: JoAnne Hutter
 * Date: 2016-04-10
 * Solution description: initialize and assign 3 ints and change 2 of them in a function 
 * using pass by reference
 */
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
	*a = *a * 2;
    
    /*Set b to half its original value*/
	*b = *b / 2;
    
    /*Assign a+b to c*/
	c = *a+*b;
    
    /*Return c*/
	return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
	int x = 5;
	int y = 6;
	int z = 7;
    
    /*Print the values of x, y and z*/
	printf("x = %d\ny = %d\nz = %d\n", x,y,z);
    
    /*Call foo() appropriately, passing x,y,z as parameters*/
    /*Print the value returned by foo*/
	printf("foo returned %d\n", foo(&x, &y, z));
    
    /*Print the values of x, y and z again*/
	printf("x = %d\ny = %d\nz = %d\n", x,y,z);
 
    /*Is the return value different than the value of z?  Why?*/
	/*Yes, because z was passed by value; only foo's local copy of c was changed */
    return 0;
}
    
    
