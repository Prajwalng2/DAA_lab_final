#include <stdio.h>
#include <time.h>
#define max 10

struct queue {
    int f;
    int r;
    int arr[30];
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
        printf("Queue is Full \n");
    } else {
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue *q) {
    int a = -1;
    if (q->f == q->r) {
        printf("Queue is Empty \n");
    } else {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

void print_queue(struct queue *q) {
    for (int i = q->f; i <= q->r; i++) {
        printf("%d \t", q->arr[i]);
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

    int n, start;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    
    int visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    int a[n][n];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    visited[start] = 1;
    enqueue(&q, start);

    printf("Breadth-First Traversal: ");

    while (!isEmpty(&q)) {
        int node = dequeue(&q);

        printf("%d ", node);

        for (int j = 0; j < n; j++) {
            if (a[node][j] == 1 && visited[j] == 0) {
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }

    t = clock() - t;
    printf("\nTime taken: %f seconds\n", ((float)t) / CLOCKS_PER_SEC);

    return 0;
}
