#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define TRUE 1
#define FALSE 0

// Function to insert an edge into the graph
void insertEdge(int graph[MAX][MAX], int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;  // Since it's an undirected graph
}

// Function to delete an edge from the graph
void deleteEdge(int graph[MAX][MAX], int u, int v) {
    graph[u][v] = 0;
    graph[v][u] = 0;
}

// Function to check if an edge exists between two nodes
int searchEdge(int graph[MAX][MAX], int u, int v) {
    return graph[u][v];
}

// Breadth-First Search (BFS) traversal
void bfs(int graph[MAX][MAX], int start) {
    int visited[MAX] = {0};
    int queue[MAX];
    int front = 0, rear = 0;

    visited[start] = TRUE;
    queue[rear++] = start;

    while (front < rear) {
        int curr = queue[front++];
        printf("%d ", curr);

        for (int i = 0; i < MAX; i++) {
            if (graph[curr][i] == 1 && !visited[i]) {
                visited[i] = TRUE;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

// Depth-First Search (DFS) traversal
void dfs(int graph[MAX][MAX], int start, int visited[MAX]) {
    visited[start] = TRUE;
    printf("%d ", start);

    for (int i = 0; i < MAX; i++) {
        if (graph[start][i] == 1 && !visited[i]) {
            dfs(graph, i, visited);
        }
    }
}

int main() {
    int graph[MAX][MAX] = {0};  // Initialize adjacency matrix with no edges

    // Insert edges into the graph
    insertEdge(graph, 0, 1);
    insertEdge(graph, 0, 2);
    insertEdge(graph, 1, 2);
    insertEdge(graph, 2, 3);

    printf("BFS starting from node 2:\n");
    bfs(graph, 2);

    int visited[MAX] = {0};  // Initialize visited array for DFS

    printf("DFS starting from node 2:\n");
    dfs(graph, 2, visited);

    return 0;
}
