/* This program shows the various types of deletion in Linked lists in C */

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

node *delete_beg(node *head)
{
    node *ptr = head;
    head = ptr->next;                                       // Deleting first node
    free(ptr);
    return head;
}

node *delete_index(node *head, int index)
{
    node *p = head;
    for (int i = 0; i != index - 1; i++)
    {                                                         // Deleting node at given index
        p = p->next;
    }

    node *ptr = p->next;
    p->next = ptr->next;
    free(ptr);
}

node *delete_end(node *head)
{
    node *p = head;
    node *ptr = head->next;
    for (int i = 0; ptr->next != NULL; i++)                    // Deleting last node
    {
        ptr = ptr->next;
        p = p->next;
    }
    p->next = NULL;
    free(ptr);
}

node *delete_val(node *head, int data)
{
    node *p = head;
    node *ptr = head->next;
    for (int i = 0; ptr->data != data && ptr->next != NULL; i++)       // Deleting node of given value
    {
        ptr = ptr->next;
        p = p->next;
    }
    if (ptr->data == data)
    {
        p->next = ptr->next;
        free(ptr);
    }
}

int main()
{
    node *head;
    node *second;
    node *third;
    node *fourth;
    node *fifth;
    node *sixth;
    node *seventh;

    head = (node *)malloc(sizeof(node));
    second = (node *)malloc(sizeof(node));
    third = (node *)malloc(sizeof(node));
    fourth = (node *)malloc(sizeof(node));
    fifth = (node *)malloc(sizeof(node));
    sixth = (node *)malloc(sizeof(node));
    seventh = (node *)malloc(sizeof(node));

    head->data = 7;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 8;
    third->next = fourth;

    fourth->data = 65;
    fourth->next = fifth;

    fifth->data = 34;
    fifth->next = sixth;

    sixth->data = 8;
    sixth->next = seventh;

    seventh->data = 65;
    seventh->next = NULL;

    printf("\nBefore deletion\n");
    traverse(head);

    head = delete_beg(head);
    printf("\nAfter deletion at the beginning\n");
    traverse(head);

    delete_index(head, 2);
    printf("\nAfter deletion at the index\n");
    traverse(head);

    delete_end(head);
    printf("\nAfter deletion at the end\n");
    traverse(head);

    delete_val(head, 8);
    printf("\nAfter deletion at given value\n");
    traverse(head);

    return 0;
}