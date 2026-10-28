#include <stdio.h>

#define INF 999999

int main() {
    int n, i, j, edges = 0;
    int cost[20][20], visited[20] = {0};
    int min, a = 0, b = 0, mincost = 0;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);

            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    visited[0] = 1;

    printf("\nEdges in the Minimum Spanning Tree:\n");

    while (edges < n - 1) {
        min = INF;

        for (i = 0; i < n; i++) {
            if (visited[i]) {
                for (j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        if (min == INF) {
            printf("Minimum Spanning Tree does not exist.\n");
            return 0;
        }

        printf("%d - %d : %d\n", a + 1, b + 1, min);

        mincost += min;
        visited[b] = 1;
        edges++;
    }

    printf("\nMinimum cost of the spanning tree = %d\n", mincost);

    return 0;
}