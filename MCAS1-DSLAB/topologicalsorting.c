#include <stdio.h>

#define MAX 10

int graph[MAX][MAX];
int indegree[MAX];
int queue[MAX];
int front = 0, rear = 0;
int n;

void bfs_topological_sort() {
    int count = 0;

    // Enqueue all vertices with indegree 0
    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            queue[rear++] = i;

    printf("Topological Order: ");

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        count++;

        // Reduce indegree of neighbors
        for (int i = 0; i < n; i++) {
            if (graph[node][i]) {
                indegree[i]--;
                if (indegree[i] == 0)
                    queue[rear++] = i;
            }
        }
    }

    // If not all vertices processed, there's a cycle
    if (count != n)
        printf("\nGraph contains a cycle! Topological sort not possible.\n");
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (directed graph):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    // Compute indegree
    for (int i = 0; i < n; i++) {
        indegree[i] = 0;
        for (int j = 0; j < n; j++)
            if (graph[j][i] == 1)
                indegree[i]++;
    }

    bfs_topological_sort();

    return 0;
}
