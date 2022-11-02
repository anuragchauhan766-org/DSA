#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void preorder(node *root)
{
    if (root != NULL)
    {
        cout << root->data;
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data;
    }
}
void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data;
        inorder(root->right);
    }
}

int main()
{
    // root node of tree
    node *root = new node(1);

    node *left = new node(2);
    node *right = new node(3);
    root->left = left;
    root->right = right;

    /*
                 1
                / \
               2   3

    */
    root->left->left = new node(4);
    root->left->right = new node(5);
    /*
               1
              / \
             2   3
            / \
           4   5

  */
    // preorder(root);
    // postorder(root);
    inorder(root);

    return 0;
}