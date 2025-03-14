/* 
Problem: Given a doubly linked list, insert a specified number in the middle of the list..

Input Format:
First line: An integer, n, representing the total number of elements in the doubly linked list.
Second line: n integers, representing the values of the doubly linked list.
Third line: An integer, representing the value of the new node to be inserted.
Output Format: Print the resulting doubly linked list after the insertion, with each element followed by <-> and ending with NULL.

Sample Test Case:
Input:
4 
1 2 3 4  
5

Output:
1 <-> 2 <-> 5 <-> 3 <-> 4 <-> NULL


Input:
5 
1 2 3 4 6 
5

Output:
1 <-> 2 <-> 3 <-> 5 <-> 4 <->6<-> NULL

*/

#include <stdio.h>
#include <stdlib.h>

// Define a structure for the doubly linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}

// Function to insert a node in the middle of the doubly linked list
void insertMiddle(struct Node** head, int data,int n) {


    
    // Find the middle node


    

    
}

// Function to print the doubly linked list
void printList(struct Node* head) {
    if (head==NULL) {
        printf("List if Empty\n");
    }
    struct Node* temp;
    temp = head;

    while (temp != NULL) {
        printf("%d", temp->data);

        if(temp->next != NULL) {
            printf(" <-> ");
        }
    temp = temp->next;
    }
    printf(" <-> NULL");
}

int main() {
    int n, data;
    
    // Input number of nodes in the doubly linked list
    scanf("%d", &n);
    
    struct Node* head = NULL;
    
    // Input the elements of the doubly linked list
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        struct Node* new_node = newNode(data);
        if (head == NULL) {
            head = new_node;
        } else {
            struct Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = new_node;
            new_node->prev = temp;
        }
    }
    
    // Input the value to be inserted in the middle
    scanf("%d", &data);
    
    // Insert the new node in the middle
    insertMiddle(&head, data,n);
    
    // Print the resulting doubly linked list
    printf("Updated List: \n");
    printList(head);
    
    return 0;
}
