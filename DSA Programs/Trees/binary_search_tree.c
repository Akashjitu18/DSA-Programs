/* Program to check whether a given Binary tree is a Binary Search Tree or not in C  */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} Node;

void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left); // In-order traversal
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int isBST(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}

Node *createNode(int data)
{
    Node *n;
    n = (Node *)malloc(sizeof(Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
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

    printf("The in order is : ");
    inOrder(p);
    printf("\n");

    if (isBST(p))
    {
        printf("This is a BST");
    }
    else
    {
        printf("This is not a BST");
    }

    return 0;
}
