#include <stdio.h>

int matrix[10][10], no_of_vertices, f = 0, r = -1, q[10], visited[10];

void bfs(int v)
{
    for (int i = 1; i <= no_of_vertices; i++)
    {
        if (matrix[v][i] && !visited[i])
        {
            q[++r] = i;
        }
        if (f <= r)
        {
            visited[q[f]] = 1;
            bfs(f++);
        }
    }
}

int main(int argc, char const *argv[])
{
    int start;
    printf("enter the no. of vertices: \n");
    scanf("%d", &no_of_vertices);
    for (int i = 1; i <= no_of_vertices; i++)
    {
        q[i] = 0, visited[i] = 0;
    }

    for (int i = 1; i <= no_of_vertices; i++)
    {
        for (int j = 1; j <= no_of_vertices; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    scanf("%d", &start);
    bfs(start);
    for (int i = 1; i <= no_of_vertices; i++)
    {
        if (visited[i] == 1)
        {
            printf("%d", i);
        }
    }

    return 0;
}
