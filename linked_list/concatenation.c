/*
Given heads of two linked lists, concatenate the linked lists by connecting both of them. Connect the head of linked list 2 with the last node of linked list 1, i.e. concatenate the linked lists to create one big list. 

If both lists are NULL or 0, then the outcome should be EMPTY.

Input Format:
First line contains two integers n and m, the lengths of the two linked lists.
Second line contains n integers, values for linked list 1
Third line contains m integers, values for linked list 2

Output Format:
Print the resulting big linked list


Sample Test Case:
Input:
2 3
1 2
3 4 5

Output:
1 2 3 4 5 NULL
*/

#include <stdio.h>
#include <stdlib.h>

// Define a node structure
typedef struct Node {
    int val;
    struct Node* next; // Pointer to the next node
} Node;

// Function to create a new node
Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a value at the end of linked list
void insert(Node** head, int val) {
    //create the node which has to be added. 
    Node* newNode = createNode(val);
    //newNode is also a pointer to the new node. It is of datatype Node*. When I create "newNode", it will look something like : newNode --> [ data : val | next : NULL]

    //check if the list is empty
    //*head is the pointer to the first node (*head contains the address of the first node)
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    //if the list is not empty : 
    //This means that *head is pointing to the first node
    Node* temp = *head; //create a temporary pointer to the first node
    while (temp->next != NULL) {
        temp = temp->next;  //keep moving to the next node until you reach the last node (for last node, next will be NULL)
    }
    temp->next = newNode;
}

// Function to print the linked list
void printLinkedList(Node* head) {
    if (head == NULL) {
        printf("List is Empty\n");
    }

    Node* temp = head; //initialise a temp which points to the first node initially
    int l = 0; //counter to track number of zeroes

    while (temp->next != NULL) {
        printf("%d ", temp->val);
        if (temp->val == 0) {
            l++;
        }
        temp = temp->next;
    }
    printf("NULL\n");
}
// In the above function, in the while loop, temp->next != NULL wasnot used because this condition won't allow us to print the value of the last node. The printing will stop at the second last node. 

// Function to concatenate two linked lists
Node* concatenate(Node* head1, Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    Node* temp = head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
    return head1;
}

int main() {
    Node* l1 = NULL;
    Node* l2 = NULL;

    int n, m, a;
    // Input number of elements for the first and second linked list
    scanf("%d %d", &n, &m);

    // Input elements for the first linked list
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        insert(&l1, a);
    }
    
    // Input elements for the second linked list
    for (int i = 0; i < m; i++) {
        scanf("%d", &a);
        insert(&l2, a);
    }
    
    // Concatenate the two linked lists
    l1 = concatenate(l1, l2);

    // Print the concatenated linked list
    printLinkedList(l1);

    return 0;
}