/* This program shows how to create ADT- Abstraction Data Type of an array */

#include <stdio.h>
#include <stdlib.h>

typedef struct myArray
{
    int total_size;
    int used_size;
    int *ptr;
} Arr;

void createArr(Arr *a, int t_size, int u_size)
{
    (*a).total_size = t_size;
    (*a).used_size = u_size;
    (*a).ptr = (int *)malloc(t_size * sizeof(int));
}

void setVal(Arr *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter element %d : ", i + 1);
        scanf("%d", &(a->ptr)[i]);
    }
}

void showArr(Arr *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d\n", (a->ptr)[i]);
    }
}

int main()
{
    Arr marks;
    createArr(&marks, 10, 2);
    setVal(&marks);
    showArr(&marks);
    return 0;
}
