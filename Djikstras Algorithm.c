
#include <stdio.h>
#include <limits.h>

#define MAX 10


int findMin(int dist[], int visited[], int n) {
    int min = INT_MAX;
    int min_index = -1;

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0 && dist[i] < min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}


void dijkstra(int graph[MAX][MAX], int n, int source) {
    int dist[MAX], visited[MAX];

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[source] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = findMin(dist, visited, n);
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (visited[v] == 0 &&
                graph[u][v] != 0 &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }


    printf("\nVertex\tDistance from Source\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}


int main() {
    int n, graph[MAX][MAX], source;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    dijkstra(graph, n, source);

    return 0;
}
