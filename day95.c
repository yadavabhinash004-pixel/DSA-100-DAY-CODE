#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Simple insertion sort for buckets
void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[MAX];

    for (int i = 0; i < n; i++)
        scanf("%f", &arr[i]);

    // Buckets
    float bucket[MAX][MAX];
    int bucketCount[MAX] = {0};

    // Distribute elements
    for (int i = 0; i < n; i++) {
        int index = (int)(n * arr[i]);
        bucket[index][bucketCount[index]++] = arr[i];
    }

    // Sort individual buckets
    for (int i = 0; i < n; i++) {
        if (bucketCount[i] > 0) {
            insertionSort(bucket[i], bucketCount[i]);
        }
    }

    // Concatenate buckets
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucketCount[i]; j++) {
            arr[k++] = bucket[i][j];
        }
    }

    // Print result
    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);

    return 0;
}