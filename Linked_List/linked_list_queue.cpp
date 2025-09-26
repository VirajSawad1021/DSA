#include<iostream>
#define MAX 5
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node *front, *rear;
    int count;
    
public:
    Queue() {
        front = rear = NULL;
        count = 0;
    }
    
    void enqueue(int item) {
        if (count == MAX) {
            cout << "Queue overflow";
            return;
        }
        else {
            Node *newNode = new Node;
            newNode->data = item;
            newNode->next = NULL;
            
            if (rear == NULL) {
                front = rear = newNode;
            }
            else {
                rear->next = newNode;
                rear = newNode;
            }
            count++;
        }
    }
    
    int dequeue() {
        if (front == NULL) {
            cout << "Queue underflow";
            return -1;
        }
        else {
            Node *temp = front;
            int item = temp->data;
            
            front = front->next;
            if (front == NULL) {
                rear = NULL;
            }
            
            delete temp;
            count--;
            return item;
        }
    }
    
    void display() {
        if (front == NULL) {
            cout << "Queue is empty";
            return;
        }
        Node *temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main() {
    Queue q;
    int choice, item;
    
    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Enqueue item" << endl;
        cout << "2. Dequeue item" << endl;
        cout << "3. Display queue" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter item to enqueue: ";
                cin >> item;
                q.enqueue(item);
                break;
            case 2:
                item = q.dequeue();
                if (item != -1)
                    cout << "Dequeued item: " << item << endl;
                break;
            case 3:
                q.display();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
}