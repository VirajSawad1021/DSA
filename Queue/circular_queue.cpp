#include<iostream>
using namespace std;
#define MAX 5

class CircularQueue{
    int front, rear;
    int arr[MAX];
    public:
        CircularQueue(){
            front = -1;
            rear = -1;
        }
        
        void enqueue(){
            if((rear + 1) % MAX == front){
                cout<<"Queue is full"<<endl;
                return;
            }
            int x;
            cout<<"Enter the value to be inserted: ";
            cin>>x;
            if(front == -1){
                front = 0;
                rear = 0;
            }
            else{
                rear = (rear + 1) % MAX;
            }
            arr[rear] = x;
            cout<<"Inserted "<<x<<endl;
        }
        
        void dequeue(){
            if(front == -1){
                cout<<"Queue is empty"<<endl;
                return;
            }
            cout<<"Deleted "<<arr[front]<<endl;
            if(front == rear){
                front = -1;
                rear = -1;
            }
            else{
                front = (front + 1) % MAX;
            }
        }
        
        void display(){
            if(front == -1){
                cout<<"Queue is empty"<<endl;
                return;
            }
            cout<<"Queue elements are: ";
            int i = front;
            while(true){
                cout<<arr[i]<<" ";
                if(i == rear) break;
                i = (i + 1) % MAX;
            }
            cout<<endl;
        }
};

int main(){
    CircularQueue q;
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