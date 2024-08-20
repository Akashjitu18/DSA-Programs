/* This program is for converting infix expression to postfix expression using stack in C */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int stackTop(stack *stk)
{
    return stk->arr[stk->top];
}

int prec(char ch)
{
    if (ch == '*' || ch == '/')
        return 3;
    else if (ch == '+' || ch == '-')
        return 2;
    else
        return 0;
}

int isOperator(char ch)
{
    if (ch == '*' || ch == '/' || ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

char *infixTOPostfix(char *infix)
{
    stack *s = (stack *)malloc(sizeof(stack));
    s->size = 100;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    char *postfix = (char *)malloc(strlen(infix) * sizeof(char));
    int i = 0; // to track infix
    int j = 0; // to track postfix

    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else
        {
            if (prec(infix[i]) > prec(stackTop(s)))
            {
                push(s, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(s);
                j++;
            }
        }
    }
    while (!isEmpty(s))
    {
        postfix[j] = pop(s);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char *infix = "x-y/z-k*d";
    printf("Postfix expression = %s ", infixTOPostfix(infix));

    return 0;
}
