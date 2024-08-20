/* This program shows the creation and traversal in Doubly linked lists in C */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;

void traverse(node *head)
{
    node *ptr = head;
    node *ptr2 = head->next;
    int i = 0;
    while (ptr2 != NULL)
    {
        printf("Element of Node %d is %d\n", i + 1, ptr->data);
        ptr = ptr->next;
        ptr2 = ptr2->next;
        i++;
    }
    printf("Element of Node %d is %d\n", i + 1, ptr->data);

    printf("\nReverse order is \n");

    while (ptr != NULL)
    {
        printf("Element of Node %d is %d\n", i + 1, ptr->data);
        ptr = ptr->prev;
        i--;
    }
}

int main()
{
    node *head;
    node *second;
    node *third;
    node *fourth;
    node *fifth;

    head = (node *)malloc(sizeof(node));
    second = (node *)malloc(sizeof(node));
    third = (node *)malloc(sizeof(node));
    fourth = (node *)malloc(sizeof(node));
    fifth = (node *)malloc(sizeof(node));

    head->data = 7;
    head->next = second;
    head->prev = NULL;

    second->data = 11;
    second->next = third;
    second->prev = head;

    third->data = 8;
    third->next = fourth;
    third->prev = second;

    fourth->data = 65;
    fourth->next = fifth;
    fourth->prev = third;

    fifth->data = 85;
    fifth->next = NULL;
    fifth->prev = fourth;

    traverse(head);
    return 0;
}