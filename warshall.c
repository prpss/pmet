#include <stdio.h>

int max(int, int);

void warshall(int arr[10][10], int n)
{
    int i, j, k;
    for (k = 1; k <= n; k++)
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                arr[i][j] = max(arr[i][j], arr[i][k] && arr[k][j]);
            }
        }
    }
}

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int main(int argc, char const *argv[])
{
    int arr[10][10], i, j, n;
    printf("enter the number of elements: \n");
    scanf("%d", &n);

    printf("enter the adjacency matrix: \n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    warshall(arr, n);

    printf("the transitive closure for the adjacency matrix is: \n");

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
