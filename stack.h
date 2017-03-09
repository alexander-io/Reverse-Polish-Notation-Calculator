/**
* This is the header file that references the functionality in stack.c
* @author Alexander Harris
* @version Feb 2017
* Operating Systems, CS475
*/
// a frame holds data and a pointer to the next frame
struct Frame {
  // store the data of the frame in this variable
  double data;
  // store a pointer to the next frame in this variable
  struct Frame *next;
} Frame;

// the stack has a pointer to the head frame and an integer representing the size
struct Stack {
  struct Frame *head;
  int size;
} Stack;

double pop(struct Stack *stack);
void push(double input, struct Stack *stack);
int size(struct Stack *stack);
void initStack(struct Stack stack);
