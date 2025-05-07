/*
Write a program to implement a circular queue of non negative integers using singly  linked list and print from (second element from head, similar to index= 1 in arrays) to first element.
Stopping criteria: user inputs -1

Input:
3 4 7 8 -1
Output:
4 7 8 3


Assume queue input is never empty
Retain duplicates
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

int isEmpty(struct Queue* queue) {
    return queue->front == NULL;
}

void enqueue(struct Queue* queue, int item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = item;
    newNode->next = NULL;
    
    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
        queue->rear->next = queue->front; //circular link
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
        queue->rear->next = queue->front; //to maaintain circular link
    }
}

//to display the queue from the second element to the first element
void displayQueue(struct Queue* queue) {
    if (isEmpty(queue)) {
        return;
    }

    struct Node* temp = queue->front->next; //start from the second element
    while (temp != queue->front) { //traverse until back to the front
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", queue->front->data); //print the first element at the end
}

int main() {
    struct Queue* queue = createQueue();
    int value;
    
    while (1) {
        scanf("%d", &value);
        if (value == -1) break;
        enqueue(queue, value);
    }
    
    displayQueue(queue);
    
    return 0;
}