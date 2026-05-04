#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct {
    int pos;
    int speed;
} Car;

int cmp(const void *a, const void *b) {
    Car *x = (Car*)a;
    Car *y = (Car*)b;
    return y->pos - x->pos; // descending by position
}

int main() {
    int n;
    scanf("%d", &n);

    int target;
    scanf("%d", &target);

    Car cars[MAX];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &cars[i].pos, &cars[i].speed);
    }

    // Sort by position descending
    qsort(cars, n, sizeof(Car), cmp);

    int fleets = 0;
    double currTime = -1;

    for (int i = 0; i < n; i++) {
        double time = (double)(target - cars[i].pos) / cars[i].speed;

        // If new slower/longer time → new fleet
        if (time > currTime) {
            fleets++;
            currTime = time;
        }
        // else it joins existing fleet
    }

    printf("%d", fleets);

    return 0;
}