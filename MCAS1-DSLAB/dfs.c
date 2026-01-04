#include <stdio.h>

#define MAX 10

int graph[MAX][MAX];  // adjacency matrix
int visited[MAX];
int n; // number of vertices

void dfs(int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix %d*%d:\n",n,n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int start;
    printf("Enter starting vertex (0-%d): ", n - 1);
    scanf("%d", &start);

    printf("DFS traversal: ");
    dfs(start);

    return 0;
}
