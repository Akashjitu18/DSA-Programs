/* Program to sort an input array using Selection Sort Algorithm */

#include <stdio.h>

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void selectionSort(int a[], int n)
{
    int indexOfMin, temp;
    for (int i = 0; i < n - 1; i++)
    {
        indexOfMin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[indexOfMin])
            {
                indexOfMin = j;
            }
        }
        temp = a[i];
        a[i] = a[indexOfMin];
        a[indexOfMin] = temp;
    }
}

int main()
{
    int a[] = {3, 05, 02, 13, 12};
    int n = 5;

    printf("Initial Array : \n");
    printArray(a, n);

    selectionSort(a, n);
    printf("Sorted Array : \n");
    printArray(a, n);

    return 0;
}


// Input Array (There will be total n-1 passes. 5-1 = 4 in this case!)
//  0   1   2   3   4
// |03, 05, 02, 13, 12

// After first pass
// 02,|05, 03, 13, 12

// After second pass
// 02, 03,|05, 13, 12

// After third pass
// 02, 03, 05,|13, 12

// After fourth pass
// 02, 03, 05, 12,|13
