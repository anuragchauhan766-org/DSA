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
void levelordertraversal(node *root)
{
    if (!root)
    {
        return;
    }
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp != NULL)
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
        else if (!q.empty())
        {
            cout << "\n";
            q.push(NULL);
        }
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
    root->right->left = new node(6);
    root->right->right = new node(7);
    /*
                1
              /   \
             2     3
            / \   / \
           4   5 6   7

  */
    // preorder(root);
    // postorder(root);
    // inorder(root);
    levelordertraversal(root);

    return 0;
}