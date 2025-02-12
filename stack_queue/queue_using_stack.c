/*
Problem:
Implement a queue using two stacks. The queue should support the following operations:
Enqueue an element into the queue.
Dequeue an element from the queue.

Input Format:
First line: An integer, n, representing the number of operations to perform.
Next n lines: Either:
1 x: Representing an enqueue operation where x is the integer to be enqueued into the queue.
2: Representing a dequeue operation to remove the front element from the queue.

Output Format:
For every dequeue operation (2), print the dequeued element. If the queue is empty and a dequeue is attempted, print -1.
*/

#include <stdio.h>
#include <stdlib.h>

// Define the stack structure
struct Stack {
    int top;
    int capacity;
    int* array;
};

// Define the queue structure using two stacks
struct Queue {
    struct Stack* stack1;
    struct Stack* stack2;
};

// Functions to create a stack, enqueue, dequeue, etc.
struct Stack* createStack(int capacity) {
    struct Stack* newStack = (struct Stack*)malloc(sizeof(struct Stack));
    newStack->capacity = capacity;
    newStack->top = -1;
    newStack->array = (int*)malloc((newStack->capacity)*sizeof(int));
    return newStack;
}

int isEmpty(struct Stack* stack) {
    if (stack->top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

void push(struct Stack* stack, int item) {
    stack->top++;
    stack->array[stack->top] = item;
}

int pop(struct Stack* stack) {
    if (stack->top == -1) {
        return -1;
    }
    int popped;
    popped = stack->array[stack->top];
    stack->top--;
    return popped;
}

struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->stack1 = createStack(capacity); 
    queue->stack2 = createStack(capacity);
    return queue;
}

void enqueue(struct Queue* queue, int item) {
    //enqueue operation on queue is simply pushing the value into stack 1
    push(queue->stack1, item);

    /*
    Explaination of enqueue : 
    stack1 : [ ] (empty)
    Enqueue elements 1 2 3:
    push(stack1, 1) : stack1 is [1]
    push(stack1, 2) : stack1 is [1 2]
    push(stack1, 3) : stack1 is [1 2 3]
    */
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue->stack1) && isEmpty(queue->stack2)) { //both stacks empty
        return -1; //error bcs queue is empty
    }
    
    if (isEmpty(queue->stack2)) {
        //If stack2 is empty, move all elements from stack1 to stack2
        while (!isEmpty(queue->stack1)) { //do till stack1 becomes empty because all elements have been transferred
            push(queue->stack2, pop(queue->stack1));
            //push to stack2, the elements popped from stack1
        }
    }
    return pop(queue->stack2);//pop and return the first element in stack2
}


int main() {
    int n;
    scanf("%d", &n);
    
    struct Queue* queue = createQueue(100); // Create a queue with sufficient capacity
    
    for (int i = 0; i < n; i++) {
        int operation;
        scanf("%d", &operation);
        
        if (operation == 1) {
            int x;
            scanf("%d", &x);
            enqueue(queue, x);
        } else if (operation == 2) {
            int result = dequeue(queue);
            printf("%d\n", result == -1 ? -1 : result);
            // If result == -1 (error), print -1. Else print result
        }
    }
    
    return 0;
}