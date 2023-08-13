#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Edge {
    int src, dest, weight;
};

void dijkstra(int vertices, struct Edge graph[], int edges, int src) {
    int dist[vertices];
    int sptSet[vertices];

    for (int i = 0; i < vertices; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < vertices - 1; count++) {
        int u = -1;
        for (int v = 0; v < vertices; v++) {
            if (!sptSet[v] && (u == -1 || dist[v] < dist[u])) {
                u = v;
            }
        }

        sptSet[u] = 1;

        for (int i = 0; i < edges; i++) {
            if (!sptSet[graph[i].dest] && graph[i].src == u && dist[u] != INT_MAX && dist[u] + graph[i].weight < dist[graph[i].dest]) {
                dist[graph[i].dest] = dist[u] + graph[i].weight;
            }
        }
    }

    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < vertices; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}

int main() {
    int vertices, edges;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    struct Edge graph[edges];

    printf("Enter the edges (src dest weight):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &graph[i].src, &graph[i].dest, &graph[i].weight);
    }

    int src;
    printf("Enter the source vertex: ");
    scanf("%d", &src);

    dijkstra(vertices, graph, edges, src);

    return 0;
}
