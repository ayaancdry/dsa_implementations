/*
Write a C program to delete the nth element of a queue.First it checks whether the queue is empty or not. Then it checks if the given position is valid or not. If the given position is valid, it deletes the first n-1 elements, then deletes the nth element by calling the dequeue() function.
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int items[MAX];
    int front, rear, size;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

int isEmpty(Queue *q) {
    return (q->size == 0);
}

void enqueue(Queue *q, int value) {
    if(q->size<MAX){
        q->rear=(q->rear+1)%MAX;
        q->items[q->rear]=value;
        q->size++;
    }
}
int dequeue(Queue *q) {
    if (isEmpty(q)) return -1;
    int removed = q->items[q->front];
    q->front = (q->front + 1) % MAX;
    q->size--;
    return removed;
}
void printQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue elements: (empty)\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = 0; i < q->size; i++) {
        int index = (q->front + i) % MAX;
        printf("%d ", q->items[index]);
    }
    printf("\n");
}

void deleteNthElement(Queue *q, int n) {
    printf("Original queue:\n");
    printQueue(q);

    printf("Enter the position of the element to delete: ");

    
    if (n <= 0 || n > q->size) {
        printf("Invalid position. The queue has %d elements.\n", q->size);
        printf("Updated queue:\n");
        printQueue(q);
        return;
    }

    
    for (int i = 1; i < n; i++) {
        int val = dequeue(q);
        enqueue(q, val);
    }
    int deleted = dequeue(q);
    printf("Deleted element at position %d: %d\n", n, deleted);
    printf("Updated queue:\n");
    printQueue(q);
}
int main() {
    Queue q;
    initQueue(&q);
    int elements[] = {10, 20, 30, 40, 50};
    int n = sizeof(elements) / sizeof(elements[0]);
    for (int i = 0; i < n; i++) {
        enqueue(&q, elements[i]);
    }
    int pos;
    scanf("%d", &pos);
    deleteNthElement(&q, pos);
    return 0;
}