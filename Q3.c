/* CS261- Assignment 1 - Q.3*/
/* Name: JoAnne Hutter
 * Date: 2016-04-10
 * Solution description: create and sort an array
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>


void sort(int* number, int n){
     /*Sort the given array number , of length n*/   
	 int sorted = n;
	 int placeHolder;
	 
	 /* bubble sort*/
	 while (sorted > 1) {
		 for (int i = 0; i < n-1;i++) {
			 if (number[i+1] < number[i]) {
				 placeHolder = number[i];
				 number[i] = number[i+1];
				 number[i+1] = placeHolder;
			 }
		 }
		 /* decrease the range in the array that we're checking*/
		 sorted--;
	 }
	
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
	int n = 20;
    
    /*Allocate memory for an array of n integers using malloc.*/
	int* array = malloc(n*sizeof(int));
    
    /*Fill this array with random numbers, using rand().*/
	/* Note: instructions say no added header files, so I seeded srand with 0
	 * instead of time(NULL), so the random numbers repeat each time this is run */
	srand(0);
	for (int i = 0; i < n; i++) {
		array[i] = rand();
	}
    
    /*Print the contents of the array.*/
	for (int j = 0; j < n; j++) {
		printf("array val: %d\n", array[j]);
	}

    /*Pass this array along with n to the sort() function of part a.*/
	sort(array, n);
    
    /*Print the contents of the array.*/    
	for (int j = 0; j < n; j++) {
		printf("sorted val: %d\n", array[j]);
	}
    
    return 0;
}
