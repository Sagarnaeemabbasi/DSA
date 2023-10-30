#include <iostream>
using namespace std;
struct BstNode
{
    struct BstNode *left;
    struct BstNode *right;
    int data;
};

struct BstNode *leftRotate(struct BstNode *root)
{
    struct BstNode *temp = root->right;
    root->right = temp->left;
    temp->left = root;
    return temp;
}
struct BstNode *rightRotate(struct BstNode *root)
{
    struct BstNode *temp = root->left;
    root->left = temp->right;
    temp->right = root;
    return temp;
}
struct BstNode *leftRightRotate(struct BstNode *root)
{
    root->left = leftRotate(root->left);
    root = rightRotate(root);
    return root;
}
struct BstNode *rightLeftRotate(struct BstNode *root)
{
    root->right = rightRotate(root->right);
    root = leftRotate(root);
    return root;
}

// int tree_height(struct BstNode *root)
// {
//     if (root == nullptr)
//     {
//         return 0;
//     }
//     else if (root->left == nullptr && root->right == nullptr)
//     {
//         return 0;
//     }
//     else
//     {
//         // Find the height of left, right subtrees
//         int left_height = tree_height(root->left);
//         int right_height = tree_height(root->right);

//         // Find max(subtree_height) + 1 to get the height of the tree
//         return max(left_height, right_height) + 1;
//     }
// }
int tree_height(struct BstNode *node)
{
    if (node == nullptr)
        return 0;
    else
    {
        int left_side;
        int right_side;
        left_side = tree_height(node->left);
        right_side = tree_height(node->right);
        if (left_side > right_side)
        {
            return left_side + 1;
        }
        else
            return right_side + 1;
    }
}

int getBalance(BstNode *N)
{
    if (N == nullptr)
        return 0;
    return (tree_height(N->left) - tree_height(N->right));
}

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
    }
    else if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        // Duplicate value, no change needed
        return root;
    }

    // Update balance factor
    int balance = getBalance(root);

    // Balancing logic
    if (balance > 1 && data < root->left->data)
        return rightRotate(root);

    // Right Right Case
    if (balance < -1 && data > root->right->data)
        return leftRotate(root);

    // Left Right Case
    if (balance > 1 && data > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if (balance < -1 && data < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
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

    // Update balance factor
    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}
// Find height of a tree, defined by the root node

void inOrder(struct BstNode *root)
{
    if (root != nullptr)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
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
struct BstNode *balance(struct BstNode *root)
{
    int bal = getBalance(root);
    cout << bal << endl;
    if (bal < -1)
    {
        root = leftRotate(root);
        cout << "left Shift" << endl;
        return root;
    }
    else if (bal > 1)
    {
        root = rightRotate(root);
        cout << "right Shift" << endl;
        return root;
    }
    else
    {
        cout << "No shift needed !!" << endl;
        return root;
    }
}

int main()
{
    BstNode *root = nullptr;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);
    // root = insert(root, 45);
    // root = insert(root, 57);
    // root = insert(root, 98);
    root = deleteNode(root, 2);
    printPreorder(root);

    return 0;
}