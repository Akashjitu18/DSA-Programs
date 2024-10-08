/* Program to sort an input array using Bubble Sort Algorithm */

#include <stdio.h>

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void bubbleSort(int a[], int n)
{
    int temp;
    int isSorted = 0;
    for (int i = 0; i < n - 1; i++) // For no. of passes
    {
        // printf("Working on pass %d\n", i + 1);
        isSorted = 1;
        for (int j = 0; j < n - 1 - i; j++) // For no. of comparisions
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted)
            break;
    }
}

int main()
{
    int a[] = {3, 76, 54, 26, 7, 38};
    int n = 6;

    printf("Initial Array : \n");
    printArray(a, n);

    bubbleSort(a, n);
    printf("Sorted Array : \n");
    printArray(a, n);

    return 0;
}