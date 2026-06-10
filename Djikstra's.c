#include <stdio.h>

#define MAX 20
#define INF 9999

int main() {
    int n, graph[MAX][MAX];
    int dist[MAX], visited[MAX];
    int source;

    printf("Enter number of vertices: ");Djikstra's.c
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 if no edge):\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);

            if(i != j && graph[i][j] == 0)
                graph[i][j] = INF;
        }
    }

    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &source);

    // Initialize distances and visited array
    for(int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[source] = 0;

    // Dijkstra's Algorithm
    for(int count = 0; count < n - 1; count++) {
        int min = INF, u = -1;

        // Find unvisited vertex with minimum distance
        for(int i = 0; i < n; i++) {
            if(!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        visited[u] = 1;

        // Update distances of adjacent vertices
        for(int v = 0; v < n; v++) {
            if(!visited[v] &&
               graph[u][v] != INF &&
               dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
               }
        }
    }

    printf("\nShortest distances from vertex %d:\n", source);
    for(int i = 0; i < n; i++) {
        printf("To vertex %d = %d\n", i, dist[i]);
    }

    return 0;
}