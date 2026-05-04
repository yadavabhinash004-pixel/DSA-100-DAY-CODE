#include <stdio.h>

#define MAX 100

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int adj[MAX][MAX] = {0};

    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        // assuming vertices are 0-based
        adj[u][v] = 1;
        adj[v][u] = 1; // remove this line for directed graph
    }

    // print adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}