#include<iostream>
#include<conio.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

bool isIdentical(Node* root1, Node* root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    
    if (root1 == NULL || root2 == NULL)
        return false;
    
    return (root1->data == root2->data) &&
           isIdentical(root1->left, root2->left) &&
           isIdentical(root1->right, root2->right);
}

Node* mirror(Node* root)
{
    if (root == NULL)
        return NULL;
    
    Node* left = mirror(root->left);
    Node* right = mirror(root->right);
    
    root->left = right;
    root->right = left;
    
    return root;
}

void inorder(Node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main()
{
    // First tree
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    
    // Second tree (identical)
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);
    
    cout << "Tree 1: ";
    inorder(root1);
    cout << endl;
    
    cout << "Tree 2: ";
    inorder(root2);
    cout << endl;
    
    if (isIdentical(root1, root2))
        cout << "Trees are identical" << endl;
    else
        cout << "Trees are not identical" << endl;
    
    cout << "Mirroring Tree 1..." << endl;
    mirror(root1);
    
    cout << "Tree 1 after mirroring: ";
    inorder(root1);
    cout << endl;
    
    getch();
    return 0;
}