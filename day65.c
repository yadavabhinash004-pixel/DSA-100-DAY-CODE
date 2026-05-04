#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node for adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Graph structure
struct Graph {
    int V;
    struct Node** adjLists;
    int* visited;
};

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create graph
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    graph->adjLists = (struct Node**)malloc(V * sizeof(struct Node*));
    graph->visited = (int*)malloc(V * sizeof(int));

    for (int i = 0; i < V; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

// Add edge (undirected)
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// DFS cycle detection
int dfsCycle(struct Graph* graph, int v, int parent) {
    graph->visited[v] = 1;

    struct Node* temp = graph->adjLists[v];
    while (temp) {
        int adj = temp->vertex;

        if (!graph->visited[adj]) {
            if (dfsCycle(graph, adj, v))
                return 1;
        } 
        else if (adj != parent) {
            return 1;
        }

        temp = temp->next;
    }
    return 0;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Graph* graph = createGraph(n);

    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    int hasCycle = 0;

    for (int i = 0; i < n; i++) {
        if (!graph->visited[i]) {
            if (dfsCycle(graph, i, -1)) {
                hasCycle = 1;
                break;
            }
        }
    }

    if (hasCycle)
        printf("YES");
    else
        printf("NO");

    return 0;
}