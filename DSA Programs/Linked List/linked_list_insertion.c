/* This program shows the various types of insertion in Linked lists in C */

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

node *insert_beg(node *head, int data)
{
    node *ptr = (node *)malloc(sizeof(node));                 // Insertion at the beginning
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

void insert_end(node *head, int data)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = data;
    node *p = head;
                                                              // Insertion at the end
    for (int i = 0; p->next != NULL; i++)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
}

void insert_index(node *head, int data, int index)
{
    node *ptr = (node *)malloc(sizeof(node));
    node *p = head;
    for (int i = 0; i != index - 1; i++)                        // Insertion at a given index
    {
        p = p->next;
    }
    ptr->next = p->next;
    ptr->data = data;
    p->next = ptr;
}

void insert_after_node(node *node1, int data)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = data;                                            // Insertion after a given node
    ptr->next = node1->next;
    node1->next = ptr;
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

    printf("\nBefore Insertion \n");
    traverse(head);

    head = insert_beg(head, 89);
    printf("\nAfter Insertion at the beginning\n");
    traverse(head);

    insert_end(head, 25);
    printf("\nAfter Insertion at the end\n");
    traverse(head);

    insert_index(head, 48, 2);
    printf("\nAfter Insertion at the index 2\n");
    traverse(head);

    insert_after_node(second, 38);
    printf("\nAfter Insertion after the node\n");
    traverse(head);

    return 0;
}