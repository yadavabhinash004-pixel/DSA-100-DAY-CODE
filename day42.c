#include <stdio.h>
#define MAX 100

// Stack implementation
int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int isEmptyStack() {
    return top == -1;
}

// Queue implementation
int queue[MAX];
int front = 0, rear = -1;

void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmptyQueue() {
    return front > rear;
}

int main() {
    int n, x;

    scanf("%d", &n);

    // Input queue
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    // Step 1: Move queue elements to stack
    while (!isEmptyQueue()) {
        push(dequeue());
    }

    // Step 2: Move back from stack to queue
    while (!isEmptyStack()) {
        enqueue(pop());
    }

    // Print reversed queue
    while (!isEmptyQueue()) {
        printf("%d ", dequeue());
    }

    return 0;
}