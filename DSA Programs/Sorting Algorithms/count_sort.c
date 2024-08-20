/* Program to sort an input array using Count Sort Algorithm */

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int maximum(int a[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < a[i])
        {
            max = a[i];
        }
    }
    return max;
}

void countSort(int a[], int n)
{
    int i, j;
    int max = maximum(a, n);

    int *count = (int *)malloc((max + 1) * sizeof(int));

    for (i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        count[a[i]] = count[a[i]] + 1;
    }

    i = j = 0;

    while (i <= max)
    {
        if (count[i] > 0)
        {
            a[j] = i;
            count[i] = count[i] - 1;
            j++;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    int a[] = {3, 5, 2, 13, 12, 3, 2, 13, 45};
    int n = 9;

    printf("Initial Array : \n");
    printArray(a, n);

    countSort(a, n);
    printf("Sorted Array : \n");
    printArray(a, n);

    return 0;
}