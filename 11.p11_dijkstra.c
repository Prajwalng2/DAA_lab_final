#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <time.h>

#define MAX_VERTICES 10 // Maximum number of vertices

int minDistance(int key[], bool mstSet[], int V) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (mstSet[v] == false && key[v] <= min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void printSolution(int key[], int V, int src) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t %d\n", i, key[i]);
    }
}

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int src, int V) {
    int key[MAX_VERTICES]; // The output array to store shortest distance
    bool mstSet[MAX_VERTICES]; // sptSet[i] will be true if vertex i is included in shortest path tree or shortest distance from src to i is finalized

    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX, mstSet[i] = false;
    }

    // Distance of source vertex from itself is always 0
    key[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(key, mstSet, vertices);
        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (!mstSet[v] && graph[u][v] && key[u] != INT_MAX && key[u] + graph[u][v] < key[v]) {
                key[v] = key[u] + graph[u][v];
            }
        }
    }

    printSolution(key, V, src);
}

int main() {
    int V, src;

    printf("Enter the number of vertices (max %d): ", V);
    scanf("%d", &V);

    int graph[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the weighted adjacency matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the source vertex: ");
    scanf("%d", &src);

    clock_t start_time = clock();
    dijkstra(graph, src, V);
    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Time taken: %f seconds\n", time_taken);

    return 0;
}
