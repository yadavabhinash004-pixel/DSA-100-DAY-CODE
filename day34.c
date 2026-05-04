#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Node for linked list stack
struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

// Push
void push(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

// Pop
int pop() {
    if (top == NULL) return 0;
    struct Node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int main() {
    char exp[100];
    int i = 0;

    // Read full line input
    fgets(exp, sizeof(exp), stdin);

    while (exp[i] != '\0') {
        // Skip spaces
        if (exp[i] == ' ') {
            i++;
            continue;
        }

        // If operand
        if (isdigit(exp[i])) {
            int num = 0;
            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            push(num);
            continue;
        }

        // Operator
        int b = pop();
        int a = pop();
        int result;

        switch (exp[i]) {
            case '+': result = a + b; break;
            case '-': result = a - b; break;
            case '*': result = a * b; break;
            case '/': result = a / b; break;
            default: result = 0;
        }

        push(result);
        i++;
    }

    // Final result
    printf("%d", pop());

    return 0;
}