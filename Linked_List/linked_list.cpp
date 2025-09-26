#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class linkedlist{
    private:
        Node *head;  
    public:  
        linkedlist(){
            head = NULL;
        }
        
        void insert(){
            int item;
            cout<<"Enter value: ";
            cin>>item;
            Node *newNode = new Node;
            
            newNode->data = item;
            newNode->next = NULL;
            
            if(head == NULL){
                head = newNode;  
            }
            else{
                newNode->next = head;  
                head = newNode;  
            }
        }
        
        void delete_node(){
            if(head == NULL){
                cout<<"List is empty";
            }
            else{
                Node *temp = head;
                head = head->next;
                delete temp;
            }
        }
        
        void display(){
            Node *temp = head;
            while(temp != NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
            }   
        }
};

int main(){
    linkedlist l;
    int choice;
    
    cout<<"1.Insert"<<endl;
    cout<<"2.Delete"<<endl;
    cout<<"3.Display"<<endl;
    cout<<"4.Exit"<<endl;
    
    cin>>choice;
    
    switch (choice)
    {
    case 1:
        l.insert();
        break;
    case 2:
        l.delete_node();
        break;
    case 3:
        l.display();
        break;
    case 4:
        cout<<"Exiting..."<<endl;
        break;
    default:
        cout<<"Invalid choice"<<endl;
        break;
    }

    return 0;
}