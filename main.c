/**
* This is the main class to drive the reverse polish notation calculator, rpn.c
* @author Alexander Harris
* @version Feb 2017
* Operating Systems, CS475
*/

#include "rpn.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_EQUATION_INPUT 100
/*
In main.c: prompt the user for an RPN expression,
evaluate the expression and print the result.
You may assume that an expression can be no longer than 100
characters long.
*/
int main(){
  // to scan an entire line of input, fgets()
  char userInput[MAX_EQUATION_INPUT];
  char evalAnother = 'y';
  char readline[256];
  double result;

  while(evalAnother == 'y'){
    printf("\nPlease enter an equation : \n");
    // read a line from the user, store in input
		fgets(userInput, MAX_EQUATION_INPUT, stdin);

		// look for the trailing newline in the input
		// remove it and replace it with a empty space ' '
		size_t ln = strlen(userInput)-1;
		if(userInput[ln] == '\n')
			userInput[ln] = '\0';

    // call calcRPN() passing in the string of user input
    result = calcRPN(userInput);
    if (result != -1){
      printf("\nresult of calculation : %f\n", result);
    }

    printf("\nEvaluate another? (y/n):");

    if (fgets(readline, sizeof(readline), stdin) == NULL) {
      printf("Something went wrong with input.\n");
      exit(1);
    }
    // check to evaluate another
    evalAnother = readline[0];
  }
  return 0;
}
