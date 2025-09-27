#include<iostream>
#include<conio.h>
using namespace std;

struct Node
{
    char data;
    Node *left;
    Node *right;
    
    Node(char d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

int evaluate(Node* root)
{
    if (root == NULL)
        return 0;
    
    if (root->left == NULL && root->right == NULL)
        return root->data - '0';
    
    int leftVal = evaluate(root->left);
    int rightVal = evaluate(root->right);
    
    switch (root->data)
    {
        case '+': return leftVal + rightVal;
        case '-': return leftVal - rightVal;
        case '*': return leftVal * rightVal;
        case '/': return leftVal / rightVal;
    }
    
    return 0;
}

void inorder(Node* root)
{
    if (root != NULL)
    {
        if (root->left != NULL)
            cout << "(";
        
        inorder(root->left);
        cout << root->data;
        inorder(root->right);
        
        if (root->right != NULL)
            cout << ")";
    }
}

int main()
{
    // Expression tree for: (3 + 2) * (5 - 1)
    Node* root = new Node('*');
    root->left = new Node('+');
    root->right = new Node('-');
    
    root->left->left = new Node('3');
    root->left->right = new Node('2');
    
    root->right->left = new Node('5');
    root->right->right = new Node('1');
    
    cout << "Expression: ";
    inorder(root);
    cout << endl;
    
    cout << "Result: " << evaluate(root) << endl;
    
    getch();
    return 0;
}