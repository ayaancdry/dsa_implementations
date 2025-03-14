/*
You are given n integers. Store these integers in a doubly linked list. Then, determine whether the doubly linked list is a palindrome. If it is not a palindrome, modify the list by changing the values from the last node to the middle node such that the list becomes a palindrome.
If the list is already a palindrome, print Yes.
If it is not, print No and the modified palindrome list.

Input Format
The first line contains a single integer n — the number of elements in the list.
The second line contains n space-separated integers, representing the elements of the list.

Output Format
Print Yes if the list is already a palindrome.
If the list is not a palindrome, print No on the first line, followed by the modified palindrome list on the second line.

Constraints
0 <= n <= 10^5
-10^9 <= value <= 10^9

 INPUT 	 	
 6
1 2 3 4 5 6 	
OUTPUT
No
1 2 3 3 2 1 
*/
#include <stdio.h>
#include <stdlib.h>

// Define a doubly linked list node
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;   
}Node;

Node* head = NULL; //Initialise the head

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node at the end of the list
void appendNode(int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    }
    else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp-> next = newNode;
        newNode->prev = temp;
    }
}

// solution function
int solve() {
    //empty list is a palindrome
    if (head == NULL) {
        printf("Yes\n");
    }

    Node* left = head;
    Node* right = head;

    // take the right to the end of the list
    while (right->next != NULL) {
        right = right->next;
    }

    int isPalindrome = 1;

    // check for palindrome
    while (left != right && left->prev != right) {
        if (left->data != right->data) {
            isPalindrome = 0;
            break;
        }
        left = left->next;
        right = right->prev;
    }

    /* Explaination of the above while loop conditions
    
        Left is currently at the start of the list (left = head)
        Right is currenty at the end of the list (right->next == NULL)

        The conditions for the loop to work are given as left != right and left->prev != right : 
        left != right means that when left is moving forward and right is moving backward, stop at the location where both left and right become equal. (Loop stops at left == right) (Think of any odd numbered LinkedList as an example)
        left->prev != right. This means that when left is moving forward and right is moving backward, stop at the location where left->prev becomes equal to right (Loop stops when left->prev == right), that is, Loop stops at the instant when left overtakes right, that is, the loop stops at the moment where left is just one node ahead of right. (Think of any even numbered LinkedList as an example)
    
        During the entire loop, if at any point we see that left->data is not equal to right->data, then it means that the list is NOT a palindrome
    
        To move the loop forward, the iterations are : 
        left = left->next;
        right = right->prev;
    */

    if (isPalindrome==1) {
        printf("Yes\n");
        return 0; // no need to modify as it's already a palindrome
    }
    if (isPalindrome==0) {
        printf("No\n");
    }

    // Now make a non-palindrome list into a palindrome list

    // Re-initialise both left and right to head
    left = head;
    right = head;

    // Take right to the end
    while (right->next != NULL) {
        right = right->next;
    }

    while (left != right && left->prev != right) {
        right->data = left->data;

        left = left->next;
        right = right->prev;
    }

    return 1; // to show modifications were made

}
// Function to print the doubly linked list
void printList() {
    Node* temp = head;
    if (head==NULL) {
        printf("Empty List");
    }

    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    int n;
    int value;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &value);
        appendNode(value);
    }
    if (!solve()) { 
        return 0; // If already a palindrome, leave after printing "Yes"
    }

    printList(); // Print modified palindrome list if changes were made
    return 0;
}