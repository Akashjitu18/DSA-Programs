/* This program is for creating stack using linked lists and performing push and pop operations on stack in C */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} stack;

int isEmpty(stack *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
        return 0;
}

int isFull(stack *top)
{
    stack *ptr = (stack *)malloc(sizeof(stack));
    if (ptr == NULL)
    {
        return 1;
    }
    else
        return 0;
}

stack *push(stack *top, int element)
{
    stack *ptr = (stack *)malloc(sizeof(stack));
    if (isFull(ptr))
    {
        printf("Stack is full...\n");
    }
    else
    {
        ptr->data = element;
        ptr->next = top;
        top = ptr;
    }
    return top;
}

int pop(stack **top)
{
    if (isEmpty(*top))
    {
        printf("Stack is Empty...cannot pop\n");
    }
    else
    {
        stack *ptr = *top;
        *top = (*top)->next;
        int val = ptr->data;
        free(ptr);
        return val;
    }
}

void display(stack *top)
{
    if (top == NULL)
    {
        printf("Stack is Empty...\n");
    }
    for (int i = 0; top != NULL; i++)
    {
        printf("Element %d : %d\n", i + 1, top->data);
        top = top->next;
    }
}

int peek(stack *top, int pos)
{
    stack *ptr = top;
    int i = 0;
    while (i < pos - 1)
    {
        ptr = ptr->next;
        i++;
    }
    printf("The element of position %d is %d\n", i + 1, ptr->data);
}

int stackTop(stack *top)
{
    return top->data;
}

int stackBottom(stack *top)
{
while (top->next!=NULL)
{
    top=top->next;
}
return top->data;
}

int main()
{
    stack *top = NULL;

    display(top);

    top = push(top, 7);
    top = push(top, 35);
    top = push(top, 74);
    top = push(top, 8);
    printf("\nAfter push\n");
    display(top);

    int val = pop(&top);
    printf("\nAfter pop\n");
    printf("Popped element %d\n", val);
    display(top);

    printf("\n");

    for (int i = 1; i<4; i++)
    {
        peek(top, i);
    }

    printf("\nThe top most element of stack is %d\n", stackTop(top));
    printf("The bottom most element of stack is %d\n", stackBottom(top));

    return 0;
}
