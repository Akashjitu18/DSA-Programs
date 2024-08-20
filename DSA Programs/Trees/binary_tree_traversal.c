/* Program to traverse a Binary tree using linked representation in C */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} Node;

void preOrder(Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data); // Pre-order traversal
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Node *root)
{
    if (root != NULL)
    {
        postOrder(root->left); // Post-order traversal
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left); // In-order traversal
        printf("%d ", root->data);
        inOrder(root->right);
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

Node *buildTree(Node *root)
{

    int data;
    printf("Enter the data : ");
    scanf("%d", &data);

    root = createNode(data);

    if (data == -1)
    {
        return NULL;
    }

    printf("Enter the left node data of node %d \n", data);
    root->left = buildTree(root->left);

    printf("Enter the right node data of node %d \n", data);
    root->right = buildTree(root->right);

    return root;
}

int main()
{
    // struct node *p = createNode(4);
    // struct node *p1 = createNode(1);
    // struct node *p2 = createNode(6);
    // struct node *p3 = createNode(5);
    // struct node *p4 = createNode(2);

    // The tree looks like this:
    //      4
    //     / \
    //    1   6
    //   / \
    //  5   2

    // p->left = p1;
    // p->right = p2;
    // p1->left = p3;
    // p1->right = p4;

    Node *root = NULL;

    root = buildTree(root);

    printf("The pre order is : ");
    preOrder(root);
    printf("\n");

    printf("The post order is : ");
    postOrder(root);
    printf("\n");

    printf("The in order is : ");
    inOrder(root);

    return 0;
}
