//
//  main.cpp
//  tree
//
//  Created by Swapnil Bhalerao on 18/09/21.
//  Question: Cheak Binary Tree is Binary Search Tree.

#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    Node *left;
    Node *right;
    int data;
    Node() : left(nullptr), right(nullptr), data(0) {}
    Node(int val) : left(nullptr), right(nullptr), data(val) {}
};

class Tree
{
private:
    Node *mpRoot;

public:
    Tree();
    Node *getRoot() { return mpRoot; }
    void inOrder(Node *);
    void createTree();
    bool checkBST(Node *, int, int);
};
Tree::Tree() : mpRoot(nullptr)
{
}
void Tree::createTree()
{
    mpRoot = new Node(10);
    mpRoot->left = new Node(-5);
    mpRoot->left->left = new Node(-10);
    mpRoot->left->right = new Node(0);
    mpRoot->left->right->right = new Node(5);

    mpRoot->right = new Node(30);
    mpRoot->right->right = new Node(36);
}

void Tree::inOrder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
bool Tree::checkBST(Node *root, int min, int max)
{
    if (root == nullptr)
    {
        return true;
    }
    if (root->data < min || root->data > max)
    {
        return false;
    }
    return checkBST(root->left, min, root->data) && checkBST(root->right, root->data, max);
}

int main(int argc, const char *argv[])
{
    // insert code here...
    std::cout << "Root to leaf Sum Binary Tree\n";

    Tree t;
    t.createTree();

    std::cout << "In-order => ";
    t.inOrder(t.getRoot());
    cout << endl;

    if (t.checkBST(t.getRoot(), INT_MIN, INT_MAX))
    {
        cout << "Yes .. BST" << endl;
    }
    else
    {
        cout << "No .. BST" << endl;
    }
    return 0;
}
