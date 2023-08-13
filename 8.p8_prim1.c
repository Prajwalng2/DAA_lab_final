#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define MAX_VERTICES 10

int minKey(int key[], bool mstSet[], int V) {
    int min = __INT_MAX__, min_index;
    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

int primMST(int graph[MAX_VERTICES][MAX_VERTICES], int V, int startVertex) {
    int parent[MAX_VERTICES];
    int key[MAX_VERTICES];
    bool mstSet[MAX_VERTICES];

    for (int i = 0; i < V; i++)
        key[i] = __INT_MAX__, mstSet[i] = false;

    key[startVertex] = 0;
    parent[startVertex] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);
        mstSet[u] = true;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    int minDistance = 0;
    for (int i = 1; i < V; i++)
        minDistance += graph[i][parent[i]];

    // Display the path of minimum cost
    printf("Path of minimum cost: ");
    for (int i = 1; i < V; i++)
        printf("%d -> %d\t -> %d\n, ", parent[i], i, graph[i][parent[i]]);
    printf("\n");

    return minDistance;
}

int main() {
    int V;
    printf("Enter the number of locations: ");
    scanf("%d", &V);

    int graph[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the distances between locations:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int startVertex;
    printf("Enter the starting vertex (0 to %d): ", V - 1);
    scanf("%d", &startVertex);

    clock_t start = clock();
    int minRouteDistance = primMST(graph, V, startVertex);
    clock_t end = clock();

    printf("Minimum driving route distance: %d\n", minRouteDistance);
    printf("Time taken: %f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);

    return 0;
}
