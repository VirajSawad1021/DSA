#include<iostream>
#define MAX 5
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;
    int count;
    
public:
    Stack() {
        top = NULL;
        count = 0;
    }
    
    void push(int item) {
        if (count == MAX) {
            cout << "Stack overflow";
            return;
        }
        else {
            Node* newNode = new Node;
            newNode->data = item;
            newNode->next = top;
            top = newNode;
            count++;
        }
    }
    
    int pop() {
        if (top == NULL) {
            cout << "Stack underflow";
            return -1;
        }
        else {
            Node* temp = top;
            int item = temp->data;
            top = top->next;
            delete temp;
            count--;
            return item;
        }
    }
    
    void display() {
        if (top == NULL) {
            cout << "Stack is empty";
            return;
        }
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main() {
    Stack s;
    int choice, item;
    
    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Push item" << endl;
        cout << "2. Pop item" << endl;
        cout << "3. Display stack" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter item to push: ";
                cin >> item;
                s.push(item);
                break;
            case 2:
                item = s.pop();
                if (item != -1)
                    cout << "Popped item: " << item << endl;
                break;
            case 3:
                s.display();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
}