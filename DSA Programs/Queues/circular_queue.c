/* This program is for creating Circular Queue using arrays and performing EnQueue and DeQueue operations on Circular Queue in C */

#include <stdio.h>
#include <stdlib.h>

typedef struct circularQueue
{
    int size;
    int f;
    int r;
    int *arr;

} CQ;

int isFull(CQ *cq)
{
    if ((cq->r + 1) % cq->size == cq->f)
    {
        return 1;
    }
    else
        return 0;
}

int isEmpty(CQ *cq)
{
    if (cq->r == cq->f)
    {
        return 1;
    }
    else
        return 0;
}

void enq(CQ *cq, int val)
{
    if (isFull(cq))
    {
        printf("CQ is Full...cannot enQ\n");
    }
    else
    {
        cq->r = (cq->r + 1) % cq->size;
        cq->arr[cq->r] = val;
        printf("Enqued element: %d\n", val);
    }
}

int deQ(CQ *cq)
{
    int val = -1;
    if (isEmpty(cq))
    {
        printf("Q is Empty...cannot deQ\n");
    }
    else
    {
        cq->f = (cq->f + 1) % cq->size;
        val = cq->arr[cq->f];
    }
    return val;
}

void display(CQ *cq)
{
    if (isEmpty(cq))
    {
        printf("Q is Empty\n");
    }
    else
    {
        printf("Elements of circular Q are \n");
        for (int i = cq->f + 1; i != (cq->r + 1) % cq->size; i = (i + 1) % cq->size)
        {
            printf("%d ", cq->arr[i]);
        }
        printf("\n");
    }
}

int main()
{
    CQ cq;
    cq.size = 5;
    cq.f = cq.r = 0;
    cq.arr = (int *)malloc(cq.size * sizeof(int));

    enq(&cq, 7);
    enq(&cq, 33);
    enq(&cq, 76);
    enq(&cq, 4);
    // enq(&cq, 80);

    display(&cq);

    int val = deQ(&cq);
    printf("Dequeuing element is %d\n", val);
    val = deQ(&cq);
    printf("Dequeuing element is %d\n", val);

    display(&cq);

    enq(&cq, 99);
    enq(&cq, 98);

    display(&cq);

    return 0;
}