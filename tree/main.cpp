//
//  main.cpp
//  tree
//
//  Created by Swapnil Bhalerao on 18/09/21.
//  Question: Lowest common Ancester in Binary Tree.

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
    Node *lowestCommonAncester(Node *, int, int);
};

Tree::Tree() : mpRoot(nullptr)
{
}
void Tree::createTree()
{
    mpRoot = new Node(1);

    mpRoot->left = new Node(2);
    mpRoot->left->left = new Node(4);
    mpRoot->left->right = new Node(5);

    mpRoot->right = new Node(3);
    mpRoot->right->left = new Node(6);
    mpRoot->right->right = new Node(7);
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

Node *Tree::lowestCommonAncester(Node *root, int a, int b)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (root->data == a || root->data == b)
    {
        return root;
    }

    Node *leftSearch = lowestCommonAncester(root->left, a, b);
    Node *rightSearch = lowestCommonAncester(root->right, a, b);

    if (leftSearch != nullptr && rightSearch != nullptr)
    {
        return root;
    }

    return leftSearch != nullptr ? leftSearch : rightSearch;
}

int main(int argc, const char *argv[])
{
    // insert code here...
    Tree t;
    t.createTree();

    std::cout << "In-order => ";
    t.inOrder(t.getRoot());
    cout << endl;

    cout << "Enter Two nodes" << endl;
    int a, b;
    cin >> a >> b;
    Node *commonAncester = t.lowestCommonAncester(t.getRoot(), a, b);
    cout << "Lowest common Ancester == " << commonAncester->data << endl;
    return 0;
}
