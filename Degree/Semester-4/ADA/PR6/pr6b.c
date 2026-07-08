#include <stdio.h>

#define MAX 20

struct Edge { int u, v, w; } edges[MAX];
int parent[MAX];

int find(int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = find(parent[x]);
}

void sortEdges(struct Edge e[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (e[i].w > e[j].w) {
                struct Edge t = e[i];
                e[i] = e[j];
                e[j] = t;
            }
        }
    }
}

void kruskal(int n, int m) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    sortEdges(edges, m);

    int total = 0;

    printf("\nEdges in MST using Kruskal's Algorithm:\n");

    for (int i = 0; i < m; i++) {
        int u = find(edges[i].u);
        int v = find(edges[i].v);

        if (u != v) {
            printf("%d - %d : %d\n", edges[i].u, edges[i].v, edges[i].w);
            total += edges[i].w;
            parent[u] = v;
        }
    }

    printf("\nTotal weight of MST = %d\n", total);
}

int main(void) {
    int n, m;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter edges (u v weight):\n");

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    kruskal(n, m);
    return 0;
}