#include<iostream>
using namespace std;
template<typename T>
class Node {
public:
    T data;
    Node* next;
    Node(T data) : data(data), next(nullptr) {}
};
template<typename T>
class Stack {
private:
    Node<T>* top;
public:
    Stack() : top(nullptr) {}
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
    bool isEmpty() {
        return top == nullptr;
    }
    void push(T data) {
        Node<T>* newNode = new Node<T>(data);
        newNode->next = top;
        top = newNode;
        cout << "Pushed: " << data << endl;
    }
    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow (empty)." << endl;
            return;
        }
        Node<T>* temp = top;
        top = top->next;
        cout << "Popped: " << temp->data << endl;
        delete temp;
    }
    T peek() {
        if (isEmpty()) {
            cerr << "Stack is empty." << endl;
            exit(EXIT_FAILURE);
        }
        return top->data;
    }

    void print() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        Node<T>* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main() {
    Stack<int> stack;

    int choice;
    do {
       cout << "\nSelect an option:\n"
                  << "1. Push\n"
                  << "2. Pop\n"
                  << "3. Peek\n"
                  << "4. Print Stack\n"
                  << "0. Exit\n"
                  << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int data;
                cout << "Enter the element to push: ";
                cin >> data;
                stack.push(data);
                break;
            }
            case 2:
                stack.pop();
                break;
            case 3:
                if (!stack.isEmpty()) {
                	cout << "Top element: " << stack.peek() << endl;
                }
                break;
            case 4:
                cout << "Stack elements: ";
                stack.print();
                break;
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}

