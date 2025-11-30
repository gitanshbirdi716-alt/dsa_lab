#include <iostream>
using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
    int data;

    Node(int d)
    {
        left = NULL;
        right = NULL;
        data = d;
    }
};

Node *build(Node *root)
{
    int d;
    cout << "Enter data: ";
    cin >> d;

    if (d == -1)
        return NULL;

    root = new Node(d);

    cout << "Enter LEFT child of " << d << endl;
    root->left = build(root->left);

    cout << "Enter RIGHT child of " << d << endl;
    root->right = build(root->right);

    return root;
}

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void search(Node *root, int val)
{

    if (root == NULL)
    {
        cout << "NOT FOUND" << endl;
        return;
    }
    if (root->data == val)
    {
        cout << "ELEMENT SEARCHED FOUND" << endl;
        return;
    }
    else if (root->data > val)
        search(root->left, val);
    else
        search(root->right, val);
}

Node *max(Node *root)
{
    while (root->right != NULL)
    {

        root = root->right;
    }
    return root;
}

Node *min(Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

Node *inorderSuccessor(Node *root, int key)
{
    Node *successor = NULL;

    while (root != NULL)
    {
        if (key < root->data)
        {
            successor = root;
            root = root->left;
        }
        else if (key > root->data)
        {
            root = root->right;
        }
        else
        {
            if (root->right != NULL)
                return min(root->right);

            return successor;
        }
    }
}
Node *inorderpredecessor(Node *root, int key)
{
    Node *predecessor = NULL;
    while (root != NULL)
    {
        if (key > root->data)
        {
            predecessor = root;
            root = root->right;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            if (root->left != NULL)
            {
                return max(root->left);
            }
        }
    }
}
int main()
{
    int key1, key2;
    Node *root = build(root);
    search(root, 10);
    cout << "printing inorder:";
    inorder(root);
    cout << "MAX ELEMENT OF BST IS:"<<endl;
    Node *temp1 = max(root);
    cout << temp1->data;
    cout << "MIN ELEMENT OF BST IS:"<<endl;
    Node *temp2 = min(root);
    cout << temp2->data << endl;
    cout << "enter key for successor:";
    cin >> key1;
    Node *inordersuc = inorderSuccessor(root, key1);
    cout << "enter key for predecessor:";
    cin >> key2;
    Node *inorderpre = inorderpredecessor(root, key2);
    cout << "inorder successor of" << key1 << "is:" << inordersuc->data << endl;
    cout << "inorder predecessor of" << key2 << "is:" << inorderpre->data;
}
