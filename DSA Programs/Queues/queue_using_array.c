/* This program is for creating Queue using arrays and performing EnQueue and DeQueue operations on Queue in C */

#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int size;
    int f;
    int r;
    int *arr;

} Q;

int isFull(Q *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    else
        return 0;
}

int isEmpty(Q *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    else
        return 0;
}

void enq(Q *q, int val)
{
    if (isFull(q))
    {
        printf("Q is Full...cannot enQ\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}

int deQ(Q *q)
{
    int val = -1;
    if (isEmpty(q))
    {
        printf("Q is Empty...cannot deQ\n");
    }
    else
    {
        q->f++;
        val = q->arr[q->f];
    }
    return val;
}

void display(Q *q)
{
    if (isEmpty(q))
    {
        printf("Q is Empty\n");
    }
    else
    {
        for (int i = q->f + 1; i <= q->r; i++)
        {
            printf("Element %d of Q is %d\n", i - q->f, q->arr[i]);
        }
    }
}

void peek(Q *q, int pos)
{
    if (pos <= 0 || pos > q->r - q->f)
    {
        printf("Invalid position\n");
    }
    else
    {
        printf("element at position %d is %d\n", pos, q->arr[q->f + pos]);
    }
}

int main()
{
    Q q;
    q.size = 5;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    enq(&q, 7);
    enq(&q, 33);
    enq(&q, 76);
    enq(&q, 4);
    enq(&q, 80);

    display(&q);

    peek(&q, 2);

    int val = deQ(&q);
    printf("Dequeuing element is %d\n", val);
    val = deQ(&q);
    printf("Dequeuing element is %d\n", val);

    display(&q);
    peek(&q, 2);

    return 0;
}