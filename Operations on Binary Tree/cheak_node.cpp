#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int value;
    Node *right;
    Node *left;
    Node(int value)
    {
        this->value = value;
        this->right = NULL;
        this->left = NULL;
    }
};
Node *input()
{
    int val;
    cin >> val;
    Node *root;
    if (val == -1)
    {
        root = NULL;
    }
    else
    {
        root = new Node(val);
    }
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *parent = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;
        Node *left_subTree, *right_subTree;

        if (l == -1)
            left_subTree = NULL;

        else
            left_subTree = new Node(l);

        if (r == -1)
            right_subTree = NULL;

        else
            right_subTree = new Node(r);

        parent->left = left_subTree;
        parent->right = right_subTree;

        if (parent->left)
            q.push(parent->left);
        if (parent->right)
            q.push(parent->right);
    }
    return root;
}

void level_order(Node *root, int target)
{
    if (root == NULL)
    {
        cout << "No tree" << endl;
        return;
    }
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();

        // cout << f->value << " ";
        if (f->value == target)
        {
            cout << "true" << endl;
        }
        else
        {
            cout << "false" << endl;
            break;
        }

        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }
}

int main()
{
    Node *root = input();
    int target;
    cin >> target;
    level_order(root, target);
    return 0;
}