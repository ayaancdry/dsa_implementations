/*
Given a doubly linked list, the task is to sort the doubly linked list in non-decreasing order using the quicksort.
Examples:
Input: head: 5<->3<->4<->1<->2
Output: 1<->2<->3<->4<->5
Explanation: Doubly Linked List after sorting using quicksort technique is 1<->2<->3<->4<->5
Input: head: 1<->5<->2<->3
Output: 1<->2<->3<->5
Explanation: Doubly Linked List after sorting using quicksort technique is 1<->2<->3<->5
Input: head: 0<->3<->2<->1
Output: 0<->1<->2<->3
Explanation: Doubly Linked List after sorting using quicksort technique is 0<->1<->2<->3
*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};

void append(Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);
    Node* last = *head_ref;
    if (*head_ref == nullptr) {
        *head_ref = new_node;
        return;
    }
    while (last->next != nullptr)
        last = last->next;
    last->next = new_node;
    new_node->prev = last;
}

// Utility to print list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data;
        if(head->next)
            cout << " ";
        head = head->next;
    }
    cout << endl;
}

Node* getLastNode(Node* head) {
    while (head && head->next != nullptr) {
        head = head->next;
    }
    return head;
}

void swap(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

Node* partition(Node* low, Node* high) {
    int pivot = high->data;
    Node* i = low->prev; 
    
    for (Node* j = low; j != high; j = j->next) {
        if (j->data <= pivot) {
            i = (i == nullptr) ? low : i->next;
            swap(i, j);
        }
    }
    
    i = (i == nullptr) ? low : i->next;
    swap(i, high);
    return i;
}

void quickSortRec(Node* low, Node* high) {
    if (high != nullptr && low != high && low != high->next) {
        Node* p = partition(low, high);
        quickSortRec(low, p->prev);
        quickSortRec(p->next, high);
    }
}

void quickSort(Node* head, Node* tail) {
    quickSortRec(head, tail);
}

int main() {
    int n;
    cin >> n;  
    Node* head = nullptr;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        append(&head, val);
    }
    
    if (head == nullptr) {
        return 0;
    }
    
    Node* last = getLastNode(head);
    quickSort(head, last);
    
    printList(head);
    
    return 0;
}