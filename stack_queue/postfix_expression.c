/*
Write a C program to evaluate a postfix mathematical expression. The program should validate the input, compute the result, and handle errors gracefully.

Requirements:
1. The postfix expression will contain positive integers and the operators +, -, *, /.
2. Numbers and operators in the input expression will be separated by spaces. Example: 5 1 2 + 4 * + 3 -
3. The program should evaluate the expression step-by-step and return the final result.

Input Constraints:
1. Input will consist of valid positive integers and operators only.
2. Operators supported:
   A. + (Addition)
   B. - (Subtraction)
   C. * (Multiplication)
   D. / (Integer Division)
2. Invalid input includes:
   A. Any character other than digits, operators, or spaces.
   B. Division by zero.
   C. Malformed expressions (e.g., operators without sufficient operands).
Output:
1. If the input is valid, print the evaluated result.
2. If the input is invalid, print Invalid input.

Sample Test Cases:
Example1:
Input:
5 1 2 + 4 * + 3 -
Output:
14

Example2:
Input:
4 2 8 $
Output:
Invalid input

Example3:
Input:
3 4 / 0 /
Output:
Invalid input
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Define a node for the linked list stack
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Push an element onto the stack
int push(Node **top, int value) {
    // Write the code to push an element on the top of the stack
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(newNode == NULL) {
        return 0; 
    }
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
    return 1;
}

// Pop an element from the stack
int pop(Node **top, int *value) {
    // Write the code to pop an element from the top of the stack
    if(*top == NULL) {
        return 0; // Stack underflow: not enough operands
    }
    Node *temp = *top;
    *value = temp->data;
    *top = temp->next;
    free(temp);
    return 1;
}

// Evaluate postfix expression
int evaluatePostfix(const char *expression, int *result) {
    // Write the code to evaluate the postfix expression her 
    Node *stack = NULL; // initialize an empty stack
    char exprCopy[201];
    strcpy(exprCopy, expression);  // Make a modifiable copy of the expression
    
    char *token = strtok(exprCopy, " ");
    while(token != NULL) {
        //check if the token is an operator
        if(strlen(token) == 1 && 
           (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')) {
            int op2, op1;
            //pop two operands; note: op1 is the earlier one
            if(!pop(&stack, &op2) || !pop(&stack, &op1)) {
                //malformed expression: not enough operands
                //clean up stack memory before returning error
                while(pop(&stack, &op1));
                return 0;
            }
            int tempResult;
            switch(token[0]) {
                case '+':
                    tempResult = op1 + op2;
                    break;
                case '-':
                    tempResult = op1 - op2;
                    break;
                case '*':
                    tempResult = op1 * op2;
                    break;
                case '/':
                    if(op2 == 0) {
                        while(pop(&stack, &op1));
                        return 0;
                    }
                    tempResult = op1 / op2;
                    break;
                default:
                    while(pop(&stack, &op1));
                    return 0;
            }
            if(!push(&stack, tempResult)) {
                //memory push error; clean up and fail
                while(pop(&stack, &op1));
                return 0;
            }
        } else {
            //token should be a positive integer
            int valid = 1;
            for (int i = 0; token[i] != '\0'; i++) {
                if (!isdigit(token[i])) {
                    valid = 0;
                    break;
                }
            }
            if (!valid) {
                //invalid token found; clean up the stack and return error.
                int dummy;
                while(pop(&stack, &dummy));
                return 0;
            }
            int num = atoi(token);
            if(!push(&stack, num)) {
                int dummy;
                while(pop(&stack, &dummy));
                return 0;
            }
        }
        token = strtok(NULL, " ");
    }
    
    //after processing, exactly one element should be in the stack.
    if(!pop(&stack, result) || stack != NULL) {
        //either no result found or extra operands remain -> malformed.
        int dummy;
        while(pop(&stack, &dummy));
        return 0;
    }
    
    return 1;
}

int main() {
    char expression[200];
    int result;

    fgets(expression, sizeof(expression), stdin);

    //remove trailing newline character
    expression[strcspn(expression, "\n")] = '\0';

    if (evaluatePostfix(expression, &result)) {
        printf("%d\n", result);
    } else {
        printf("Invalid input\n");
    }

    return 0;
}