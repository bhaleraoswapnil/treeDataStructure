//
//  main.cpp
//  tree
//
//  Created by Swapnil Bhalerao on 18/09/21.
//  Question: Root to leaf Sum Binary Tree

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
    bool sumBinaryTree(Node *, std::vector<int> &, int);
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
bool Tree::sumBinaryTree(Node *root, std::vector<int> &vec, int sum)
{
    if (root == nullptr)
    {
        return false;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        if (root->data == sum)
        {
            vec.push_back(root->data);
            return true;
        }
        else
        {
            return false;
        }
    }
    if (sumBinaryTree(root->left, vec, sum - root->data))
    {
        vec.push_back(root->data);
        return true;
    }
    if (sumBinaryTree(root->right, vec, sum - root->data))
    {
        vec.push_back(root->data);
        return true;
    }
    return false;
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
    std::vector<int> vec;
    int sum = 0;
    cout << "Enter sum to check " << endl;
    cin >> sum;
    if (t.sumBinaryTree(t.getRoot(), vec, sum))
    {
        cout << "Yes .. Sum Binary Tree and Path is ...";
        for (auto i : vec)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "No .. Sum Binary Tree" << endl;
    }
    return 0;
}
