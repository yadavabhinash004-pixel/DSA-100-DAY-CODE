#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int main() {
    int n;
    scanf("%d", &n);

    int arr[MAX];

    int max = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > max)
            max = arr[i];
    }

    // Frequency array
    int *freq = (int*)calloc(max + 1, sizeof(int));

    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    // Build sorted output
    int k = 0;
    for (int i = 0; i <= max; i++) {
        while (freq[i] > 0) {
            arr[k++] = i;
            freq[i]--;
        }
    }

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    free(freq);

    return 0;
}