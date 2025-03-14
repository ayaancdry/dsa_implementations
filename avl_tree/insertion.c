#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
    int height;
}Node;

// Function to return height
int getHeight(Node *N) {
    if (N==NULL) {
        return 0;
    }
    return N->height; 
}

Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> left = NULL;
    newNode -> right = NULL;
    newNode -> key = key;
    newNode ->  height = 1; 
    return newNode;
}

int max(int a, int b) {
    return a>b?a:b;
}

int getBalanceFactor(Node *N) {
    if (N==NULL) {
        return 0;
    }
    return getHeight(N->left) - getHeight(N->right);
}


Node* rightRotate(Node *y) {
    /* 
            y                           x
           / \                         / \
          x   T3                      T1  y
         / \                             / \
       T1  T2                           T2  T3

    The second tree is the product of performing right-rotation on the first tree
    */
    // Initialise the nodes which will be shifting their location
    Node *x = y->left;
    Node *T2 = x->right;

    // After rotation 
    x->right = y;
    y->left = T2;

    // Get the heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
    // means the final tree's root is x
}

Node* leftRotate(Node *x) {
    /* 
            y                           x
           / \                         / \
          x   T3                      T1  y
         / \                             / \
       T1  T2                           T2  T3
    The first tree is the product of performing left-rotation on the second tree
    */
    Node *y = x->right;
    Node *T2 = y->left;

    // After rotation
    y->left = x;
    x->right = T2;

    // Get the heights 
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

    return y;
}

Node* insertNode(Node *node, int key) {
    if (node == NULL) {
        return createNode(key);
    }
    // simple binary search tree insertion
    if (key < node->key) {
        node -> left = insertNode(node->left, key);
    }
    else if (key > node->key) {
        node -> right = insertNode(node->right, key);
    }
    else {
        return node;
    }
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int bf = getBalanceFactor(node);

    // Insertion of a new node may lead to disruption in valid BF.
    // There are four cases

    // L-L Imbalance. Solve : RR Rotation
    if (bf>1 && key < node->left->key) {
        return rightRotate(node);
    }
    // R-R Imbalance. Solve : LL Rotation
    if (bf<-1 && key > node->right->key) {
        return leftRotate(node);
    }
    // L-R Imbalance. Solve : LR Rotation
    if (bf>1 && key > node->left->key) {
        node -> left = leftRotate(node->left);
        return rightRotate(node);
    }
    // R-L Imbalance. Solve : RL Rotation
    if (bf<-1 && key < node->right->key) {
        node -> right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void preOrder(Node *root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    Node *root = NULL;
    root = insertNode(root, 45); 
    root = insertNode(root, 5);
    root = insertNode(root, 6);
    root = insertNode(root, 9);
    root = insertNode(root, 8);
    root = insertNode(root, 10);
    preOrder(root);
    return 0;
}


