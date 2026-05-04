#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct {
    int start;
    int end;
} Interval;

int cmpStart(const void *a, const void *b) {
    return ((Interval*)a)->start - ((Interval*)b)->start;
}

// Min-heap for end times
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyDown(int heap[], int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;

    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(heap, size, smallest);
    }
}

void heapifyUp(int heap[], int i) {
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    Interval arr[MAX];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    qsort(arr, n, sizeof(Interval), cmpStart);

    int heap[MAX];
    int size = 0;

    // Add first meeting end time
    heap[size++] = arr[0].end;

    for (int i = 1; i < n; i++) {
        // If room is free (earliest end <= current start)
        if (heap[0] <= arr[i].start) {
            heap[0] = arr[i].end;
            heapifyDown(heap, size, 0);
        } else {
            // Need new room
            heap[size++] = arr[i].end;
            heapifyUp(heap, size - 1);
        }
    }

    printf("%d", size);

    return 0;
}