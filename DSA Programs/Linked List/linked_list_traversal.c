/* This program shows the creation and traversal in Linked lists in C */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void traverse(node *ptr)
{
    for (int i = 1; ptr != NULL; i++)
    {
        printf("Element of Node %d is %d\n", i, ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    node *head;
    node *second;
    node *third;
    node *fourth;

    head = (node *)malloc(sizeof(node));
    second = (node *)malloc(sizeof(node));
    third = (node *)malloc(sizeof(node));
    fourth = (node *)malloc(sizeof(node));

    head->data = 7;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 8;
    third->next = fourth;

    fourth->data = 65;
    fourth->next = NULL;

    traverse(head);

    return 0;
}