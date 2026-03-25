#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20
#define INF 9999

int minKey(int key[], int mstSet[], int V) {
    int min = INF, index = -1;

    for (int i = 0; i < V; i++) {
        if (!mstSet[i] && key[i] < min) {
            min = key[i];
            index = i;
        }
    }
    return index;
}

void primMST(int graph[MAX][MAX], int V) {
    int parent[MAX], key[MAX], mstSet[MAX];

    for (int i = 0; i < V; i++) {
        key[i] = INF;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < V - 1; i++) {
        int u = minKey(key, mstSet, V);
        mstSet[u] = 1;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    int total = 0;
    printf("\nMST using Prim:\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d = %d\n", parent[i], i, graph[i][parent[i]]);
        total += graph[i][parent[i]];
    }
    printf("Total cost = %d\n", total);
}

int main() {
    int V, graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    srand(time(0));


    for (int i = 0; i < V; i++) {
        for (int j = i; j < V; j++) {
            if (i == j)
                graph[i][j] = 0;
            else {
                int weight = rand() % 20
                 + 1;
                graph[i][j] = graph[j][i] = weight;
            }
        }
    }

    printf("\nGenerated Graph:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++)
            printf("%3d ", graph[i][j]);
        printf("\n");
    }

    primMST(graph, V);
    return 0;
}
