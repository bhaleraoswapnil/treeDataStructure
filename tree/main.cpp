//
//  main.cpp
//  tree
//
//  Created by Swapnil Bhalerao on 18/09/21.
//  Question: Tree level order traversal

#include <iostream>
#include <queue>
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
    void level_order_traversal(Node *);
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

void Tree::level_order_traversal(Node *root)
{
    std::queue<Node *> q;
    if (root == nullptr)
    {
        return;
    }
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left != nullptr)
        {
            q.push(temp->left);
        }
        if (temp->right != nullptr)
        {
            q.push(temp->right);
        }
    }
    cout<<endl;
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
    t.level_order_traversal(t.getRoot());

    return 0;
}
