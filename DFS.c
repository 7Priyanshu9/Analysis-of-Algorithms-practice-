#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int visited[MAX_VERTICES]; // Keeps track of visited vertices

void dfs(int graph[MAX_VERTICES][MAX_VERTICES], int i, int n) {
    visited[i] = 1;  // Mark current node as visited
    printf("%d ", i); // Print the current node

    // Recur for all adjacent vertices
    for (int j = 0; j < n; j++) {
        if (graph[i][j] && !visited[j]) {
            dfs(graph, j, n);
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

    // Initialize all vertices as unvisited
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("DFS Traversal: ");
    dfs(graph, 0, n); // Start DFS from vertex 0 (you can change this)

    printf("\n");
    return 0;
}
// Number of vertices: 5
// Number of edges: 6
// Adjacency Matrix:
// 0 1 0 0 1
// 1 0 1 1 0
// 0 1 0 0 0
// 0 1 0 0 1
// 1 0 0 1 0