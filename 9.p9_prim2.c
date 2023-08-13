#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>

#define MAX_VERTICES 10 // Maximum number of vertices

int minKey(int key[], bool mstSet[], int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

int printMST(int parent[], int graph[MAX_VERTICES][MAX_VERTICES], int V) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int graph[MAX_VERTICES][MAX_VERTICES], int V, int startVertex) {
    int parent[MAX_VERTICES];
    int key[MAX_VERTICES];
    bool mstSet[MAX_VERTICES];

    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[startVertex] = 0;
    parent[startVertex] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);

        mstSet[u] = true;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printMST(parent, graph, V);
}

int main() {
    int V;

    printf("Enter the number of vertices (max %d): ", V);
    scanf("%d", &V);

    int graph[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int startVertex;
    printf("Enter the starting vertex (0 to %d): ", V - 1);
    scanf("%d", &startVertex);

    clock_t start_time = clock();

    primMST(graph, V, startVertex);

    clock_t end_time = clock();
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Time taken: %f seconds\n", time_taken);

    return 0;
}
