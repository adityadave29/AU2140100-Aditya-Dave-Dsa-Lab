#include <bits/stdc++.h>
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

BinaryTreeNode *takeinput_levelwise()
{
    int rootdata;
    cin >> rootdata;
    BinaryTreeNode *root = new BinaryTreeNode(rootdata);
    queue<BinaryTreeNode *> pendingNodes;
    pendingNodes.push(root);

    while (!pendingNodes.empty())
    {
        BinaryTreeNode *front = pendingNodes.front();
        pendingNodes.pop();

        cout << "Enter left child data of " << front->data << endl;
        int leftchilddata;
        cin >> leftchilddata;

        if (leftchilddata != -1)
        {
            BinaryTreeNode *child = new BinaryTreeNode(leftchilddata);
            front->left = child;
            pendingNodes.push(child);
        }
        cout << "Enter right child data of " << front->data << endl;

        int rightchilddata;
        cin >> rightchilddata;

        if (rightchilddata != -1)
        {
            BinaryTreeNode *child = new BinaryTreeNode(rightchilddata);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
};

bool Breadth_search(BinaryTreeNode *root, int ele)
{
    queue<BinaryTreeNode *> q1;
    q1.push(root);

    while (!q1.empty())
    {
        BinaryTreeNode *front = q1.front();
        q1.pop();
        if (front->data == ele)
        {
            return true;
        }
        else
        {
            if (front->left != NULL)
            {
                q1.push(front->left);
            }
            if (front->right != NULL)
            {
                q1.push(front->right);
            }
        }
    }
    return false;
}

int main()
{
    BinaryTreeNode *root = takeinput_levelwise();
    printTree(root);

    if (Breadth_search(root, 4) == true)
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
    return 0;
}