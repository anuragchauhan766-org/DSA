
#include <iostream>
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

int main()
{
    BST *root = NULL;
    root = insertBST(root, 5);
    insertBST(root, 3);
    insertBST(root, 8);
    insertBST(root, 1);
    insertBST(root, 6);
    insertBST(root, 9);

    inorder(root);
    return 0;
}