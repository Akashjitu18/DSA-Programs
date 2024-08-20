/* Program to delete a given element in Binary Search Tree in C */

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

void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

Node *inOrderPredecessor(Node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

Node *deleteNode(Node *root, int value)
{

    Node *inPre;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }

    // searching for the node to be deleted
    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }

    // deletion strategy when the node is found
    else
    {
        inPre = inOrderPredecessor(root);
        root->data = inPre->data;
        root->left = deleteNode(root->left, inPre->data);
    }
    return root;
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

    inOrder(p);
    deleteNode(p, 5);
    printf("\n");
    inOrder(p);

    return 0;
}
