/* 
Problem : You are given a queue containing n elements and an integer K. Your task is to reverse the first K elements of the queue while leaving the rest of the queue unchanged. If K is greater than or equal to n, reverse the entire queue.

Input Format:
An integer n representing the number of elements in the queue.
A space-separated sequence of integers representing the elements of the queue (if n > 0).
An integer K representing the number of elements to reverse.

Output Format:
If the queue is empty (n = 0), print "Empty Queue".
Otherwise, print the queue after reversing the first K elements.

Sample 1
input:
10
10 20 30 40 50 60 70 80 90 100
5

output:
50 40 30 20 10 60 70 80 90 100

Sample 2

input:
0

output:
Empty Queue
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum size of the queue

// Structure to represent a queue
typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

// Structure to represent a stack
typedef struct {
    int items[MAX];
    int top;
} Stack;

void initstack(Stack*s)
{
    s->top=-1;
}
// Function to initialize the queue
void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == -1;
}

// Function to enqueue an element
void enqueue(Queue* q, int value) {
    //write your code here
    if (isEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear++;
    }
    
    q->items[q->rear] = value;
}

// Function to dequeue an element
int dequeue(Queue* q) {
    //write your code here
    if (isEmpty(q)) {
       
        return -1; 
    }
    int dequeuedValue = q->items[q->front];
    if (q->front == q->rear) { 
        // Reset queue when last element is dequeued
        q->front = q->rear = -1;
    }
    else {
        q->front++;
    }
    
    return dequeuedValue;
}

void push(Stack* s, int value) {
    if (s->top == MAX - 1) {
        
        return;
    }
    s->items[++s->top] = value;
}

// Function to pop an element from the stack
int pop(Stack* s) {
    if (s->top == -1) {
        
        return -1;
    }
    return s->items[s->top--];
}
// Function to reverse the first K elements of a queue
void reverseQueueFirstKElements(int K, Queue* q) {
    //write your code here
    Stack s;
    initstack(&s);
    
    if(K>q->rear+1)
    {
       for (int i = 0; i<=q->rear; i++) {
        push(&s, dequeue(q));
       }
        
        while (s.top != -1) {
        enqueue(q, pop(&s));
        }
     return;
     
    }else{
        for (int i = 0; i < K; i++) {
        push(&s, dequeue(q));
    }
    while (s.top != -1) {
        enqueue(q, pop(&s));
    }
    int remaining = (q->rear - q->front + 1) - K;
    for (int i = 0; i < remaining; i++) {
        enqueue(q, dequeue(q));
    }
    }
    
}

// Function to display the queue
void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Empty Queue\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

// Driver code
int main() {
    Queue q;
    initQueue(&q);
    int n, value, K;

    // Read the number of elements to add to the queue
    // printf("Enter the number of elements to add to the queue: ");
    scanf("%d", &n);


    // Read and enqueue elements to the queue
    // printf("Enter the elements to add to the queue:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(&q, value);
    }

    // Read the value of K (number of elements to reverse)
    // printf("Enter the number of elements to reverse (K): ");
    scanf("%d", &K);

    // Display the original queue
    printf("Original Queue: ");
    displayQueue(&q);

    // Reverse the first K elements
    reverseQueueFirstKElements(K, &q);

    // Display the queue after reversal
    printf("Queue after reversing  elements: ");
    displayQueue(&q);

    return 0;
}