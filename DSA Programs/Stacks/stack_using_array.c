/* This program is for creating stack using arrays and performing push and pop operations on stack in C */

#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int size;
    int top;
    int *arr;
} stack;

int isEmpty(stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(stack *ptr, int element)
{
    if (isFull(ptr))
    {
        printf("Stack is full...You cannot push\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = element;
    }
}

int pop(stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack is Empty...You cannot pop\n");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

void display(stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack is Empty\n");
    }
    for (int i = 0; i <= ptr->top; i++)
    {
        printf("Element %d : %d\n", i + 1, ptr->arr[i]);
    }
}

int peek(stack *stk, int pos)
{
    int ind = stk->top - pos + 1;
    if (ind < 0)
    {
        printf("Invalid position\n");
        return -1;
    }
    else
    {
        printf("Element at postion %d : %d\n", pos, stk->arr[ind]);
    }
}

int stackTop(stack *stk)
{
    return stk->arr[stk->top];
}

int stackBottom(stack *stk)
{
    return stk->arr[0];
}

int main()
{
    stack *s = (stack *)malloc(sizeof(stack));
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    push(s, 8);
    push(s, 65);
    push(s, 85);
    push(s, 23);
    push(s, 33);
    // push(s, 93); // overflow

    display(s);

    for (int i = 1; i <= s->top + 1; i++)
    {
        peek(s, i);
    }

    printf("The top most element of stack is %d\n", stackTop(s));
    printf("The bottom most element of stack is %d\n", stackBottom(s));

    // pop(s);
    // pop(s);
    // pop(s);
    // pop(s);
    // pop(s);
    // pop(s);   // underflow

    // printf("After pop\n");
    // display(s);

    return 0;
}