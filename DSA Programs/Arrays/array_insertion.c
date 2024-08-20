/* This program shows custom insertion function at required index with display function */

#include <stdio.h>

void display(int a[], int size)
{
    for (int i = 0; i < size; i++)                                     // array traversal
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int ind_sort(int a[], int size, int capacity, int element, int index)
{
    if (size >= capacity)
    {
        printf("Array is full...\n");
        return -1;
    }

    if (index < 0 || index > size)
    {
        printf("Invalid index...\n");
        return -1;
    }
    
    for (int i = size - 1; i >= index; i--)                                // array insertion
    {
        a[i + 1] = a[i];
    }
     
    a[index] = element;
    printf("Insertion successful...\n");
    size += 1;
    display(a, size);
    return 1;
}

int main()
{
    int arr[100] = {1, 4, 23, 46, 78, 89};
    int size = 6, element = 34, index = 3;
    display(arr, size);
    ind_sort(arr, size, 100, element, index);

    return 0;
}