/*
Question: Remove K Digits to Form the Largest Number
Problem Statement
Given a string num representing a non-negative integer num, and an integer k, remove exactly k digits from num such that the resulting number is as large as possible. If removing all the digits results in an empty string, return "0".
Example 1
Input: num = "1432219", k = 3
Output: "4329"
Explanation:.
Remove the three digits 1, 2, and 1  to form the new number 4329, which is the largest possible number you can create after 3 removals.
Example 2
Input: num = "10200", k = 1
Output: "2000"
Explanation:
If we remove the 1, we get "0200". After removing leading zeros, the number is "2000".
Notice that removing any other digit (like removing 0 from "10200") would not yield as large a number.
Example 3
Input: num = "10", k = 2
Output: "0"
Explanation:
After removing both digits, you are left with an empty string, which should be interpreted as "0".
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void removeKdigitsToFormLargest(const char* num, int k, char* result) {
    char stack[100001];
    int top = 0;
    int len = strlen(num);

    for (int i = 0; i < len; i++) {
        char c = num[i];
        while (top > 0 && stack[top - 1] < c && k > 0) {
            top--;
            k--;
        }
        stack[top++] = c;
    }

    //remove remaining k digits from the end
    top -= k;
    if (top < 0) {
        top = 0;
    }

    //handle case where all digits are removed
    if (top == 0) {
        strcpy(result, "0");
        return;
    }

    stack[top] = '\0';

    //skip leading zeros
    int start = 0;
    while (start < top && stack[start] == '0') {
        start++;
    }

    if (start == top) {
        strcpy(result, "0");
    } else {
        strncpy(result, stack + start, top - start);
        result[top - start] = '\0';
    }
}

int main() {
    char num[100001]; //buffer for input number
    int k;

    scanf("%s %d", num, &k);

    // Buffer to store the final largest number
    char largestNumber[100001];

    // Call the function to compute the largest number
    removeKdigitsToFormLargest(num, k, largestNumber);

    // Print the result
    printf("%s\n", largestNumber);

    return 0;
}