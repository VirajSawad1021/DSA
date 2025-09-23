#include <iostream>
using namespace std;

#define MAXSIZE 10

class Stack {
private:
    int array[MAXSIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int num) {
        if (top >= MAXSIZE - 1) {
            cout << "The Stack is full" << endl;
        }
        else {
            array[++top] = num;
            cout << "Pushed " << num << endl;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
        }
        else {
            cout << "Popped " << array[top] << endl;
            top--;
        }
    }

    int peek() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        else {
            return array[top];
        }
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top >= MAXSIZE - 1;
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
        }
        else {
            cout << "Stack elements: ";
            for (int i = 0; i <= top; i++) {
                cout << array[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack s;
    
    // Push some elements
    s.push(5);
    s.push(4);
    s.push(5);
    s.push(8);
    s.push(9);
    
    // Display stack
    s.display();
    
    // Peek top element
    cout << "Top element: " << s.peek() << endl;
    
    // Pop some elements
    s.pop();
    s.pop();
    
    s.display();
    

    return 0;
}
