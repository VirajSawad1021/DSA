#include<iostream>
#include<queue>
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

void levelOrder(Node* root)
{
    if (root == NULL)
        return;
    
    queue<Node*> q;
    q.push(root);
    
    while (!q.empty())
    {
        Node* current = q.front();
        q.pop();
        
        cout << current->data << " ";
        
        if (current->left != NULL)
            q.push(current->left);
        
        if (current->right != NULL)
            q.push(current->right);
    }
}

int height(Node* root)
{
    if (root == NULL)
        return 0;
    
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    return 1 + max(leftHeight, rightHeight);
}

int countNodes(Node* root)
{
    if (root == NULL)
        return 0;
    
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    cout << "Level Order Traversal: ";
    levelOrder(root);
    cout << endl;
    
    cout << "Height of tree: " << height(root) << endl;
    cout << "Total nodes: " << countNodes(root) << endl;
    
    getch();
    return 0;
}