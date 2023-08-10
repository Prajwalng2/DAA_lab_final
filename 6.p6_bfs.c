#include <stdio.h>
#include <time.h>
#define max 30

struct queue {
    int f;
    int r;
    int arr[max];
};

int isfull(struct queue *q) {
    if (q->r == max - 1) {
        return 1;
    }
    return 0;
}

int isEmpty(struct queue *q) {
    if (q->f == q->r) {
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int val) {
    if (q->r == max - 1) {
        printf("Queue is Full\n");
    } else {
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue *q) {
    int a = -1;
    if (q->f == q->r) {
        printf("Queue is Empty\n");
    } else {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

void print_queue(struct queue *q) {
    for (int i = q->f; i <= q->r; i++) {
        printf("%d\t", q->arr[i]);
    }
    printf("\n");
}

int main() {
    clock_t t;
    t = clock();

    struct queue q;
    struct queue *ptr = &q;
    q.f = 0;
    q.r = 0;

    int num_vertices, num_edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    int visited[num_vertices];
    for (int i = 0; i < num_vertices; i++) {
        visited[i] = 0;
    }

    int a[max][max] = {0}; // Initialize adjacency matrix

    printf("Enter the adjacency matrix (%d x %d):\n", num_vertices, num_vertices);
    for (int i = 0; i < num_edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        a[u][v] = 1;
        a[v][u] = 1; // Assuming an undirected graph
    }

    int start_vertex;
    printf("Enter the starting vertex: ");
    scanf("%d", &start_vertex);

    visited[start_vertex] = 1;
    enqueue(&q, start_vertex);

    while (!isEmpty(&q)) {
        int node = dequeue(&q);

        for (int j = 0; j < num_vertices; j++) {
            if (a[node][j] == 1 && visited[j] == 0) {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }

    t = clock() - t;
    printf("\nTime taken: %f seconds\n", ((float)t) / CLOCKS_PER_SEC);

    return 0;
}
