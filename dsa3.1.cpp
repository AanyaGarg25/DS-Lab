#include<iostream>
using namespace std;

#define SIZE 10

int stack[SIZE];
int top = -1;

int isempty() {
    return top == -1;
}

int isfull() {
    return top == SIZE - 1;
}

void push(int num) {
    if (isfull()) {
        cout << "Stack overflow" << endl;
    } else {
        stack[++top] = num;
        cout << "Data pushed: " << num << endl;
    }
}

void pop() {
    if (isempty()) {
        cout << "Stack is empty, can't pop." << endl;
    } else {
        cout << stack[top] << " is popped" << endl;
        top--;
    }
}

void peek() {
    if (isempty()) {
        cout << "Stack is empty, no top value." << endl;
    } else {
        cout << stack[top] << " is the top value" << endl;
    }
}

void display() {
    if (isempty()) {
        cout << "The stack is empty" << endl;
    } else {
        cout << "Values in stack are: ";
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice, num;
    while (true) {
        cout << "\nStack operations are:" << endl;
        cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n5. End" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value to be pushed: ";
            cin >> num;
            push(num);
        } else if (choice == 2) {
            pop();
        } else if (choice == 3) {
            peek();
        } else if (choice == 4) {
            display();
        } else if (choice == 5) {
            cout << "Program ends" << endl;
            break;
        } else {
            cout << "Please choose a correct option." << endl;
        }
    }
    return 0;
}