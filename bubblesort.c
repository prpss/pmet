#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    int arr[100], n, i, j, swap;
    double start, end;
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
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = swap;
            }
        }
    }
    end = clock();
    double time = (double)(end - time) / CLOCKS_PER_SEC;
    printf("time taken to execute is %e", time);

    printf("the sorted list is: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }

    return 0;
}
