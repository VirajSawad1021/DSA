#include<iostream>
#include<conio.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    
    Node (int d)
    {
        data=d;
        left=NULL;
        right=NULL;	
    }	
};

void preorder(Node *root)
{
    if(root!=NULL)
    {
        cout<< root->data << " ";
        preorder(root->left);
        preorder(root->right);	
    }
}

void inorder(Node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<< root->data << " ";
        inorder(root->right);	
    }
}

void postorder(Node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<< root->data << " ";	
    }
}

int main()
{
    Node *root=new Node(7);
    root->left=new Node(4);
    root->left->left=new Node(3);
    root->left->right=new Node(6);
    root->right=new Node(12);
    root->right->left=new Node(9);
    root->right->left->left=new Node(8);
    root->right->left->right=new Node(11);
    root->right->right=new Node(18);
    
    cout << "Preorder: ";
    preorder(root);
    cout << endl;
    
    cout << "Inorder: ";
    inorder(root);
    cout << endl;
    
    cout << "Postorder: ";
    postorder(root);
    cout << endl;
    
    getch();	
    return 0;
}