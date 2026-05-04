#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct {
    int start;
    int end;
} Interval;

int cmp(const void *a, const void *b) {
    Interval *x = (Interval*)a;
    Interval *y = (Interval*)b;
    return x->start - y->start;
}

int main() {
    int n;
    scanf("%d", &n);

    Interval arr[MAX];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    qsort(arr, n, sizeof(Interval), cmp);

    Interval merged[MAX];
    int k = 0;

    merged[0] = arr[0];
    k = 1;

    for (int i = 1; i < n; i++) {
        Interval last = merged[k - 1];

        if (arr[i].start <= last.end) {
            if (arr[i].end > last.end) {
                merged[k - 1].end = arr[i].end;
            }
        } else {
            merged[k++] = arr[i];
        }
    }

    for (int i = 0; i < k; i++) {
        printf("%d %d\n", merged[i].start, merged[i].end);
    }

    return 0;
}