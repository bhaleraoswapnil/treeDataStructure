//
//  main.cpp
//  tree
//
//  Created by Swapnil Bhalerao on 18/09/21.
//  Question: Same Tree

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
    bool sameTree(Node *, Node *);
    void createTree1();
    void createTree2();
};
Tree::Tree() : mpRoot(nullptr)
{
}
void Tree::createTree1()
{
    mpRoot = new Node(10);
    mpRoot->left = new Node(-5);
    mpRoot->left->left = new Node(-10);
    mpRoot->left->right = new Node(0);
    mpRoot->left->right->right = new Node(5);

    mpRoot->right = new Node(30);
    mpRoot->right->right = new Node(36);
}
void Tree::createTree2()
{
//    create not same tree
//    mpRoot = new Node(10);
//    mpRoot->left = new Node(-5);
//    mpRoot->left->left = new Node(-10);
//    mpRoot->left->right = new Node(0);
//    mpRoot->left->right->right = new Node(5);
//
//    mpRoot->right = new Node(30);
//    mpRoot->right->left = new Node(15);
//    mpRoot->right->right = new Node(36);
    
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

bool Tree::sameTree(Node *root1, Node *root2)
{
    if (root1 == nullptr && root2 == nullptr)
    {
        return true;
    }
    if (root1 == nullptr || root2 == nullptr)
    {
        return false;
    }

    return (root1->data == root2->data) && sameTree(root1->left, root2->left) && sameTree(root1->right, root2->right);
}
int main(int argc, const char *argv[])
{
    // insert code here...
    std::cout << "Compare Two Tree\n";
    Tree t1, t2;
    t1.createTree1();
    t2.createTree2();
    std::cout << "In-order => ";
    t1.inOrder(t1.getRoot());
    std::cout << "\nIn-order => ";
    t2.inOrder(t2.getRoot());
    cout << endl;
    if (t1.sameTree(t1.getRoot(), t2.getRoot()))
    {
        cout << "Both Tree's are same" << endl;
    }
    else
    {
        cout << "Tree's are not same" << endl;
    }

    return 0;
}
