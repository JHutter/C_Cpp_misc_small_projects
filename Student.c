/* CS261- Assignment 1 - Q.1*/
/* Name: JoAnne Hutter
 * Date: 2016-04-10
 * Solution description: create, assign, summarize 10 student structs
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>


struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
	 struct student * studentPtr = malloc(10 * sizeof(struct student));
	 /* No assert here because that would require adding assert.h, and the instructions
	  * specified not to add any additional header files*/
     
     /*return the pointer*/
	 return studentPtr;
}

void generate(struct student* students){
     /*Generate random and unique ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
     int numStus = 10;
	 int randID, randScore;
	 int isIDused;
	 /* Note: the assignment instructions specified not to add any header files
	  * so, I didn't use time(NULL) when calling srand, and so the random numbers
	  * will repeat on subsequent runs of generate() because the seed is always 0*/
	 srand (0);
	 
	 /* iterate through all 10 students*/
	 for (int i = 0; i < numStus;i++) {
		 randScore = rand() % 101;
		 isIDused = 1;
		 
		 /* loop in order to ensure unique student ID is assigned */
		 while (isIDused) {
			randID = rand() % 10 + 1;
			
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
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
	int numStus = 10;
	
	for (int i = 0; i < numStus; i++) {
		printf("ID%d Score%d\n", students[i].id, students[i].score);
	}
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
	 int scoreLow = 100;
	 int scoreHigh = 0;
	 double scoreAvg;
	 int scores = 0;
	 int numStus = 10;
	 
	 /* iterate and check for high score, low score, and add to scores */
	 for (int i = 0; i<numStus; i++) {
		 if (students[i].score < scoreLow) {
			 scoreLow = students[i].score;
		 }
		 if (students[i].score > scoreHigh) {
			 scoreHigh = students[i].score;
		 }
		 scores += students[i].score;
	 }
	 scoreAvg = (double) scores /  numStus;
	 
	 
	 printf("Lowest score is %4d\n", scoreLow);
	 printf("Highest score is %3d\n", scoreHigh);
	 /* format scoreAvg to 2 decimal places */
	 printf("Average score is  %.2f\n", scoreAvg);
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
	 if (stud == 0) {
		return;
	 }
	 free(stud);
}

int main(){
    struct student* stud = NULL;
    
    /*call allocate*/
	stud = allocate();
    
    /*call generate*/
	generate(stud);
    
    /*call output*/
	output(stud);
    
    /*call summary*/
	summary(stud);
    
    /*call deallocate*/
	deallocate(stud);

    return 0;
}
