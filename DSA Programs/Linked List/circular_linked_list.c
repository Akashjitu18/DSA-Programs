/* This program shows the insertion at the head node in Circular Linked lists in C */

#include <stdio.h>
#include <stdlib.h>

typedef struct noode
{
    int data;
    struct node *next;

} node;

void traversal(node *head)
{
    node *ptr = head;
    int i = 0;
    do
    {
        printf("Element of Node %d is %d\n", i + 1, ptr->data);
        ptr = ptr->next;
        i++;
    } while (ptr != head);
}

node *insertion(node *head, int value)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = value;
    node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }

    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
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

    second->data = 11;
    second->next = third;

    third->data = 8;
    third->next = fourth;

    fourth->data = 65;
    fourth->next = fifth;

    fifth->data = 34;
    fifth->next = head;

    printf("\nBefore Insertion\n");
    traversal(head);

    head = insertion(head, 96);
    printf("\nAfter Insertion\n");
    traversal(head);

    return 0;
}