/**
* This is the source file that contains the functionality for the reverse polish notation calculator.
* @author Alexander Harris
* @version Feb 2017
* Operating Systems, CS475
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "stack.h"

/**
* funciton to conduct addition on two operands
* @param double representing the first operand
* @param double representing the second operand
* @return double the value result of the operation
*/
double addition(double op1, double op2){
  return op1+op2;
}

/**
* function to conduct subtraction on two operands
* @param double representing the first operand
* @param double representing the second operand
* @return double the value result of the operation
*/
double subtraction(double op1, double op2){
  return op2-op1;
}
/**
* function to conduct multiplication on two operands
* @param double representing the first operand
* @param double representing the second operand
* @return double the value result of the operation
*/
double multiplication(double op1, double op2){
  return op1*op2;
}
/**
* function to conduct division on two operands
* @param double representing the first operand
* @param double representing the second operand
* @return double the value result of the operation
*/
double division(double op1, double op2){
  return op2/op1;
}

/**
* function to conduct exponent on two operands
* @param double base
* @param double exponent
* @return double the value result of the operation
*/
double powr(double op1, double op2){
  return pow(op2, op1);
}

/**
* work-horse function to take user input in string form,
* parse the string of user input for tokens,
* implement the reverse polish notation calculation using
* a linked list implementation of a stack,
* and to return a double representing the resulting value of the operation
* @param takes a stirng of user input
* @return returns a double representing the result of the reverse polish notation calculation
*/
double calcRPN(char *userInput){
  char *delimeter = " ";
  // user strstr() to parse userinput for the delimeters,
  if (strstr(userInput,"\t")){
    delimeter ="\t";
  } else if (strstr(userInput,"\n")){
    delimeter ="\n";
  }

  // declare a variable to store the result of the RPN calculatin
  double result = -1;

  // initialize a stack to store our calculator inputs
  struct Stack s = {.head = NULL, .size = 0};
  initStack(s);

  // declare a variable to store the length of each token
  int token_length;

  // make the delimeter, assign it to an empty space
  // const char delimeter[2] = " ";

  // token used to store each delimited value
  char *token;

  // strtok() to tokenize a string
  token = strtok(userInput, delimeter);

  // while the token isn't null
  while(token!=NULL){
    // init token_length to zero
    token_length = 0;

    // get the length of the token, store in token_length
    while(token[token_length]){token_length++;}

    // check if the token is a digit or an operand
    if (isdigit(token[0])){

      // TESTPRINTING
      // if token is a digit, push  it onto the stack
      // printf("\nfound a digit!\n");
      // printf("\npushing digit : %c onto the stack\n", token[0]);

      // push digit onto stack, but also use atof() to convert char to double
      push(atof(&token[0]), &s);

    } else if (ispunct(token[0])){
      // printf("\nfound a punct!\n");
      if (s.size<2){
        // if the token is a punctuation and there's less than 2 frames in stack,
        // then tell the user they entered too many operators
        // generate error and exit
        printf("\n\nError : not polish notation or too many operators\n");
        return -1;
      } else {
        // pop two operands off of the stack
        double operand1, operand2;
        operand1 = pop(&s);
        operand2 = pop(&s);

        // apply the current operator to the numbers
        if (token[0] == '+'){
          // call addition function
          result = addition(operand1, operand2);
        } else if (token[0] == '-'){
          // call the subtraction function
          result = subtraction(operand1, operand2);
        } else if (token[0] == '*'){
          // call the multiplication function
          result = multiplication(operand1, operand2);
        } else if (token[0] == '/'){
          // catch divide by zero
          if (operand1 == 0 ){
            printf("\nError :  divide by zero\n");
            return -1;
          }
          // call the division function
          result = division(operand1, operand2);
        } else if (token[0] == '^'){
          // call the pow function referenced in math.h
          result = powr(operand1, operand2);
        }

        // TESTPRINTING
        // printf("\npushing result : %f onto stack\n", result);

        // push results onto the stack
        push(result, &s);
      }
    }
    // reset the token
    token = strtok(NULL, delimeter);
  }

  // if the stack size is still greater than 1, something went wrong,
  if (s.size > 1){

    // to determine whether the user entered too many operands or operators, first declare counters
    int i = 0, num_operands = 0, num_operators = 0;

    // pop all of the remaining frames off the stack, and increment our counters for operands and operators
    while (i<s.size){
      if(isdigit(pop(&s))){
        num_operands++;
      } else if (ispunct(pop(&s))){
        num_operators++;
      }
    }

    // determine whether there are too many operands or too many operators
    if (num_operands>=num_operators){
      printf("\nError : too many operands\n");
      return -1;
    } else if (num_operands<num_operators){
      printf("\nError : too many operators\n");
      return -1;
    } else {return -1;}
  } else {
    // else, pop the last frame from the stack, that's the result of the calculating
    return pop(&s);
  }
  return -1;
}
