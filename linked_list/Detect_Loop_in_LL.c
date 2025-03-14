/* 
Problem:
You are given linked list. Your task is to determine whether the list contains a loop.
A loop exists if the last node of the linked list points back to any node within the list, creating a cycle.

Input Format:

The first line contains the number of nodes in the linked list.

The second line contains a space-separated list of integers, where each integer represents the data of a node in the linked list.

The third line contains an integer pos, which indicates the index (0-based) of the node where the tail’s next pointer should connect. If pos = -1, the tail’s next pointer is NULL.

Output Format:
Print true if a loop exists in the linked list.
Print false if no loop exists.

Sample Test Case:
Input:
5
1 2 3 4 5
2

Output:
true

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


// Function to insert a new node at the end of the linked list
void insert(Node** head, int data) {
    Node* newNode = createNode(data);
    Node* temp = *head;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to create a loop in the linked list by linking the last node to the given position
void createLoop(Node* head, int pos) {

}

// Function to detect if there is a loop in the linked list using Floyd's Cycle Detection Algorithm
int hasLoop(Node* head) {

}

int main() {
    int n, pos;
    scanf("%d", &n);

    struct Node* head = NULL;
    
    // Insert nodes into the linked list
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        insert(&head, data);
    }

    scanf("%d", &pos);  // Position for loop creation
    createLoop(head, pos);

    // Check if a loop exists and print the result
    if (hasLoop(head)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
