#include <iostream>
using namespace std;
struct BstNode
{
    struct BstNode *left;
    struct BstNode *right;
    int data;
};
struct BstNode *insert(struct BstNode *root, int data)
{
    if (root == nullptr)
    {
        struct BstNode *temp = new BstNode();
        temp->data = data;
        temp->right = nullptr;
        temp->left = nullptr;
        return temp;
    }
    if (data > root->data)
    {
        root->right = insert(root->right, data);
        return root;
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
        return root;
    }
    return nullptr;
}
// struct BstNode *search(struct BstNode *root, int toFindData)
// {
//     struct BstNode *temp = new BstNode();
//     if (root == nullptr)
//     {
//         cout << "Empty Tree Or Value not found" << endl;
//     }
//     if (root->data == toFindData)
//     {
//         cout << " Found !! " << endl;
//         temp = root;
//         return temp;
//     }
//     if (toFindData > root->data)
//     {
//         search(root->right, toFindData);
//         return;
//     }
//     if (toFindData < root->data)
//     {
//         search(root->left, toFindData);
//         return;
//     }
//}
struct BstNode *deleteNode(struct BstNode *root, int data)
{
    if (root == nullptr)
    {
    }
    if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
        return root;
    }
    if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
        return root;
    }
    else
    {
        if (root->left == nullptr)
        {
            struct BstNode *temp = new BstNode();
            temp = root->right;
            free(root);
            return temp;
        }
        if (root->right == nullptr)
        {
            struct BstNode *temp = new BstNode();
            temp = root->left;
            free(root);
            return temp;
        }
        else
        {

            struct BstNode *smallest = new BstNode();
            smallest = root->right;
            while (smallest->left != nullptr)
            {
                smallest = smallest->left;
            }
            root->data = smallest->data;
            root->right = deleteNode(root->right, smallest->data);
            return root;
        }
    }
}
// Find height of a tree, defined by the root node
int tree_height(struct BstNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    else if (root->left == nullptr && root->right == nullptr)
    {
        return 0;
    }
    else
    {
        // Find the height of left, right subtrees
        int left_height = tree_height(root->left);
        int right_height = tree_height(root->right);

        // Find max(subtree_height) + 1 to get the height of the tree
        return max(left_height, right_height) + 1;
    }
}
int getBalance(BstNode *N)
{
    if (N == nullptr)
        return 0;
    return (tree_height(N->left) - tree_height(N->right));
}
void printPreorder(struct BstNode *node)
{
    if (node == NULL)
        return;

    // First print data of node
    cout << node->data << " ";

    // Then recur on left subtree
    printPreorder(node->left);

    // Now recur on right subtree
    printPreorder(node->right);
}
void inOrder(struct BstNode *root)
{
    if (root != nullptr)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}
int main()
{
    BstNode *root = nullptr;
    root = insert(root, 10);
    root = insert(root, 15);
    root = insert(root, 5);
    root = insert(root, 19);
    root = insert(root, 12);
    root = insert(root, 2);
    root = insert(root, 7);
    root = insert(root, 8);
    root = insert(root, 11);
    root = insert(root, 13);
    root = insert(root, 21);
    root = insert(root, 18);
    root = insert(root, 16);
    deleteNode(root, 5);
    inOrder(root);
    cout << root->data << endl;

    return 0;
}