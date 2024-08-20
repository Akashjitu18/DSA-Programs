/* Program to create Binary tree using linked representation in C */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} Node;

// Function to create node
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
    // Creating every node one by one
    /*
    Node *r;
    Node *p1;
    Node *p2;

    r = (Node *)malloc(sizeof(Node));
    r->data = 7;
    r->left = p1;
    r->right = p2;

    p1 = (Node *)malloc(sizeof(Node));
    p1->data = 18;
    p1->left = NULL;
    p1->right = NULL;

    p2 = (Node *)malloc(sizeof(Node));
    p2->data = 45;
    p2->left = NULL;
    p2->right = NULL;
    */

    Node *r = createNode(7);
    Node *p1 = createNode(18);
    Node *p2 = createNode(45);

    // Linking the root node with left and right children

    r->left = p1;
    r->right = p2;

    return 0;
}