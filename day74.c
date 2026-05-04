#include <stdio.h>
#include <string.h>

#define MAX 1000
#define LEN 50

int main() {
    int n;
    scanf("%d", &n);

    char names[MAX][LEN];

    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    char unique[MAX][LEN];
    int count[MAX] = {0};
    int k = 0;

    // Count votes
    for (int i = 0; i < n; i++) {
        int found = -1;

        for (int j = 0; j < k; j++) {
            if (strcmp(unique[j], names[i]) == 0) {
                found = j;
                break;
            }
        }

        if (found != -1) {
            count[found]++;
        } else {
            strcpy(unique[k], names[i]);
            count[k] = 1;
            k++;
        }
    }

    // Find winner
    int maxVotes = count[0];
    int winner = 0;

    for (int i = 1; i < k; i++) {
        if (count[i] > maxVotes) {
            maxVotes = count[i];
            winner = i;
        } else if (count[i] == maxVotes) {
            if (strcmp(unique[i], unique[winner]) < 0) {
                winner = i;
            }
        }
    }

    printf("%s %d", unique[winner], maxVotes);

    return 0;
}