#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

// Push operation
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

// Pop operation
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    printf("%d\n", stack[top--]);
}

// Display operation
void display() {
    if (top == -1) {
        printf("Stack is Empty\n");
        return;
    }
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int op, val;
        scanf("%d", &op);

        if (op == 1) { // push
            scanf("%d", &val);
            push(val);
        } else if (op == 2) { // pop
            pop();
        } else if (op == 3) { // display
            display();
        }
    }

    return 0;
}
