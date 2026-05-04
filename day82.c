#include <stdio.h>

int lowerBound(int arr[], int n, int x) {
    int low = 0, high = n;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= x)
            high = mid;
        else
            low = mid + 1;
    }

    return low;
}

int upperBound(int arr[], int n, int x) {
    int low = 0, high = n;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] > x)
            high = mid;
        else
            low = mid + 1;
    }

    return low;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int x;
    scanf("%d", &x);

    int lb = lowerBound(arr, n, x);
    int ub = upperBound(arr, n, x);

    printf("%d %d", lb, ub);

    return 0;
}