/* CS261- Assignment 1 - Q. 0*/
/* Name: Jon Hutter
 * Date: 2016-04-10
 * Solution description: Explore pointers by printing the value and address
 * of a variable and passing it by reference to a function.
 */
 
#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
     /*Print the value pointed to by iptr*/
	 printf("In fooA, the value pointed to by iptr is %d\n", *iptr);
     
     /*Print the address pointed to by iptr*/
	 printf("In fooA, the address pointed to by iptr is %p\n", iptr);
     
     /*Print the address of iptr itself*/
	 printf("In fooA, the address of iptr is %p\n", &iptr);
}

int main(){
    
    /*declare an integer x*/
	int x = 5;
    
    /*print the address of x*/
	printf("In main, the address of x is %p\n", &x);
    
    /*Call fooA() with the address of x*/
	fooA(&x);
    
    /*print the value of x*/
	printf("In main, the value of x is %d\n", x);
    
    return 0;
}
