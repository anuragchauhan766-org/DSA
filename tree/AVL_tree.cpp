#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class node
{
public:
    int key;
    node *left;
    node *right;
    int height;
    node()
    {
        this->key = 0;
        this->left = NULL;
        this->right = NULL;
        this->height = 1;
    }
    node(int key)
    {
        this->key = key;
        this->left = NULL;
        this->right = NULL;
        this->height = 1;
    }
    int getbf()
    {
        if (this->left == NULL && this->right == NULL)
        {
            return 0;
        }

        return (this->left->height) - (this->right->height);
    }

    friend class AVL;
};
class AVL
{

public:
    node *root;
    AVL()
    {
        this->root = NULL;
    }
    node *insert(node *a, int key)
    {
        if (a == NULL)
        {
            node *newnode = new node(key);
            return;
        }
        if (key < a->right->key)
        {
            a->right = insert(a->right, key);
        }
    }
};

node *rightRotate(node *y)
{
    node *x = y->left;
    node *t2 = x->right;

    x->right = y;
    y->left = t2;
    y->height = max(y->left->height, y->right->height) + 1;
    x->height = max(x->left->height, x->right->height) + 1;
    return x;
}
node *leftRotate(node *x)
{
    node *y = x->right;
    node *t2 = y->left;

    y->left = x;
    x->right = t2;
    x->height = max(x->left->height, x->right->height) + 1;
    y->height = max(y->left->height, y->right->height) + 1;
    return y;
}

int main()
{

    return 0;
}