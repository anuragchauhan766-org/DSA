
#include <iostream>
#include <climits>
using namespace std;
class BST
{
public:
    int data;
    BST *left, *right;
    BST(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
int min(BST *root)
{
    BST *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->data;
}
int max(BST *root)
{
    BST *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp->data;
}
bool search(BST *root, int value)
{

    // todo:  recursive way
    /*
    if (root == NULL)
    {
        return false;
    }
    if (root->data == value)
    {
        return true;
    }
    else if (root->data > value)
    {
        return search(root->left, value);
    }
    else
    {
        return search(root->right, value);
    }
    */

    // iterative way

    BST *temp = root;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            return true;
        }
        if (temp->data > value)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    return false;
}
BST *insertBST(BST *root, int value)
{
    if (root == NULL)
    {
        return new BST(value);
    }

    if (value < root->data)
    {
        // insert value to the left of node
        root->left = insertBST(root->left, value);
    }
    else if (value > root->data)
    {
        // insert value to the right of node
        root->right = insertBST(root->right, value);
    }
    return root;
}
void inorder(BST *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

BST *Deletenode(BST *root, int value)
{

    if (root == NULL)
    {
        return root;
    }

    if (root->data == value)
    {
        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 1 child

        // left child
        if (root->left != NULL && root->right == NULL)
        {
            BST *temp = root->left;
            delete root;
            return temp;
        }
        // right child
        if (root->right != NULL && root->left == NULL)
        {
            BST *temp = root->right;
            delete root;
            return temp;
        }
        // 2 child

        if (root->right != NULL && root->left != NULL)
        {
            int minvvalue = min(root->right);
            root->data = minvvalue;
            root->right = Deletenode(root->right, minvvalue);
            return root;
        }
    }
    else if (root->data > value)
    {
        root->left = Deletenode(root->left, value);
    }
    else
    {
        root->right = Deletenode(root->right, value);
    }
    return root;
}

bool isBST(BST *root, int min, int max)
{
    if (root == NULL)
    {
        return 1;
    }
    if (root->data >= max && root->data <= min)
    {
        bool left = isBST(root->left, min, root->data);
        bool right = isBST(root->right, root->data, max);
        return left && right;
    }

    else
    {
        return 0;
    }
}
int main()
{
    BST *root = NULL;
    root = insertBST(root, 5);
    insertBST(root, 3);
    insertBST(root, 8);
    insertBST(root, 10);
    insertBST(root, 6);
    insertBST(root, 9);
    // insertBST(root, 9);

    inorder(root);
    // cout << endl
    //      << search(root, 0);
    // cout << endl
    //      << min(root);
    // cout << endl
    //      << max(root);
    // root = Deletenode(root, 10);
    // cout << endl;
    // inorder(root);
    // cout << endl;
    // cout << isBST(root, INT_MIN, INT_MAX);
    return 0;
}