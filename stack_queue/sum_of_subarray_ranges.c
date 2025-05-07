/* 
You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.

Return the sum of all subarray ranges of nums.

A subarray is a contiguous non-empty sequence of elements within an array.

Note: You are required to solve this problem using stacks.
Expected Time  Complexity is O(N) . 

Constraints:

1 <= nums.length <= 1000
-109 <= nums[i] <= 109

Input:
The first line contains an integer n, representing the size of the array.
The second line contains n space-separated integers, representing the elements of the array.
Output:
A single integer representing the sum of all subarray ranges.
Sample Input-1
3  
1 2 3  
Sample Output-1
4  
*/
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the sum of subarray ranges
long long subArrayRanges(int* nums, int numsSize) {
    //decreasing stack for max
    long long maxSum = 0;
    //increasing stack for min
    long long minSum = 0;
    
    //array to store the next and pichla smaller and greater indices
    int* prevGreater = (int*)malloc(numsSize * sizeof(int));
    int* nextGreater = (int*)malloc(numsSize * sizeof(int));
    int* prevSmaller = (int*)malloc(numsSize * sizeof(int));
    int* nextSmaller = (int*)malloc(numsSize * sizeof(int));

    //stack to find pichla and agla greater elements
    int* stack = (int*)malloc(numsSize * sizeof(int));
    int top = -1;

    //pichla aur agla greater elements for each index
    for (int i = 0; i < numsSize; i++) {
        prevGreater[i] = -1;  // Default to no previous greater
        nextGreater[i] = numsSize; // Default to no next greater
    }

    //decreasing stack for previous greater
    for (int i = 0; i < numsSize; i++) {
        while (top != -1 && nums[stack[top]] < nums[i]) {
            nextGreater[stack[top]] = i; // Update the next greater index
            top--;
        }
        if (top != -1) {
            prevGreater[i] = stack[top]; // Update the previous greater index
        }
        stack[++top] = i;
    }

    //reset stack and find previous smaller and next smaller elements
    top = -1;
    for (int i = 0; i < numsSize; i++) {
        prevSmaller[i] = -1;  // Default to no previous smaller
        nextSmaller[i] = numsSize; // Default to no next smaller
    }

    //monotonic increasing stack for previous smaller
    for (int i = 0; i < numsSize; i++) {
        while (top != -1 && nums[stack[top]] > nums[i]) {
            nextSmaller[stack[top]] = i; // Update the next smaller index
            top--;
        }
        if (top != -1) {
            prevSmaller[i] = stack[top]; // Update the previous smaller index
        }
        stack[++top] = i;
    }

    //calculate the sum of subarray ranges
    for (int i = 0; i < numsSize; i++) {
        // For maximum: (i - prevGreater[i]) * (nextGreater[i] - i) will give us the count of subarrays where nums[i] is the maximum
        maxSum += (long long)(i - prevGreater[i]) * (long long)(nextGreater[i] - i) * nums[i];
        // For minimum: (i - prevSmaller[i]) * (nextSmaller[i] - i) will give us the count of subarrays where nums[i] is the minimum
        minSum += (long long)(i - prevSmaller[i]) * (long long)(nextSmaller[i] - i) * nums[i];
    }

    // The result is the difference between maxSum and minSum
    return maxSum - minSum;
}

int main() {
    int numsSize;

    scanf("%d", &numsSize);

    int* nums = (int*)malloc(numsSize * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        scanf("%d", &nums[i]);
    }

    long long result = subArrayRanges(nums, numsSize);
    printf("%lld\n", result);

    return 0;
}