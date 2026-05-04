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

// Function to delete first occurrence of key
struct Node* deleteKey(struct Node* head, int key) {
    struct Node* temp = head;
    struct Node* prev = NULL;

    // If head itself holds the key
    if (temp != NULL && temp->data == key) {
        head = temp->next;  // move head
        free(temp);         // free memory
        return head;
    }

    // Search for the key
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key not found
    if (temp == NULL) return head;

    // Unlink node
    prev->next = temp->next;
    free(temp);

    return head;
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
    int n, key;
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

    scanf("%d", &key);

    // Delete first occurrence of key
    head = deleteKey(head, key);

    // Traverse updated list
    traverse(head);

    return 0;
}
