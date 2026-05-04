#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Node structure
struct Node {
    int data;
    struct Node *left, *right;
};

// Queue item with horizontal distance
struct QItem {
    struct Node* node;
    int hd;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);

    struct Node* queue[MAX];
    int front = 0, rear = 0;
    queue[rear++] = root;

    int i = 1;

    while (i < n) {
        struct Node* curr = queue[front++];

        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[MAX];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    // Queue for BFS
    struct QItem q[MAX];
    int front = 0, rear = 0;

    // Storage for vertical order
    int result[MAX][MAX];
    int count[MAX] = {0};

    int offset = MAX / 2; // to handle negative hd

    // Start BFS
    q[rear++] = (struct QItem){root, 0};

    int min_hd = 0, max_hd = 0;

    while (front < rear) {
        struct QItem temp = q[front++];
        struct Node* curr = temp.node;
        int hd = temp.hd;

        int index = hd + offset;

        result[index][count[index]++] = curr->data;

        if (hd < min_hd) min_hd = hd;
        if (hd > max_hd) max_hd = hd;

        if (curr->left)
            q[rear++] = (struct QItem){curr->left, hd - 1};

        if (curr->right)
            q[rear++] = (struct QItem){curr->right, hd + 1};
    }

    // Print vertical order
    for (int i = min_hd; i <= max_hd; i++) {
        int idx = i + offset;
        for (int j = 0; j < count[idx]; j++) {
            printf("%d ", result[idx][j]);
        }
        printf("\n");
    }

    return 0;
}