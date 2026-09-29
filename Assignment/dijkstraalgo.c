#include <stdio.h>

#define MAX 100
#define INF 99999

void dijkstra(int graph[MAX][MAX], int n, int source) {
    int distance[MAX];
    int visited[MAX];
    int i, j, min, u;
    for (i = 0; i < n; i++) {
        distance[i] = graph[source][i];
        visited[i] = 0;
    }

    distance[source] = 0;
    visited[source] = 1;
    for (i = 1; i < n; i++) {

        min = INF;
        u = -1;
        for (j = 0; j < n; j++) {
            if (!visited[j] && distance[j] < min) {
                min = distance[j];
                u = j;
            }
        }

        // No more reachable vertices
        if (u == -1)
            break;

        visited[u] = 1;
        for (j = 0; j < n; j++) {
            if (!visited[j] &&
                graph[u][j] != INF &&
                distance[u] + graph[u][j] < distance[j]) {

                distance[j] = distance[u] + graph[u][j];
            }
        }
    }
    printf("\nShortest distances from source vertex %d:\n", source);

    for (i = 0; i < n; i++) {
        if (distance[i] == INF)
            printf("Destination %d : Not reachable\n", i);
        else
            printf("Destination %d : %d\n", i, distance[i]);
    }
}

int main() {
    int graph[MAX][MAX];
    int n, source;
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the weighted adjacency matrix:\n");
    printf("(Enter %d for no direct edge)\n", INF);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &source);

    dijkstra(graph, n, source);

    return 0;
}
