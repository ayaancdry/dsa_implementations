/*
Implement the Quick Sort algorithm to sort an array of integers in ascending order. You can use any partitioning scheme of your choice.

Input Format:
The first line contains an integer n (1<=n<=10^5), the number of elements in the array.
The second line contains n space-separated integers (-10^9<=A[I]<=10^9), representing the elements of the array.

Output Format:
Print the sorted array as space separated integers in ascending order.

Sample Input 1:
5
3 6 8 10 1

Sample Output 1:
1 3 6 8 10

Sample Input 2:
7
9 -2 7 5 3 0 4

Sample Output 2:
-2 0 3 4 5 7 9
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to swap two elements
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function to partition the array
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // Choose the pivot element
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);  // Swap arr[i] and arr[j]
        }
    }
    swap(arr[i + 1], arr[high]);  // Swap arr[i+1] and arr[high]
    return i + 1;
}

// Quick Sort function
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    quickSort(arr, 0, n - 1);
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
