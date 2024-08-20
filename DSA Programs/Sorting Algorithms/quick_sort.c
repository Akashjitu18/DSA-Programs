/* Program to sort an input array using Quick Sort Algorithm */

#include <stdio.h>

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    int temp;

    while (i <= j)
    {
        while (a[i] <= pivot)
        {
            i++;
        }
        while (a[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    return j;
}

void quickSort(int a[], int low, int high)
{
    int partitionIndex;

    if (low < high)
    {
        partitionIndex = partition(a, low, high);
        // printArray(a, 9);
        quickSort(a, low, partitionIndex - 1);
        quickSort(a, partitionIndex + 1, high);
    }
}

int main()
{
    int a[] = {3, 5, 2, 13, 12, 3, 2, 13, 45};
    int n = 9;

    printf("Initial Array : \n");
    printArray(a, n);

    quickSort(a, 0, n - 1);
    printf("Sorted Array : \n");
    printArray(a, n);

    return 0;
}