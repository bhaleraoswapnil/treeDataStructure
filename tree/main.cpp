//
//  main.cpp
//  tree
//
//  Created by Swapnil Bhalerao on 18/09/21.
//  Question: Tree level order traversal in spiral order.

#include <iostream>
#include <queue>
#include <stack>
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
    void level_order_traversal_reverse(Node *);
    void level_order_traversal_spiral(Node *);
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
    cout << endl;
}
void Tree::level_order_traversal_reverse(Node *root)
{
    std::stack<int> st;
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
        st.push(temp->data);
        if (temp->right != nullptr)
        {
            q.push(temp->right);
        }
        if (temp->left != nullptr)
        {
            q.push(temp->left);
        }
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}
void Tree::level_order_traversal_spiral(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    std::stack<Node *> st1;
    std::stack<Node *> st2;
    st1.push(root);
    while (!st1.empty() || !st2.empty())
    {
        while (!st1.empty())
        {
            Node *temp = st1.top();
            st1.pop();
            cout << temp->data << " ";
            if (temp->left)
            {
                st2.push(temp->left);
            }
            if (temp->right)
            {
                st2.push(temp->right);
            }
        }

        while (!st2.empty())
        {
            Node *temp = st2.top();
            st2.pop();
            cout << temp->data << " ";
            if (temp->right)
            {
                st1.push(temp->right);
            }
            if (temp->left)
            {
                st1.push(temp->left);
            }
        }
    }
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
    cout << "order_traversal: ";
    t.level_order_traversal(t.getRoot());

    cout << "order_traversal_reverse: ";
    t.level_order_traversal_reverse(t.getRoot());

    cout << "order_traversal_spiral: ";
    t.level_order_traversal_spiral(t.getRoot());
    cout << endl;
    return 0;
}
