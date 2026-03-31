#include <stdio.h>
#include <stdlib.h>

// Structure for tree node
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
    q->rear = -1;
}

// Check if queue is empty
int isEmpty(struct Queue* q) {
    return q->front > q->rear;
}

// Enqueue
void enqueue(struct Queue* q, struct Node* node) {
    q->arr[++q->rear] = node;
}

// Dequeue
struct Node* dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node* root = createNode(arr[0]);
    struct Queue q;
    initQueue(&q);
    enqueue(&q, root);

    int i = 1;

    while (!isEmpty(&q) && i < n) {
        struct Node* curr = dequeue(&q);

        // Left child
        if (arr[i] != -1) {
            curr->left = createNode(arr[i]);
            enqueue(&q, curr->left);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            enqueue(&q, curr->right);
        }
        i++;
    }

    return root;
}

// Function to print right view
void rightView(struct Node* root) {
    if (root == NULL)
        return;

    struct Queue q;
    initQueue(&q);
    enqueue(&q, root);

    while (!isEmpty(&q)) {
        int size = q.rear - q.front + 1;

        for (int i = 0; i < size; i++) {
            struct Node* curr = dequeue(&q);

            // Print last node of each level
            if (i == size - 1)
                printf("%d ", curr->data);

            if (curr->left)
                enqueue(&q, curr->left);

            if (curr->right)
                enqueue(&q, curr->right);
        }
    }
}

// Main function
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    rightView(root);

    return 0;
}