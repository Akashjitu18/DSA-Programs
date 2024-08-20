/* This is the binary search array program to search a given number in an array */

#include <stdio.h>

int binarysearch(int a[], int size, int element)
{
    int low = 0;
    int high = size - 1;
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] == element)
        {
            printf("%d is present in the array at index %d", element, mid);
            return mid;
        }

        if (a[mid] > element)
        {
            high = mid - 1;
        }
        if (a[mid] < element)
        {
            low = mid + 1;
        }
    }
    printf("%d is not present in the array", element);
    return -1;
}

int main()
{
    int arr[] = {2, 19, 23, 45, 55, 78, 95,123};
    int size = sizeof(arr) / sizeof(int), element = 23;
    binarysearch(arr, size, element);
    return 0;
}