/* Program to insert a given element in Binary Search Tree in C */

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

Node *insert(Node *root, int key)
{
    Node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            printf("Cannot insert...Element already exists in BST\n");
            return NULL;
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
    Node *new = createNode(key);
    if (key < prev->data)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
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

    insert(p, 2);
    printf("%d",p->left->left->right->data);

    return 0;
}
