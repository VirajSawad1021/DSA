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

class BST
{
public:
    Node* insert(Node* root, int data)
    {
        if (root == NULL)
        {
            return new Node(data);
        }
        
        if (data < root->data)
        {
            root->left = insert(root->left, data);
        }
        else if (data > root->data)
        {
            root->right = insert(root->right, data);
        }
        
        return root;
    }
    
    Node* search(Node* root, int key)
    {
        if (root == NULL || root->data == key)
        {
            return root;
        }
        
        if (key < root->data)
        {
            return search(root->left, key);
        }
        
        return search(root->right, key);
    }
    
    Node* findMin(Node* root)
    {
        while (root->left != NULL)
        {
            root = root->left;
        }
        return root;
    }
    
    Node* deleteNode(Node* root, int key)
    {
        if (root == NULL)
        {
            return root;
        }
        
        if (key < root->data)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->data)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            if (root->left == NULL)
            {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL)
            {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
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
};

int main()
{
    BST bst;
    Node* root = NULL;
    
    // Insert nodes
    root = bst.insert(root, 50);
    root = bst.insert(root, 30);
    root = bst.insert(root, 20);
    root = bst.insert(root, 40);
    root = bst.insert(root, 70);
    root = bst.insert(root, 60);
    root = bst.insert(root, 80);
    
    cout << "BST Inorder traversal: ";
    bst.inorder(root);
    cout << endl;
    
    // Search
    Node* found = bst.search(root, 40);
    if (found != NULL)
        cout << "Found 40 in BST" << endl;
    else
        cout << "40 not found" << endl;
    
    // Delete
    root = bst.deleteNode(root, 20);
    cout << "After deleting 20: ";
    bst.inorder(root);
    cout << endl;
    
    getch();
    return 0;
}