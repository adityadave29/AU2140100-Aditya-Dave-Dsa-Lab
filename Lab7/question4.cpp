#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class BinaryTreeNode
{
public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class tree
{
    BinaryTreeNode *root;

public:
    tree()
    {
        root = NULL;
    }

private:
    BinaryTreeNode *insert_helper(BinaryTreeNode *node, int data)
    {
        if (node == NULL)
        {
            BinaryTreeNode *newnode = new BinaryTreeNode(data);
            return newnode;
        }

        if (data < node->data)
        {
            node->left = insert_helper(node->left, data);
            cout << "node inserted" << endl;
        }
        else if (data > node->data)
        {
            node->right = insert_helper(node->right, data);
            cout << "node inserted" << endl;
        }

        return node;
    }

    void printTree(BinaryTreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        cout << root->data << ":";
        if (root->left != NULL)
        {
            cout << "L" << root->left->data;
        }

        if (root->right != NULL)
        {
            cout << "R" << root->right->data;
        }
        cout << endl;
        printTree(root->left);
        printTree(root->right);
    }

    BinaryTreeNode *remove_helper(BinaryTreeNode *root, int data)
    {
        if (root == NULL)
            return NULL;

        if (root->data == data)
        {
            if (root->left == NULL && root->right == NULL)
            {
                return NULL;
            }
            else if (root->left != NULL && root->right == NULL)
            {
                return root->left;
            }
            else if (root->left == NULL && root->right != NULL)
            {
                return root->right;
            }
            else
            {
                BinaryTreeNode *temp = root->right;

                while (temp->left != NULL)
                {
                    temp = temp->left;
                }

                root->data = temp->data;
                root->right = remove_helper(root->right, temp->data);

                return root;
            }
        }
        else if (data < root->data)
        {
            root->left = remove_helper(root->left, data);
        }
        else
        {
            root->right = remove_helper(root->right, data);
        }

        return root;
    }

public:
    void insert(int data)
    {
        root = insert_helper(root, data);
    }

    void printTree()
    {
        printTree(root);
    }

    void remove(int data)
    {
        this->root = remove_helper(root, data);
    }
};

int main()
{

    tree tree;

    tree.insert(5);
    tree.insert(9);
    tree.insert(3);

    tree.insert(2);
    tree.insert(15);
    tree.insert(25);

    tree.printTree();
    cout << endl;

    tree.remove(25);
    tree.printTree();

    return 0;
}