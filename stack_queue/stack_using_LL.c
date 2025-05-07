/* 
Write a program to implement a stack using a linked list. The stack should have operations like push(), pop(), top(), isEmpty(). 
Queries:
1 x will represent to push integer x to the stack
2 will represent to pop the top element
3 will represent to print the stack top
4 will represent to print the entire stack

Input Format:
Number of queries q
q lines representing the queries

For example:
Input:
5
1 10
1 20
3
2
4

5 indicates the number of queries
1 10 indicates push 10
1 20 indicates push 20
3 indicates print top element of the stack, which is 20
2 indicates pop the top element, that is, pop 20
4 indicates printing the entire stack

Note: Pop does not require printing the topmost element. You have to remove it. For an empty stack, you have to print "Stack is empty\n"
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for a node in the stack
struct Node {
    int data;
    struct Node* next;
};

// Structure for the stack
struct Stack {
    struct Node* topNode;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}

// Function to initialize stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (stack != NULL) {
        stack->topNode = NULL;
    }
    return stack;
}

// Function to check if stack is empty
bool isEmpty(struct Stack* stack) {
    return (stack->topNode == NULL);
}

// Function to push an element onto the stack
void push(struct Stack* stack, int x) {
    struct Node* newNode = createNode(x);
    if (newNode != NULL) {
        newNode->next = stack->topNode;
        stack->topNode = newNode;
    }
}

// Function to pop the top element from the stack
void pop(struct Stack* stack) {
    if (!isEmpty(stack)) {
    struct Node* temp = stack->topNode;
    stack->topNode = stack->topNode->next;
    free(temp);
    }
}

// Function to get the top element of the stack
int top(struct Stack* stack) {
    if (!isEmpty(stack)) {
    return stack->topNode->data;
    }
    return -1;
}

// Function to print all elements of the stack
void printStack(struct Stack* stack) {
    if (isEmpty(stack)) {
    printf("Stack is empty\n");
    return;
    }
    struct Node* current = stack->topNode;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function to process queries
int main() {
    struct Stack* stack = createStack();
    int q;
    scanf("%d", &q); // Number of queries
    while (q--) {
        int query;
        scanf("%d", &query);
        
        if (query == 1) {
            //push operation
            int x;
            scanf("%d", &x);
            push(stack, x);
        }
        else if (query == 2) {
            //pop operation
            pop(stack);
        }
        else if (query == 3) {
            //print the top element
            int topElement = top(stack);
            if (topElement == -1) {
                printf("Stack is empty\n");
            } else {
                printf("%d\n", topElement);
            }
        }
        else if (query == 4) {
            //print the stack
            printStack(stack);
        }
    }
    return 0;
}