#include<iostream>
using namespace std;
#define MAX 5

class queue{
    int front,rear;
    int arr[MAX];
    public:
        queue(){
            front=-1;
            rear=-1;
        }
        
        void enqueue(){
            if(rear==MAX-1){
                cout<<"Queue is full"<<endl;
                return;
            }
            int x;
            cout<<"Enter the value to be inserted: ";
            cin>>x;
            if(front==-1){
                front=0;
            }
            rear++;
            arr[rear]=x;
            cout<<"Inserted "<<x<<endl;
        }
        
        void dequeue(){
            if(front==-1 || front>rear){
                cout<<"Queue is empty"<<endl;
                return;
            }
            cout<<"Deleted "<<arr[front]<<endl;
            for(int i=front; i<rear; i++){
                arr[i]=arr[i+1];
            }
            rear--;
            if(rear<front){
                front=-1;
                rear=-1;
            }
        }
        
        void display(){
            if(front==-1 || front>rear){
                cout<<"Queue is empty"<<endl;
                return;
            }
            cout<<"Queue elements are: ";
            for(int i=front; i<=rear; i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};

int main(){
    queue q;
    int choice;
    do {
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                q.enqueue();
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 4);
    
    return 0;
}