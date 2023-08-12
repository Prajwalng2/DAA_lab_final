#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 10
#define MAX_EDGES 20

struct Edge {
    int src, dest, weight;
};

struct Edge edges[MAX_EDGES];
int parent[MAX_VERTICES];

int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

int find(int vertex) {
    if (parent[vertex] == -1)
        return vertex;
    return find(parent[vertex]);
}

void unionSets(int x, int y) {
    parent[x] = y;
}

void kruskalMST(int V, int E) {
    clock_t start = clock();

    qsort(edges, E, sizeof(struct Edge), compareEdges);

    printf("Minimum Spanning Tree:\n");
    printf("Edge \tWeight\n");
    int totalWeight = 0;
    for (int i = 0; i < E; i++) {
        int src = edges[i].src;
        int dest = edges[i].dest;
        int srcParent = find(src);
        int destParent = find(dest);

        if (srcParent != destParent) {
            printf("%d - %d \t%d\n", src, dest, edges[i].weight);
            totalWeight += edges[i].weight;
            unionSets(srcParent, destParent);
        }
    }

    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Total Minimum Spanning Tree Weight: %d\n", totalWeight);
    printf("Time taken: %f seconds\n", time_taken);
}

int main() {
    int V, E;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    printf("Enter the edges (src, dest, weight):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }

    for (int i = 0; i < V; i++)
        parent[i] = -1;

    kruskalMST(V, E);

    return 0;
}



    
