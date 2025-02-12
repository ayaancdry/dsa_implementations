/*
Using the stack concept, find the solution for the given string s containing just the characters '(', ')', '{', '}', '[' and ']', and determine if the input string is valid.
An input string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.
Constraints:
        1 <= s.length <= 104
        s consists of parentheses only '()[]{}'
*/

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure definition for Stack
typedef struct Stack{
    int capacity;
    int top;
    char* data;
}Stack;

// Function to create a stack
Stack *createStack(int capacity) {
    Stack* newStack = (Stack*)malloc(sizeof(Stack));
    newStack->capacity = capacity;
    newStack->top = -1;
    newStack->data = (char*)malloc((newStack->capacity)*sizeof(char));
    return newStack;
}

// Function to check if the stack is empty
bool isEmpty(Stack *stack) {
    return stack->top == -1; 
    // this function will return true if stack->top = -1, that is, if the stack is empty
}

// Function to push an element onto the stack
void push(Stack *stack, char c) {
    if (stack->top == stack->capacity-1){
        return; //stack is full
    }
    stack->top++;
    stack->data[stack->top] = c;
}

// Function to pop an element from the stack
char pop(Stack *stack) {
    if(isEmpty(stack)) {
        return -1; //stack is empty
    }
    char popped;
    popped = stack->data[stack->top];
    stack->top--;
    return popped;
}


//function to check for matching brackets
bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}


// Function to check if the input string has valid parentheses
bool isValid(char *s) {
    /*
    Logic of the problem will be : 
    - Any time you encounter an opening bracket, push it into the stack.
    - Any time you encounter any closing bracket, pop the stack, that is, pop out the last element of the stack
    - If the closing bracket & the popped element match, then it is valid. 
    - If at any case they don't match, means it's invalid.
    - For a valid parenthesis, at the end of the complete process, the stack should be empty.
    - If the stack remains non empty after completion of the procedure, then invalid parenthesis. 
    */

   int length = strlen(s);
   Stack* stack = createStack(length); 

   for (int i=0; i<length; i++) { // start processing one char at a time
    char current;
    current = s[i];
        if (current == '(' || current =='{' || current =='[') { // encounter an opening bracket
            push(stack, s[i]);
        }
        else {
            char topElement = pop(stack);
            if (!isMatchingPair(topElement, current)) {
                return false;
            }
            if (isEmpty(stack)) {
                return false; //if stack is empty, there is no matching opening bracket
            }
        }
   }
    bool valid = isEmpty(stack); //return true if stack is empty at the end
    free(stack->data); 
    free(stack); 
    return valid;
}
int main() {
    char s[105];
    
    // Input handling string of parentheses
    scanf("%104s", s);

    // Function call
    if (isValid(s))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
