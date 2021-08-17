#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int partition(int a[], int low, int high)
{
    int key, i, j, temp, k;
    key = a[low];
    i = low + 1;
    j = high;
    while (i <= j)
    {
        while (i <= j && key >= a[i])
            i = i + 1;
        while (key < a[j])
            j = j - 1;
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        else
        {
            k = a[j];
            a[j] = a[low];
            a[low] = k;
        }
    }
    return j;
}

void quicksort(int a[], int low, int high)
{
    int pos;
    if (low < high)
    {
        pos = partition(a, low, high);
        quicksort(a, low, pos - 1);
        quicksort(a, pos + 1, high);
    }
}
int main()
{
    int i, n, a[20000];
    double totaltime, start, end;
    printf("enter the value of n\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        a[i] = rand();
    }
    start = clock();
    quicksort(a, 0, n - 1);
    end = clock();
    printf("sorted array\n");
    for (i = 0; i < n; i++)
        printf("%d\n", a[i]);
    totaltime = (double)(end - start) / CLOCKS_PER_SEC;
    printf("time taken is %e", totaltime);
}
