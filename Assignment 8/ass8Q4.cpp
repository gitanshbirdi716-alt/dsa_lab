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
Node *insert(Node *root, int d)
{
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }
    if (root->data > d)
    {
        root->left = insert(root->left, d);
    }
    else if (root->data < d)
    {
        root->right = insert(root->right, d);
    }
    else
        cout << "Cannot insert duplicates"<<endl;
    return root;
}
void input(Node *&root)
{
    int d;
    cout << "Enter data: ";
    cin >> d;
    while (d != -1)
    {
        root = insert(root, d);
        cin >> d;
    }
}

Node *min(Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

Node *del(Node *&root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (key < root->data)
    {
        root->left = del(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = del(root->right, key);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        else if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            Node *successor = min(root->right);
            root->data = successor->data;
            root->right = del(root->right, successor->data);
        }
    }
    return root;
}

int maxdepth(Node *root)
{
    if (root == NULL)
        return -1;
    int leftd = maxdepth(root->left);
    int rightd = maxdepth(root->right);
    return 1 + max(leftd, rightd);
}

int minDepth(Node *root)
{
    if (root == NULL)
        return -1;

    if (root->left == NULL)
        return 1 + minDepth(root->right);

    if (root->right == NULL)
        return 1 + minDepth(root->left);

    return 1 + min(minDepth(root->left), minDepth(root->right));
}

void inorder(Node *&root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node *root = NULL;
    input(root);
    cout << "Printing Inorder Traversal "<<endl;
    inorder(root);
    cout << "Max depth of BST" << maxdepth(root)<<endl;
    cout << "Min depth of BST" << minDepth(root)<<endl;
    int node;
    cout << "Enter node to delete:"<<endl;
    cin >> node;
    root = del(root, node);
    cout << "After deletion: "<<endl;
    inorder(root);
    cout << endl;
    return 0;
}
