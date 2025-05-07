/*
Given a Queue consisting of first n natural numbers (in random order). The task is to check whether the given Queue elements can be arranged in increasing order in another Queue using a stack. The operation allowed are: 

1. Push and pop elements from the stack 
2. Pop (Or Dequeue) from the given Queue. 
3. Push (Or Enqueue) in another Queue.

Input : Queue[] = { 5, 1, 2, 3, 4 } 
Output: Yes 
Pop the first element of the given Queue, i.e. 5. 
Push 5 into the stack. 
Now, pop all the elements of the given Queue and push them to 
second Queue. 
Now, pop element 5 in the stack and push it to the second Queue. 
  
Input: Queue[] = { 5, 1, 2, 6, 3, 4 } 
Output: No 
Push 5 to stack. 
Pop 1 and 2 from a given Queue and push them to another Queue. 
Pop 6 from the given Queue and push to stack. 
Pop 3 and 4 from the given Queue and push to the second Queue. 
Now, from using any of the above operations, we cannot push 5 
into the second Queue because it is below the 6 in the stack. 

Observe that the second Queue (which will contain the sorted element) takes inputs (or enqueue elements) either from a given Queue or Stack. So, the next expected (initially 1) must be present as a front element of a given Queue or top element of the Stack. So, simulate the process for the second Queue by initializing the expected element as 1. Check if we can get the expected element from the front of the given Queue or from the top of the Stack. If we cannot take it from either of them, pop the front element of the given queue and push it to the stack. 

Also, observe that the stack must also be sorted at each instance, i.e. the element at the top of the stack must be the smallest in the stack. For example, let x > y, and then x will always be expected before y. So, x cannot be pushed before y in the stack. Therefore, we cannot push an element with a higher value on top of the element with a lesser value.

Complexity Analysis:
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct Queue {
    int items[MAX];
    int front, rear;
} Queue;

typedef struct Stack {
    int items[MAX];
    int top;
} Stack;

void enqueue(Queue *q, int item) {
    // your logic
    if (q->rear == MAX - 1) {
    printf("Queue is full\n");
    return;
    }
    q->items[++q->rear] = item;
    if (q->front == -1) {
        q->front = 0;
    }
}

int dequeue(Queue *q) {
// your logic
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->items[q->front++];
}

void push(Stack *s, int item) {
    // your logic
    if (s->top == MAX - 1) {
        printf("Stack is full\n");
        return;
    }
    s->items[++s->top] = item;
}


int pop(Stack *s) {
    // your logic
    if (s->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->items[s->top--];
}

bool check_sortable(int arr[], int n) {
    Queue q = { .front = -1, .rear = -1 };
    Stack s = { .top = -1 };
    
    for (int i = 0; i < n; i++) {
        enqueue(&q, arr[i]);
    }
    
    int expected = 1;
    while (q.front <= q.rear || s.top != -1) {
        if (q.front <= q.rear && q.items[q.front] == expected) {
            dequeue(&q);
            expected++;
        } else if (s.top != -1 && s.items[s.top] == expected) {
            pop(&s);
            expected++;
        } else if (q.front <= q.rear) {
            if (s.top != -1 && s.items[s.top] < q.items[q.front]) {
                return false;
            }
            push(&s, dequeue(&q));
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX) {
        printf("Invalid input size.\n");
        return 0;
    }
    
    int arr[MAX];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input.\n");
            return 0;
        }
    }
    
    if (check_sortable(arr, n)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}