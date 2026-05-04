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
    int indegree[MAX];
};

// Queue
int queue[MAX];
int front = 0, rear = -1;

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

    for (int i = 0; i < V; i++) {
        graph->adjLists[i] = NULL;
        graph->indegree[i] = 0;
    }

    return graph;
}

// Add edge (directed)
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    graph->indegree[dest]++;
}

// Queue operations
void enqueue(int v) {
    queue[++rear] = v;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front > rear;
}

// Kahn's Algorithm
void topoSort(struct Graph* graph) {
    int count = 0;

    // Step 1: Add all vertices with indegree 0
    for (int i = 0; i < graph->V; i++) {
        if (graph->indegree[i] == 0)
            enqueue(i);
    }

    // Step 2: Process queue
    while (!isEmpty()) {
        int u = dequeue();
        printf("%d ", u);
        count++;

        struct Node* temp = graph->adjLists[u];
        while (temp) {
            int v = temp->vertex;
            graph->indegree[v]--;

            if (graph->indegree[v] == 0)
                enqueue(v);

            temp = temp->next;
        }
    }

    // Step 3: Check for cycle
    if (count != graph->V)
        printf("\nCycle detected");
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

    topoSort(graph);

    return 0;
}