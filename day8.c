#include <stdio.h>

// Recursive function to calculate a^b
int power(int a, int b) {
    if (b == 0) return 1;          // base case
    return a * power(a, b - 1);    // recursive step
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", power(a, b));
    return 0;
}
