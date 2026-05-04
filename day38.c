#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

// Check empty
int isEmpty() {
    return (front == -1);
}

// Check full
int isFull() {
    return ((rear + 1) % MAX == front);
}

// push_front
void push_front(int x) {
    if (isFull()) return;

    if (isEmpty()) {
        front = rear = 0;
    } else {
        front = (front - 1 + MAX) % MAX;
    }

    deque[front] = x;
}

// push_back
void push_back(int x) {
    if (isFull()) return;

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    deque[rear] = x;
}

// pop_front
void pop_front() {
    if (isEmpty()) return;

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

// pop_back
void pop_back() {
    if (isEmpty()) return;

    if (front == rear) {
        front = rear = -1;
    } else {
        rear = (rear - 1 + MAX) % MAX;
    }
}

// front element
int getFront() {
    if (isEmpty()) return -1;
    return deque[front];
}

// rear element
int getBack() {
    if (isEmpty()) return -1;
    return deque[rear];
}

// size
int size() {
    if (isEmpty()) return 0;
    if (rear >= front) return rear - front + 1;
    return MAX - front + rear + 1;
}

// display
void display() {
    if (isEmpty()) return;

    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
}

int main() {
    int n, x;
    char op[20];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (op[0] == 'p' && op[5] == 'f') { // push_front
            scanf("%d", &x);
            push_front(x);
        } 
        else if (op[0] == 'p' && op[5] == 'b') { // push_back
            scanf("%d", &x);
            push_back(x);
        } 
        else if (op[0] == 'p' && op[4] == 'f') { // pop_front
            pop_front();
        } 
        else if (op[0] == 'p' && op[4] == 'b') { // pop_back
            pop_back();
        } 
        else if (op[0] == 'f') { // front
            printf("%d\n", getFront());
        } 
        else if (op[0] == 'b') { // back
            printf("%d\n", getBack());
        } 
        else if (op[0] == 's') { // size
            printf("%d\n", size());
        } 
        else if (op[0] == 'e') { // empty
            printf("%d\n", isEmpty());
        }
    }

    // final state
    display();

    return 0;
}