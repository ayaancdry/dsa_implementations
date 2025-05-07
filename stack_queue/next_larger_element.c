/* 
Given an array of integers nums of size n, find the next greater element for each element in the array. The next greater element for an element nums[i] is the first element to the right of nums[i] that is strictly greater than it. If there is no such element, return -1 for that position. You need to return an array result where result[i] contains the next greater element for nums[i]. Your solution must run in O(n) time complexity.
*/
#include <stdio.h>
#include <stdlib.h>

void nextGreaterElement(int* nums, int n, int* result) {
    if (n == 0) return;  //empty array case

    int stack[n];
    int top = -1;

    for (int i = n - 1; i >= 0; i--) {
        //elements from stack that are <= current element
        while (top != -1 && stack[top] <= nums[i]) {
            top--;
        }
        //if stack is empty, no greater element found
        if (top == -1) {
            result[i] = -1;
        } else {
            result[i] = stack[top];
        }
        //push current element to stack
        stack[++top] = nums[i];
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int* nums = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int* result = (int*)malloc(n * sizeof(int));
    nextGreaterElement(nums, n, result);

    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(nums);
    free(result);
    return 0;
}