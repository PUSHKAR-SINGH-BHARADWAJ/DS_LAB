#include <stdio.h>

#define MAX 10
#define INF 99999

void dijkstra(int graph[MAX][MAX], int n, int source)
{
    int dist[MAX], visited[MAX];
    int i, j, min, u;

    for (i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[source] = 0;

    for (i = 0; i < n - 1; i++)
    {
        min = INF;
        u = -1;

        for (j = 0; j < n; j++)
        {
            if (!visited[j] && dist[j] < min)
            {
                min = dist[j];
                u = j;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        for (j = 0; j < n; j++)
        {
            if (!visited[j] && graph[u][j] > 0 &&
                dist[u] + graph[u][j] < dist[j])
            {
                dist[j] = dist[u] + graph[u][j];
            }
        }
    }

    printf("\nShortest distances from vertex %d:\n", source);

    for (i = 0; i < n; i++)
    {
        if (dist[i] == INF)
            printf("Vertex %d: Unreachable\n", i);
        else
            printf("Vertex %d: %d\n", i, dist[i]);
    }
}

int main()
{
    int graph[MAX][MAX];
    int n, i, j, source;

    printf("Enter number of vertices (max %d): ", MAX);
    scanf("%d", &n);

    if (n < 1 || n > MAX)
    {
        printf("Invalid number of vertices.\n");
        return 1;
    }

    printf("Enter adjacency matrix (0 means no edge):\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &source);

    if (source < 0 || source >= n)
    {
        printf("Invalid source vertex.\n");
        return 1;
    }

    dijkstra(graph, n, source);

    return 0;
}