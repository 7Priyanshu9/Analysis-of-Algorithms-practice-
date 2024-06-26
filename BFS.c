#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int queue[MAX_VERTICES];
int front = -1, rear = -1;

void enqueue(int data) {
    if (rear == MAX_VERTICES - 1) {
        printf("Queue overflow\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = data;
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue underflow\n");
        exit(1);
    }
    int data = queue[front];
    front++;
    return data;
}

int isEmpty() {
    return front == -1 || front > rear;
}

void bfs(int graph[MAX_VERTICES][MAX_VERTICES], int i, int n) {
    int visited[MAX_VERTICES] = {0};

    visited[i] = 1;
    enqueue(i);

    while (!isEmpty()) {
        int vertex = dequeue();
        printf("%d ", vertex);

        for (int j = 0; j < n; j++) {
            if (graph[vertex][j] && !visited[j]) {
                visited[j] = 1;
                enqueue(j);
            }
        }
    }
}

int main() {
    int n, e;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    int graph[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("BFS Traversal: ");
    bfs(graph, 0, n); // Start BFS from vertex 0 (you can change this)

    printf("\n");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int queue[MAX_VERTICES];
int front = -1, rear = -1;

void enqueue(int data) {
    if (rear == MAX_VERTICES - 1) {
        printf("Queue overflow\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = data;
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue underflow\n");
        exit(1);
    }
    int data = queue[front];
    front++;
    return data;
}

int isEmpty() {
    return front == -1 || front > rear;
}

void bfs(int graph[MAX_VERTICES][MAX_VERTICES], int i, int n) {
    int visited[MAX_VERTICES] = {0};

    visited[i] = 1;
    enqueue(i);

    while (!isEmpty()) {
        int vertex = dequeue();
        printf("%d ", vertex);

        for (int j = 0; j < n; j++) {
            if (graph[vertex][j] && !visited[j]) {
                visited[j] = 1;
                enqueue(j);
            }
        }
    }
}

int main() {
    int n, e;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    int graph[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("BFS Traversal: ");
    bfs(graph, 0, n); // Start BFS from vertex 0 (you can change this)

    printf("\n");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int queue[MAX_VERTICES];
int front = -1, rear = -1;

void enqueue(int data) {
    if (rear == MAX_VERTICES - 1) {
        printf("Queue overflow\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = data;
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue underflow\n");
        exit(1);
    }
    int data = queue[front];
    front++;
    return data;
}

int isEmpty() {
    return front == -1 || front > rear;
}

void bfs(int graph[MAX_VERTICES][MAX_VERTICES], int i, int n) {
    int visited[MAX_VERTICES] = {0};

    visited[i] = 1;
    enqueue(i);

    while (!isEmpty()) {
        int vertex = dequeue();
        printf("%d ", vertex);

        for (int j = 0; j < n; j++) {
            if (graph[vertex][j] && !visited[j]) {
                visited[j] = 1;
                enqueue(j);
            }
        }
    }
}

int main() {
    int n, e;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    int graph[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("BFS Traversal: ");
    bfs(graph, 0, n); // Start BFS from vertex 0 (you can change this)

    printf("\n");
    return 0;
}
// //Number of vertices: 6
// Number of edges: 8
// Adjacency Matrix:
// 0 1 0 0 1 0
// 1 0 1 1 0 0
// 0 1 0 0 0 1
// 0 1 0 0 0 0
// 1 0 0 0 1 1
// 0 0 1 0 1 0