/*
Write a program to perform the basic operations of a stack such as push(), pop(), peek(), isFull(), isEmpty(). Assume stack is of size 100 integers. The program should take input of a given n number of integers and push them into the stack and then perform the operations in the order mentioned below.
Input Format:
	N 1, 2, 3, ..n integers
Output Format:
	Output of peek(), printWholeStack(), pop(), isFull(), and isEmpty() in a new line:
Example:
	Input: 5
        15 123 62 10 44
	Output: 
		44
		44 10 62 123 15
		44
		0 // isFull() returns 1 if full, 0 otherwise
		0 // isEmpty() returns 1 if empty, 0 otherwise
*/

#include <stdio.h>

#define MX_SIZE 1000

typedef struct {
    int top; //index of the top element of the stack
    int v[MX_SIZE]; //array to store the elements of the stack
} Stack;

// Initialize the stack
void initStack(Stack* s) {
    s->top = -1;
    //when initialising a empty stack, the index of the top is set to -1. This is because now when the first element will be added, the index of the first element will become (-1) + 1 = 0. Then 0+1 = 1, then 2 and so on..
}

// Check if the stack is empty
int isEmpty(Stack* s){
    //empty means the top index is still -1
    if (s->top==-1) {
        return 1;
    }
    else {
        return 0;
    }
}

// Check if the stack is full
int isFull(Stack* s){
    //index of the top is maxsize - 1. 
    if (s->top == MX_SIZE - 1) {
        return 1;
    }
    else {
        return 0;
    }
}

// Return the top element without removing it
int peek(Stack* s){
    //if stack is empty return error -1
    if (isEmpty(s)) {
        return -1;
    }
    //otherwise return the top element of the stack
    return s->v[s->top];
}

// Remove and return the top element
int pop(Stack* s){
    if(s->top == -1) {
        return -1;    
    }
    int popped = s->v[s->top];
    s->top--; //reduce the top by 1 because one element has been removed
    return popped;
}

// Add an element to the top of the stack
int push(Stack* s, int data){
    
    //if stack is full, return error -1
    if (isFull(s)) {
        return -1;
    }

    //otherwise
    s->top++; //first increment top so that the new element which will be added doesn't overwrite the current top element
    s->v[s->top] = data;
    return 1;    
}

// Print all elements in the stack
void printWholeStack(Stack* s){
    //print the elements
    for (int i = s->top; i>=0; i--) {
        printf("%d ", s->v[i]);
    }
    printf("\n");
}

int main(){
    int n, x;
    scanf("%d", &n);
    Stack s;
    initStack(&s);
    for(int i =0; i<n; i++){
        scanf("%d", &x);
        push(&s, x);
    }
    x = peek(&s);
    printf("%d\n", x);
    printWholeStack(&s);
    x = pop(&s);
    printf("%d\n", x);
    printf("%d\n", isFull(&s));
    printf("%d\n", isEmpty(&s));
    return 0;
}


