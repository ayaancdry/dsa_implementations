/*
Given an infix expression, Convert the given infix expression to prefix expression.
Note: Keep in mind order of precedence.
Examples:

Example 1:
Input: x+y*z/w+u
Output: ++x/*yzwu

Example 2:
Input: p+q
Output: +pq

Constraints:
1<= s.length<=30
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 30

typedef struct {
    char data[MAX];
    int top;
} Stack;

//to check precedence of operators
int precedence(char c) {
    if (c == '^') {
        return 3;  // Highest precedence
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '+' || c == '-') {
        return 1;
    }
    return 0;
}

//to convert infix to prefix
void infixToPrefix(const char *infix, char *prefix) {
    Stack s;
    int i, k = 0;
    int len = strlen(infix);

    //initialize stack
    s.top = -1;

    //reverse the infix expression for conversion to handle operators from right to left
    char reversedInfix[MAX];
    strcpy(reversedInfix, infix);
    int n = strlen(reversedInfix);
    for (i = 0; i < n / 2; i++) {
        char temp = reversedInfix[i];
        reversedInfix[i] = reversedInfix[n - i - 1];
        reversedInfix[n - i - 1] = temp;
    }

    //go through the reversed infix expression
    for (i = 0; i < len; i++) {
        char c = reversedInfix[i];
        
        //character is an operand, add it to the result
        if (isalnum(c)) {
            prefix[k++] = c;
        }
        //character is '(', push it to the stack
        else if (c == ')') {
            s.data[++(s.top)] = c;
        }
        //character is ')', pop from the stack until '(' is found
        else if (c == '(') {
            while (s.top != -1 && s.data[s.top] != ')') {
                prefix[k++] = s.data[s.top--];
            }
            s.top--; // Discard the ')'
        }
        //character is an operator, process it
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
            while (s.top != -1 && (precedence(c) < precedence(s.data[s.top])) && s.data[s.top] != '(') {
                prefix[k++] = s.data[s.top--];
            }
            s.data[++(s.top)] = c;
        }
    }

    //pop remaining operators in the stack and add them to the result
    while (s.top != -1) {
        prefix[k++] = s.data[s.top--];
    }

    prefix[k] = '\0';

    //reverse the result to get the final prefix expression
    int m = strlen(prefix);
    for (i = 0; i < m / 2; i++) {
        char temp = prefix[i];
        prefix[i] = prefix[m - i - 1];
        prefix[m - i - 1] = temp;
    }
}

// // Function to check precedence of operators
// int precedence(char c) {
//     if (c == '^') {
//         return 3;  // Highest precedence
//     } else if (c == '*' || c == '/') {
//         return 2;
//     } else if (c == '+' || c == '-') {
//         return 1;
//     }
//     return 0;
// }


int main() {
    char infix[MAX], prefix[MAX];


    scanf("%s", infix);

    infixToPrefix(infix, prefix);

    printf("%s\n", prefix);

    return 0;
}