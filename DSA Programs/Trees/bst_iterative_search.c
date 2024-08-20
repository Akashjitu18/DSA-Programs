/* Program to search whether a given element is present in Binary Search Tree or not using iterative search in C */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} Node;

Node *createNode(int data)
{
    Node *n;
    n = (Node *)malloc(sizeof(Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
}

int search(Node *root, int key)
{
    while (root != NULL)
    {
        if (key == root->data)
        {
            return 1;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return 0;
}

int main()
{
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);
    // The tree looks like this:
    //      5
    //     / \
    //    3   6
    //   / \
    //  1   4

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    if (search(p, 9))
    {
        printf("Element is present \n");
    }
    else
    {
        printf("Element is not present \n");
    }

    return 0;
}
