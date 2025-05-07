/*
Problem Statement: Given an array of integers, find the K largest elements in the array using a min-heap.

Input Format:
The first line contains two space-separated integers N and K, where N is the size of the array and K is the number of largest elements to find.
The second line contains N space-separated integers representing the elements of the array.

Output Format:
Print K space-separated integers representing the K largest elements in the array in descending order.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int main() {
    int N, K;
    std::cin >> N >> K;
    std::vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> arr[i];
    }

    // Build min heap with first k elements
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap(arr.begin(), arr.begin() + K);

    // For remaining elements, if element is larger than top, remove top and add element
    for (int i = K; i < N; ++i) {
        if (arr[i] > minHeap.top()) {
            minHeap.pop();
            minHeap.push(arr[i]);
        }
    }

    // Extract all elements from heap
    std::vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }

    // Reverse to get descending order
    std::sort(result.rbegin(), result.rend());

    // Print result
    for (int i = 0; i < K; ++i) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}