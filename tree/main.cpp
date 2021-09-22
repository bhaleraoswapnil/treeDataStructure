//
//  main.cpp
//  tree
//
//  Created by Swapnil Bhalerao on 18/09/21.
//

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
    void preOrder(Node *);
    void postOrder(Node *);
    void inOrder(Node *);
};
Tree::Tree() : mpRoot(nullptr)
{
    createTree();
}
void Tree::createTree()
{
    mpRoot = new Node(10);
    mpRoot->left = new Node(2);
    mpRoot->left->left = new Node(6);

    mpRoot->right = new Node(5);
    mpRoot->right->left = new Node(8);
    mpRoot->right->right = new Node(3);
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

void Tree::preOrder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void Tree::postOrder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main(int argc, const char *argv[])
{
    // insert code here...
    std::cout << "Hello, World!\n";
    Tree t;
    std::cout << "In-order => ";
    t.inOrder(t.getRoot());
    cout << endl;
    
    std::cout << "Pre-order => ";
    t.preOrder(t.getRoot());
    cout << endl;
    
    std::cout << "Post-order => ";
    t.postOrder(t.getRoot());
    cout << endl;

    return 0;
}
