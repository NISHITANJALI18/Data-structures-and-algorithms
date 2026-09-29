#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];

void BFS(int n, int start) {
    int front = 0, rear = 0;
    int current, i;
    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS Traversal: ");

    while (front < rear) {
        current = queue[front++];

        printf("%d ", current);
        for (i = 0; i < n; i++) {

            if (graph[current][i] == 1 && visited[i] == 0) {

                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    printf("\n");
}

int main() {
    int n, start;
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    for (i = 0; i < n; i++)
        visited[i] = 0;

    BFS(n, start);

    return 0;
}
