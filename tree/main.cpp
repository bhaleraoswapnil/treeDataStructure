//
//  main.cpp
//  tree
//
//  Created by Swapnil Bhalerao on 18/09/21.
//  Question: Size of Binary Tree

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

public:
    Tree();
    Node *getRoot() { return mpRoot; }
    void inOrder(Node *);
    void createTree();
    int sizeofTree(Node *);
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
int Tree::sizeofTree(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return 1 + sizeofTree(root->left) + sizeofTree(root->right);
}
int main(int argc, const char *argv[])
{
    // insert code here...
    std::cout << "Compare Two Tree\n";
    Tree t;
    t.createTree();

    std::cout << "In-order => ";
    t.inOrder(t.getRoot());
    cout << endl;
    cout << "Size of Tree => " << t.sizeofTree(t.getRoot()) << endl;

    return 0;
}
