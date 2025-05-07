/*
Given an array arr[] of rope lengths, connect all ropes into a single rope with the minimum total cost. The cost to connect two ropes is the sum of their lengths.

Example 1:

Input: arr[] = [4,3,2,6]
Output: 29

Explanation:
We can connect the ropes in the following ways:
1) First, connect the ropes with the length 2 and 3. Which makes the array [4,5,6]. Cost of this operation 2+3=5.
2) Now connect ropes of lengths 4 and 5. Which makes the array [9,6]. Cost of this operation 4+5=9.
3) Finally connect the two ropes and all ropes have connected. Cost of this operation 9+6=15. 
Total cost is the optimized cost for connecting ropes.

Other ways of connecting ropes would always have some or morecost. For example, if we connect 4 and 6 first (we get three rope of 3,2, and 10), then connect 10 and 3 (we get two ropes of 13 and 2). Finally we connect 13 and 2. Total cost in this way is 10+13+15=38.

Example 2:

Input: arr[] = [10]
Output: 0

Explanation:
Since there is only one rope, no connections are needed, so the cost is 0.

Approach:

The idea is to connect the smallest two ropes first, as the lengths of the ropes that are picked early are included more than once in the total cost. This approach is similar to the concept used in Huffman Coding, where the smaller elements are combined earlier, which results in a smaller cost for subsequent operations.
To implement the idea, use a min-heap (priority queue) and push all elements into it. While the heap contains more than one element, repeatedly extract the two smallest values, add them, and insert the sum back into the heap. Maintain a variable to track the total cost, incrementing it by the sum of the extracted values at each step. Once the total process is complete, return the total cost.

Time Complexity: 
O (n log n), where n is the size of the array. Each insertion or deletion in the heap takes O (log n)

Space Complexity:
O(n), for sorting all elements in the heap.

*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int minCostToConnectRopes(vector<int>& ropes) {
    priority_queue<int, vector<int>, greater<int>> minHeap(ropes.begin(), ropes.end());
    int totalCost = 0;

    cout << "Initial Min-Heap: ";
    for (int r : ropes) cout << r << " ";
    cout << "\n";

    while (minHeap.size() > 1) {
        // Extract the two smallest ropes
        int first = minHeap.top();
        minHeap.pop();
        int second = minHeap.top();
        minHeap.pop();

        // Calculate the cost and update total cost
        int cost = first + second;
        totalCost += cost;

        // Insert the combined rope back into the heap
        minHeap.push(cost);

        cout << "\nConnecting ropes " << first << " and " << second << " with cost " << cost << endl;
        cout << "Updated Min-Heap: ";
        priority_queue<int, vector<int>, greater<int>> tempHeap = minHeap;
        while (!tempHeap.empty()) {
            cout << tempHeap.top() << " ";
            tempHeap.pop();
        }
        cout << "\n";
    }

    return totalCost;
}

int main() {
    int n;
    cout << "Enter number of ropes: ";
    cin >> n;
    
    vector<int> ropes(n);
    cout << "Enter the lengths of the ropes: ";
    for (int i = 0; i < n; i++) {
        cin >> ropes[i];
    }

    int totalCost = minCostToConnectRopes(ropes);
    cout << "\nMinimum total cost to connect all ropes: " << totalCost << endl;
    return 0;
}
