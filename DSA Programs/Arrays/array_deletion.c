/* This program shows custom delete function at required index with display function */

#include <stdio.h>

void display(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int ind_del(int a[], int size, int index)
{

    if (index < 0 || index > size)
    {
        printf("Invalid index...\n");
        return -1;
    }

    for (int i = index; i < size ; i++)
    {
        a[i] = a[i + 1];
    }

    printf("Deletion successful...\n");
    size -= 1;
    display(a, size);
    return 1;
}

int main()
{
    int arr[100] = {2, 44, 35, 78, 33};
    int size = 5, index = 2;
    display(arr, size);
    ind_del(arr, size, index);
    return 0;
}