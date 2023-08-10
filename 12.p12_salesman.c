#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <time.h>

#define V 10 // Maximum number of cities

int min(int a, int b) {
    return (a < b) ? a : b;
}

int calculateCost(int graph[V][V], int path[], int n) {
    int cost = 0;
    for (int i = 0; i < n - 1; i++) {
        cost += graph[path[i]][path[i + 1]];
    }
    cost += graph[path[n - 1]][path[0]]; // Return to the starting city
    return cost;
}

void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

void tspBranchAndBound(int graph[V][V], int bound, int cost, int path[], int level, int minCostPath[]) {
    if (level == V - 1) {
        int currentCost = cost + graph[path[level - 1]][path[level]] + graph[path[level]][path[0]];
        if (currentCost < bound) {
            bound = currentCost;
            copyArray(path, minCostPath, V);
        }
        return;
    }

    for (int i = 1; i < V; i++) {
        if (!path[i]) {
            int temp = bound;
            cost += graph[path[level]][i];
            if (level == 0) {
                bound -= ((2 * cost) + calculateCost(graph, path, V));
            } else {
                bound -= ((cost) + calculateCost(graph, path, V));
            }

            if (bound + cost < temp) {
                path[level + 1] = i;
                tspBranchAndBound(graph, bound, cost, path, level + 1, minCostPath);
            }

            cost -= graph[path[level]][i];
            bound = temp;
            path[level + 1] = -1;
        }
    }
}

int main() {
    int n;

    printf("Enter the number of cities (max %d): ", V);
    scanf("%d", &n);

    int graph[V][V];

    printf("Enter the distance matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int bound = INT_MAX;
    int cost = 0;
    int path[V];
    int minCostPath[V];
    for (int i = 0; i < V; i++) {
        path[i] = -1;
    }
    path[0] = 0;

    clock_t start_time = clock();
    tspBranchAndBound(graph, bound, cost, path, 0, minCostPath);
    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Optimal Tour Path: ");
    for (int i = 0; i < V; i++) {
        printf("%d ", minCostPath[i]);
    }
    printf("\nOptimal Tour Cost: %d\n", calculateCost(graph, minCostPath, V));
    printf("Time taken: %f seconds\n", time_taken);

    return 0;
}