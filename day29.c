#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to rotate linked list right by k places
struct Node* rotateRight(struct Node* head, int k, int n) {
    if (head == NULL || k == 0) return head;

    // Make list circular
    struct Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = head;

    // Effective rotation
    k = k % n;
    int stepsToNewHead = n - k;

    struct Node* newTail = head;
    for (int i = 1; i < stepsToNewHead; i++) {
        newTail = newTail->next;
    }

    struct Node* newHead = newTail->next;
    newTail->next = NULL; // break circular link

    return newHead;
}

// Function to traverse and print linked list
void traverse(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n, k;
    scanf("%d", &n);

    struct Node* head = NULL;
    struct Node* tail = NULL;

    // Create linked list
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        struct Node* newNode = createNode(val);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    scanf("%d", &k);

    // Rotate list
    head = rotateRight(head, k, n);

    // Traverse rotated list
    traverse(head);

    return 0;
}
