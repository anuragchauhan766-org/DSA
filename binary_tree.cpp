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

int main()
{
    node *root = new node(1);
    node *left = new node(2);
    node *right = new node(3);
    root->left = left;
    root->right = right;

    return 0;
}