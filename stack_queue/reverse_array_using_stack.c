/*
Problem: Reverse an array using Stack
Examples:
Input: arr[] = { 10, 20, 30, 40, 50 } 
Output: 50 40 30 20 10 
Explanation: Reversing the array modifies arr[] to { 50, 40, 30, 20, 10 } Therefore, the required output is 50 40 30 20 10.
Input: arr[] = { 1 } 
Output: 1
*/

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure of stack
struct Stack {

    // Stores index of top element of a stack
    int top;

    // Stores maximum count of elements stored in a stack
    unsigned capacity;

    // Stores address of array element
    int* array;
};

//Rest of the code
void reverseArray(int arr[], int n) {
    for (int i=0; i<n/2; i++) {
        int temp;
        temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
    
    //print the reversed array
    printf("Reversed array: ");
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    // Input array size
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid array size. Exiting program.\n");
        return 0;
    }

    int* arr = (int*)malloc(n * sizeof(int));

    // Input array elements
    printf("Enter %d elements of the array: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Reverse the array
    reverseArray(arr, n);

    // Free the allocated memory
    free(arr);

    return 0;
}