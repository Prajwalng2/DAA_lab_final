#include <stdio.h>
#include <time.h>

int visited[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int a[10][10];

void DFS(int vertex, int num_vertices) {
    printf("%d ", vertex);
    visited[vertex] = 1;
    
    for (int j = 0; j < num_vertices; j++) {
        if (a[vertex][j] == 1 && visited[j] == 0) {
            DFS(j, num_vertices);
        }
    }
}

int main() {
    clock_t t;
    t = clock();
    
    int num_vertices, num_edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);
    
    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);
    
    printf("Enter the adjacency matrix (%d x %d):\n", num_vertices, num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    int start_vertex;
    printf("Enter the starting vertex: ");
    scanf("%d", &start_vertex);
    
    DFS(start_vertex, num_vertices);
    t = clock() - t;
    printf("\nTime taken: %f seconds\n", ((float)t) / CLOCKS_PER_SEC);
    
    return 0;
}
