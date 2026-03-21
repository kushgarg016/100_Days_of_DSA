#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Queue structure
struct Queue {
    struct Node* arr[100];
    int front, rear;
};

// Initialize queue
void initQueue(struct Queue* q) {
    q->front = 0;
    q->rear = 0;
}

// Check if empty
int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

// Enqueue
void enqueue(struct Queue* q, struct Node* node) {
    q->arr[q->rear++] = node;
}

// Dequeue
struct Node* dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

// Level Order Traversal
void levelOrder(struct Node* root) {
    if (root == NULL) return;

    struct Queue q;
    initQueue(&q);

    enqueue(&q, root);

    while (!isEmpty(&q)) {
        struct Node* current = dequeue(&q);
        printf("%d ", current->data);

        if (current->left != NULL)
            enqueue(&q, current->left);

        if (current->right != NULL)
            enqueue(&q, current->right);
    }
}

// Driver Code
int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);

    printf("Level Order Traversal: ");
    levelOrder(root);

    return 0;
}