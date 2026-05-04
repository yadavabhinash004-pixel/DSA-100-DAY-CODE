#include <stdio.h>
#include <stdlib.h>

// Define polynomial node structure
struct Node {
    int coeff;          // coefficient
    int exp;            // exponent
    struct Node* next;  // pointer to next term
};

// Function to create new node
struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to insert node at end
void insertNode(struct Node** head, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to print polynomial
void printPolynomial(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->coeff);
        if (temp->exp != 0) {
            printf("x^%d", temp->exp);
        }
        if (temp->next != NULL) {
            printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* head = NULL;

    // Read terms
    for (int i = 0; i < n; i++) {
        int coeff, exp;
        scanf("%d %d", &coeff, &exp);
        insertNode(&head, coeff, exp);
    }

    // Print polynomial
    printPolynomial(head);

    return 0;
}
