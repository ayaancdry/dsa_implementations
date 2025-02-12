/* 
Given an array of elements, insert all the elements in a Linked List in sorted order. The insertion function should be called everytime you add an element to the linked list and it should be implemented in such a way that the inserted element goes to its correct position in the sorted order.
NOTE : You must NOT sort the array and then create a Linked List.

Input Format :
First line of the input contains an integer ‘n’, representing the size of the input array.
Next line contains n integers representing the elements in the array.

Output Format :
Print the elements in the sorted linked list.

Sample Test Case:
Input:
5 
3 11 9 16 15

Output:
3 9 11 15 16

*/

#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;          
    struct Node* next; 
};

// Define the LinkedList structure
struct LinkedList {
    struct Node* head; // Pointer to the head of the list
};

// Function to initialize a linked list
struct LinkedList* createLinkedList() {
    struct LinkedList* list = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    if (list != NULL) {
        list->head = NULL;
    }
    return list;
}

// Function to insert in sorted order
void insert_sorted(struct LinkedList* list, int val) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    // If the list is empty or the new value is smaller than the head value
    if (list->head == NULL || val < list->head->data) {
        newNode->next = list->head;
        list->head = newNode;
        return;
    }

    // Traverse the list to find the correct position for insertion
    struct Node* curr = list->head;
    while (curr->next != NULL && curr->next->data < val) {
        curr = curr->next;
    }

    // Insert the new node
    newNode->next = curr->next;
    curr->next = newNode;
}

// Function to print the linked list
void printLinkedList(struct LinkedList* list) {
    struct Node* curr = list->head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("NULL");
}

int main() {
    int n;

    // Read the size of the input array
    scanf("%d", &n);
    int arr[n];

    // Read the array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Create a linked list
    struct LinkedList* list = createLinkedList();

    // Insert elements into the linked list in sorted order
    for (int i = 0; i < n; i++) {
        insert_sorted(list, arr[i]);
    }

    // Print the sorted linked list
    printLinkedList(list);

    return 0;
}