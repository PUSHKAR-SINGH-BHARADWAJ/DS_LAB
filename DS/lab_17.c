#include <stdio.h>

int a[10][10], visited[10], n;

void DFS(int v)
{
    int i;
    printf("%d ", v);
    visited[v] = 1;

    for (i = 0; i < n; i++)
        if (a[v][i] == 1 && !visited[i])
            DFS(i);
}

void BFS(int start)
{
    int q[10], front = 0, rear = 0, i, v;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    q[rear++] = start;
    visited[start] = 1;

    while (front < rear)
    {
        v = q[front++];
        printf("%d ", v);

        for (i = 0; i < n; i++)
            if (a[v][i] == 1 && !visited[i])
            {
                q[rear++] = i;
                visited[i] = 1;
            }
    }
}

// PUSHKAR SINGH BHARADWAJ
int main()
{
    int i, j, start;

    printf("Enter number of vertices (max 10): ");
    scanf("%d", &n);

    if (n < 1 || n > 10)
    {
        printf("Invalid number of vertices");
        return 0;
    }

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%1d", &a[i][j]);

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    if (start < 0 || start >= n)
    {
        printf("Invalid starting vertex");
        return 0;
    }

    printf("DFS: ");
    for (i = 0; i < n; i++)
        visited[i] = 0;
    DFS(start);

    printf("\nBFS: ");
    BFS(start);

    return 0;
}