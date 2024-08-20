/* Program to sort an input array using Merge Sort Algorithm */

#include <stdio.h>

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void merge(int a[], int low, int mid, int high)
{
    int i, j, k, b[high + 1];
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }
        else
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        b[k] = a[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        b[k] = a[j];
        j++;
        k++;
    }
    for (int i = low; i <= high; i++)
    {
        a[i] = b[i];
    }
}

void mergeSort(int a[], int low, int high)
{
    if (low >= high){
        return;
    }
    else
    {
        int mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main()
{
    int a[] = {3, 5, 2, 13, 12, 3, 2, 13, 45};
    int n = 9;

    printf("Initial Array : \n");
    printArray(a, n);

    mergeSort(a, 0, n - 1);
    printf("Sorted Array : \n");
    printArray(a, n);

    return 0;
}