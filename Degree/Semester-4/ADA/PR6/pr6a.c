#include <stdio.h>

#define MAX 10
#define INF 9999

void prim(int cost[MAX][MAX], int n) {
    int parent[MAX], key[MAX], used[MAX] = {0}, u = 0;

    for (int i = 0; i < n; i++) {
        parent[i] = -1;
        key[i] = INF;
    }

    key[0] = 0;

    for (int c = 0; c < n - 1; c++) {
        int min = INF;

        for (int i = 0; i < n; i++) {
            if (!used[i] && key[i] < min) {
                min = key[i];
                u = i;
            }
        }

        used[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!used[v] && cost[u][v] && cost[u][v] < key[v]) {
                key[v] = cost[u][v];
                parent[v] = u;
            }
        }
    }

    printf("\nEdges in MST using Prim's Algorithm:\n");

    for (int i = 1; i < n; i++) {
        printf("%d - %d : %d\n", parent[i], i, cost[i][parent[i]]);
    }
}

int main(void) {
    int n, cost[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    prim(cost, n);
    return 0;
}