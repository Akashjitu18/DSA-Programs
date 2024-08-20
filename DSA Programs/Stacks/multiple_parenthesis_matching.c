/* This program is for checking the balanced parenthesis of an expression using stack in C */

#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int size;
    int top;
    char *arr;
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

void push(stack *ptr, char element)
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

char pop(stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack is Empty...You cannot pop\n");
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int match(char a, char b)
{
    if (a == '(' && b == ')')
    {
        return 1;
    }
    if (a == '{' && b == '}')
    {
        return 1;
    }
    if (a == '[' && b == ']')
    {
        return 1;
    }
    return 0;
}

int parenthesisMatch(char *exp)
{
    stack *s = (stack *)malloc(sizeof(stack));
    s->size = 100;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));
    char popped_ch;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(s, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(s))
            {
                return 0;
            }
            popped_ch = pop(s);
            if (!match(popped_ch, exp[i]))
            {
                return 0;
            }
        }
    }
    if (isEmpty(s))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char *exp = "[[4-6]]((8){(9-8)})";
    if (parenthesisMatch(exp))
    {
        printf("The paranthesis are balanced\n");
    }
    else
    {
        printf("The paranthesis are not balanced\n");
    }

    return 0;
}