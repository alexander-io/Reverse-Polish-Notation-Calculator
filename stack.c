/**
* This is the source file that contains the functionality for the stack
* This stack is implemented inside of the rpn.c source file.
* @author Alexander Harris
* @version Feb 2017
* Operating Systems, CS475
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 10

// a frame holds data and a pointer to the next frame
struct Frame {
  // store the data of the frame in this variable
  double data;
  // store a pointer to the next frame in this variable
  struct Frame *next;
} Frame;

// the stack has a pointer to the head frame and an integer representing the size
struct Stack {
  // store a pointer to the current head of the stack (aka the elem to be popped next)
  struct Frame *head;

  int size;
} Stack;

/**
* A constructor for the Stack type, sets the head to NULL and the initial size to 0
* @param Stack a stack to initialize
*/
void initStack(struct Stack stack){
  // init a new stack
  struct Stack newStack;
  newStack.size = 0;
  newStack.head = NULL;
}

/**
* returns the number of elements currently in the stack
* @param Stack that has the desired size
* @return int variable representing the size of the stack
*/
int size(struct Stack *stack){
  return stack->size;
}

/**
* inputs a double, allocates a new stack element,
* and pushes it onto the top of the stack
* @param double data to be stored in the stack
* @param Stack stack that needs pushing onto
*/
void push(double input, struct Stack *stack){
  // create and init a new frame for the stack, also allocate mem for the new frame
  struct Frame *newHead = (struct Frame*) malloc(sizeof(struct Frame));

  // store the data in the new frame
  newHead->data = input;

  // set the next frame to be null
  newHead->next = stack->head;

  // stack is FIFO so set the head of the stack to be the new frame
  stack->head = newHead;

  // increment stack size
  stack->size++;
}

/**
* pops off the top element fromt he stack,
* returns the stored double value,
* and deallocates it from the heap
* @param *Stack pointer to stack object
* @return double
*/
double pop(struct Stack *stack){
  if (stack->head == NULL){
    printf("\n\tyou tried popping... but either stack is empty or null stack-head error...\n");
    return -1;
  }

  // make a variable to store our head's data
  double returnData;
  // get the data of the current head, store it to return
  returnData = stack->head->data;
  // deallocate the memory used for the stackhead
  free(stack->head);
  // assign the stack-head to the next
  stack->head = stack->head->next;
  // decrement the size of the stack
  stack->size = stack->size-1;

  return returnData;
}
