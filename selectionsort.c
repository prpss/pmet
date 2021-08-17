#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    double start, end, ttime, swap;
    int arr[1000], i, j, pos, n;

    printf("enter the number of elements: \n");
    scanf("%d", &n);

    printf("enter the elements: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    start = clock();
    for (i = 0; i < n - 1; i++)
    {
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[pos] > arr[j])
            {
                pos = j;
            }
        }
        if (pos != i)
        {
            swap = arr[i];
            arr[i] = arr[pos];
            arr[pos] = swap;
        }
    }

    end = clock();
    ttime = (double)(end - start) / CLOCKS_PER_SEC;
    printf("time taken to execute: %e \n", ttime);
    printf("The sorted list is : ");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }

    return 0;
}
