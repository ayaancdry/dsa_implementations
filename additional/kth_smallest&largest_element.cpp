/*
You are given an array of N integers. Your task is to find the K-th smallest and K-th largest element in the array using the QuickSort partitioning technique.

Input Format:
The first line contains an integer N  — the number of elements in the array.
The second line contains N space-separated integers A[i]  — the elements of the array.
The third line contains an integer K  — the position of the element to find.

Output Format:
Print two space-separated integers:
The K-th smallest element.
The K-th largest element.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to partition the array
int partition(vector<int>& arr, int left, int right) {
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

// QuickSelect function
int quickSelect(vector<int>& arr, int left, int right, int k) {
    if (left <= right) {
        int pivotIndex = partition(arr, left, right);
        if (pivotIndex == k) {
            return arr[pivotIndex];
        } else if (pivotIndex > k) {
            return quickSelect(arr, left, pivotIndex - 1, k);
        } else {
            return quickSelect(arr, pivotIndex + 1, right, k);
        }
    }
    return -1;
}

int main() {
    int N, K;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];
    cin >> K;

    int kthSmallest = quickSelect(arr, 0, N - 1, K - 1);
    int kthLargest = quickSelect(arr, 0, N - 1, N - K);

    cout << kthSmallest << " " << kthLargest << endl;
    return 0;
}