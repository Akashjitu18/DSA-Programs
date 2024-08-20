/* This program is for creating Queue using linked list and performing EnQueue and DeQueue operations on Queue in C */


#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Q;

Q *f = NULL;
Q *r = NULL;

void traverse(Q *f)
{
    if (f == NULL)
    {
        printf("Q is Empty\n");
    }
    for (int i = 1; f != NULL; i++)
    {
        printf("Element of Node %d is %d\n", i, f->data);
        f = f->next;
    }
}

void enQ(int val)
{
    Q *n = (Q *)malloc(sizeof(Q));
    if (n == NULL)
    {
        printf("Q is full...cannot enQ\n");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}

int deQ()
{
    int val = -1;
    Q *n = f;
    if (f == NULL)
    {
        printf("Q is Empty...cannot deQ\n");
    }
    else
    {
        f = f->next;
        val = n->data;
        free(n);
    }
    return val;
}

int main()
{

    enQ(7);
    enQ(8);
    enQ(74);
    enQ(26);
    enQ(80);

    traverse(f);

    printf("Dequeued element is %d\n", deQ());
    printf("Dequeued element is %d\n", deQ());

    traverse(f);

    return 0;
}