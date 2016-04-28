/* CS261- Assignment 1 - Q.4*/
/* Name: JoAnne Hutter
 * Date: 2016-04-10
 * Solution description: create array of student structs, sort it by id
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
     /*Sort the n students based on their score*/    
	 int sorted = n;
	 int placeHolder;
	 
	 /* bubble sort*/
	 while (sorted > 1) {
		 for (int i = 0; i < n-1;i++) {
			 if (students[i+1].id < students[i].id) {
				 placeHolder = students[i].id;
				 students[i].id = students[i+1].id;
				 students[i+1].id = placeHolder;
			 }
		 }
		 /* decrease the range in the array that we're checking*/
		 sorted--;
	 }	 
}

int main(){
    /*Declare an integer n and assign it a value.*/
	int n = 10;
    
    /*Allocate memory for n students using malloc.*/
	struct student * students = malloc(n * sizeof(struct student));
    
    /*Generate random IDs and scores for the n students, using rand().*/
	int randID, randScore;
	int isIDused;
	 /* Note: the assignment instructions specified not to add any header files
	  * so, I didn't use time(NULL) when calling srand, and so the random numbers
	  * will repeat on subsequent runs of generate() because the seed is always 0*/
	 srand (0);
	 
	 /* iterate through all 10 students*/
	 for (int i = 0; i < n;i++) {
		 randScore = rand() % 101;
		 isIDused = 1;
		 
		 /* loop in order to ensure unique student ID is assigned */
		 while (isIDused) {
			randID = rand() % 10 + 1;
			isIDused = 0;
			
			/* we already know students[0] is a unique ID, it's the first one */
			if (i == 0) {
				isIDused = 0;
				continue;
			}
			 
			 /* check current random ID against the already assigned IDs,
			  * if it's unique, set isIDused to 0 to break out of the while loop*/
			for (int j = 0; j < i;j++) {
				 if (students[j].id == randID) {
					 isIDused = 1;
					 break;
				}
				else {
					isIDused = 0;
				}
			}
		}
		 
		 /* assign id and score */
		students[i].id = randID;
		students[i].score = randScore;
	 }
    
    /*Print the contents of the array of n students.*/
	for (int i = 0; i < n; i++) {
		printf("ID%d Score%d\n", students[i].id, students[i].score);
	}

    /*Pass this array along with n to the sort() function*/
	sort(students, n);
    
    /*Print the contents of the array of n students.*/
	for (int i = 0; i < n; i++) {
		printf("ID%d Score%d\n", students[i].id, students[i].score);
	}
    
    return 0;
}
