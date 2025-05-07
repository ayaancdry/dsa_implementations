/*
You are tasked with implementing a simple HashSet (set of unique integers) that automatically resizes its underlying storage array when the load factor exceeds 0.75. The set supports three operations:

add(x): Inserts the element x into the set. If already present, do nothing.
contains(x): Outputs true if the element exists in the set, otherwise false
remove(x): Removes the element x from the set if it exists.


After every add or remove operation, output the current state of the set with elements sorted in ascending order
Input format:
The first line contains an integer N — the number of operations.
The next N lines contain operations in one of the following formats:
- add x
- contains x
- remove x

Output format:
For add and remove: Output the current set in ascending order, formatted as [x1, x2, ..., xn].


For contains: Output true if the element exists, false otherwise.
Sample input:
7
add 5
add 3
add 5
contains 3
remove 5
contains 5
add 7

Sample output:
[5]
[3, 5]
[3, 5]
true
[3]
false
[3, 7]
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 10
#define LOAD_FACTOR 0.75

typedef struct node {
    int key;
    struct node* next;
} Node;

typedef struct {
    Node** buckets;
    int capacity;
    int size;
} HashSet;

unsigned int hash(int key, int capacity) {
    return (unsigned int)(key % capacity);
}

HashSet* createHashSet() {
    HashSet* set = (HashSet*)malloc(sizeof(HashSet)); // Explicit cast for malloc
    set->capacity = INITIAL_CAPACITY;
    set->size = 0;
    set->buckets = (Node**)calloc(set->capacity, sizeof(Node*)); // Explicit cast for calloc
    return set;
}

int cmpfunc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

char* getSortedString(HashSet* set) {
    int* elements = (int*)malloc(set->size * sizeof(int));
    int idx = 0;
    for (int i = 0; i < set->capacity; i++) {
        Node* current = set->buckets[i];
        while (current) {
            elements[idx++] = current->key;
            current = current->next;
        }
    }
    qsort(elements, set->size, sizeof(int), cmpfunc);

    char* buffer = (char*)malloc(10000); // Explicit cast for malloc
    int pos = 0;
    pos += sprintf(buffer + pos, "[");
    for (int i = 0; i < set->size; i++) {
        pos += sprintf(buffer + pos, "%d", elements[i]);
        if (i < set->size - 1) pos += sprintf(buffer + pos, ", ");
    }
    sprintf(buffer + pos, "]");
    free(elements);
    return buffer;
}

void resizeHashSet(HashSet* set) {
    int oldCapacity = set->capacity;
    Node** oldBuckets = set->buckets;

    set->capacity *= 2;
    set->buckets = (Node**)calloc(set->capacity, sizeof(Node*));
    set->size = 0;

    for (int i = 0; i < oldCapacity; i++) {
        Node* current = oldBuckets[i];
        while (current) {
            Node* next = current->next;
            unsigned int index = hash(current->key, set->capacity);
            current->next = set->buckets[index];
            set->buckets[index] = current;
            current = next;
            set->size++;
        }
    }
    free(oldBuckets);
}

int contains(HashSet* set, int key) {
    unsigned int index = hash(key, set->capacity);
    Node* current = set->buckets[index];
    while (current) {
        if (current->key == key) return 1;
        current = current->next;
    }
    return 0;
}

void add(HashSet* set, int key) {
    if (contains(set, key)) return;
    unsigned int index = hash(key, set->capacity);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = set->buckets[index];
    set->buckets[index] = newNode;
    set->size++;

    if ((float)set->size / set->capacity > LOAD_FACTOR) {
        resizeHashSet(set);
    }
}

void removeKey(HashSet* set, int key) {
    unsigned int index = hash(key, set->capacity);
    Node* current = set->buckets[index];
    Node* prev = NULL;
    while (current) {
        if (current->key == key) {
            if (prev) prev->next = current->next;
            else set->buckets[index] = current->next;
            free(current);
            set->size--;
            return;
        }
        prev = current;
        current = current->next;
    }
}

void freeHashSet(HashSet* set) {
    for (int i = 0; i < set->capacity; i++) {
        Node* current = set->buckets[i];
        while (current) {
            Node* tmp = current;
            current = current->next;
            free(tmp);
        }
    }
    free(set->buckets);
    free(set);
}

int main() {
    int N;
    scanf("%d", &N);
    HashSet* set = createHashSet();
    char operation[20];
    int x;

    char** outputs = (char**)malloc(N * sizeof(char*)); // Explicit cast for malloc
    int outCount = 0;

    for (int i = 0; i < N; i++) {
        scanf("%s", operation);
        if (strcmp(operation, "add") == 0) {
            scanf("%d", &x);
            add(set, x);
            outputs[outCount++] = getSortedString(set);
        } else if (strcmp(operation, "contains") == 0) {
            scanf("%d", &x);
            outputs[outCount++] = strdup(contains(set, x) ? "true" : "false");
        } else if (strcmp(operation, "remove") == 0) {
            scanf("%d", &x);
            removeKey(set, x);
            outputs[outCount++] = getSortedString(set);
        }
    }

    for (int i = 0; i < outCount; i++) {
        printf("%s\n", outputs[i]);
        free(outputs[i]);
    }

    free(outputs);
    freeHashSet(set);
    return 0;
}