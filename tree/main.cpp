//
//  main.cpp
//  tree
//
//  Created by Swapnil Bhalerao on 18/09/21.
//  Question: Search key in Binary Search Tree (BST).

#include <iostream>
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
    void createTree();

public:
    Tree();
    Node *getRoot() { return mpRoot; }
    void inOrder(Node *);
    bool keySearch(Node *, int);
};
Tree::Tree() : mpRoot(nullptr)
{
    createTree();
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
bool Tree::keySearch(Node *root, int key)
{
    if (root == nullptr)
    {
        return false;
    }
    if (root->data == key)
    {
        return true;
    }
    else if (root->data > key)
    {
        return keySearch(root->left, key);
    }
    else
    {
        return keySearch(root->right, key);
    }
    return false;
}
int main(int argc, const char *argv[])
{
    // insert code here...
    std::cout << "Hello, World!\n";
    Tree t;
    std::cout << "In-order => ";
    t.inOrder(t.getRoot());
    cout << endl;
    cout << "Enter key to be searched " << endl;
    int key = 0;
    cin >> key;
    if (t.keySearch(t.getRoot(), key))
    {
        cout << "Key Found in BST" << endl;
    }
    else
    {
        cout << "Key Not Found in BST" << endl;
    }
    return 0;
}
