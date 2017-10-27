/*	stack.c: Stack application. */
/* Author: Jon Hutter
 * Date: 2016-04-17
 * Name: stackapp.c
 * Solution: Uses a dynArr stack to check for bracket/parenthesis balance */
#include <stdio.h>
#include <stdlib.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string
	pre: s is not null
*/
char nextChar(char* s)
{
	static int i = -1;
	char c;
	++i;
	c = *(s+i);
	if ( c == '\0' )
		return '\0';
	else
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string
	pre: s is not null
	post:
*/
int isBalanced(char* s)
{
	/* FIXME: You will write this function */
	/* stack to keep track of brackets and parentheses */
	DynArr *stack;
	stack = newDynArr(2);

	/* declare chars */
	char currentChar = nextChar(s);
	char reversedBracket;

	/* loop through the string */
	while (currentChar != '\0') {
        /* if the char is open bracket/paren */
        if (currentChar == '(' || currentChar == '{' || currentChar == '[') {

            /* convert to close bracket/paren */
            if (currentChar == '(') {
                reversedBracket = currentChar +1;
            }
            else {
                reversedBracket = currentChar +2;
            }
            pushDynArr(stack, reversedBracket);
        }
        /* if the char is close bracket/paren */
        else if (currentChar == ')' || currentChar == '}' || currentChar == ']') {

            /* check if stack is empty or top of stack is not current close bracket/paren ==> unbalanced */
            if (isEmptyDynArr(stack) || topDynArr(stack) != currentChar) {
                return 0;
            }
            /* close bracket/paren matches top of stack ==> pop top element */
            else {
                popDynArr(stack);
            }
        }
        currentChar = nextChar(s);
	}

	if (isEmptyDynArr(stack)) {
        return 1;
	}
	return 0;
}

int main(int argc, char* argv[]){

    /* avoid seg fault if no arg is given */
    if (argc >= 1) {
        char* s=argv[1];
        int res;

        printf("Assignment 2\n");

        res = isBalanced(s);

        if (res)
            printf("The string %s is balanced\n",s);
        else
            printf("The string %s is not balanced\n",s);
    }
    else {
        printf("No string was provided\n");
    }


	return 0;
}

