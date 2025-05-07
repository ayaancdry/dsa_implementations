/*
Priority Queue with Decrease Priority Operation
Implement a priority queue using a max-heap. The priority of an element is determined by its value. In addition to the standard insertion and extraction operations, you must support decreasing the priority of a given element.
Operations:
Insertion (Operation 1, p):
Insert an element with value p into the priority queue.
Extraction (Operation 2):
Remove and return the element with the highest priority (i.e., the maximum value).
If the priority queue is empty during an extraction, output -1.
Decrease Priority (Operation 3, p, d):
Decrease the priority of an element with value p by d units.
If after decreasing, the new value is less than or equal to 0, remove that element from the priority queue.
If the element p is not found, ignore the operation.
Note: Assume that all inserted values are unique for simplicity.
Input Format:
The first line contains an integer n representing the total number of operations.
Each of the next n lines contains an operation:
For insertion: 1 p
For extraction: 2
For decrease priority: 3 p d
Output Format:
For every extraction operation (operation 2), print the extracted element’s value. If the priority queue is empty when an extraction is attempted, print -1.

Sample input:
8    // total number of operations
1 7    //  1 is for push operation and 7 is the value to be inserted
1 3    // 1 is for push operation and 7 is the value to be inserted
2       // Operation type 2: Extraction. Remove and print the highest value from the priority queue
1 12
2
1 6
3 6 2   // Operation type 3: Decrease Priority. Find the element with value 6 and decrease its value by 2. The new value becomes 4. 
2

Output
7 
12 
4
*/
#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
private:
    vector<int> heap; // Max-Heap

    // Swap two elements in the heap
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // Heapify up: Maintain max-heap property after insertion
    void heapify_up(size_t index) {
        while (index > 0) {
            size_t parent = (index - 1) / 2;
            if (heap[index] > heap[parent]) {
                swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    // Heapify down: Maintain max-heap property after extraction or update
    void heapify_down(size_t index) {
        size_t largest = index;
        size_t left = 2 * index + 1;
        size_t right = 2 * index + 2;

        if (left < heap.size() && heap[left] > heap[largest]) {
            largest = left;
        }
        if (right < heap.size() && heap[right] > heap[largest]) {
            largest = right;
        }
        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapify_down(largest);
        }
    }

public:
    // Insert an element into the priority queue
    void push(int value) {
        heap.push_back(value);
        heapify_up(heap.size() - 1);
    }

    // Extract the element with the highest priority
    int pop() {
        if (heap.empty()) {
            return -1; // Priority queue is empty
        }

        int maxVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapify_down(0);
        return maxVal;
    }

    // Decrease the priority of an element by d units
    void decreasePriority(int value, int d) {
        // Find the index of the element with the given value
        int index = -1;
        for (size_t i = 0; i < heap.size(); ++i) {
            if (heap[i] == value) {
                index = i;
                break;
            }
        }

        // If element is not found, ignore the operation.
        if (index == -1) return;

        // Decrease its value
        heap[index] -= d;

        // If the new value is <= 0, remove the element from the heap
        if (heap[index] <= 0) {
            heap[index] = heap.back(); // Replace with the last element
            heap.pop_back();
            if (index < heap.size()) heapify_down(index); // Fix heap
        } else {
            // Since priority decreased, it might need to move down
            heapify_down(index);
        }
    }
};

int main() {
    PriorityQueue pq;
    int n;
    cin >> n;

    vector<int> outputs; // To store the output of pop operations

    while (n--) {
        int op;
        cin >> op;
        if (op == 1) {
            int p;
            cin >> p;
            pq.push(p);
        } else if (op == 2) {
            outputs.push_back(pq.pop());
        } else if (op == 3) {
            int p, d;
            cin >> p >> d;
            pq.decreasePriority(p, d);
        }
    }

    // Print all outputs after processing all operations
    for (int output : outputs) {
        cout << output << "\n";
    }

    return 0;
}
