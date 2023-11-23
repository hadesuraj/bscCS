#include<iostream>
#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Node {
public:
    T data;
    Node *next;
    Node(T data) : data(data), next(NULL) {}
    ~Node() {
        T value = this->data;
        if (this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << "MEMORY FREE FOR NODE WITH DATA " << value << endl;
    }
};
template<typename T>
void insertNode(Node<T> *&tail, T element, T data) {
    if (tail == NULL) {
        Node<T> *newNode = new Node<T>(data);
        tail = newNode;
        newNode->next = newNode;
    } else {
        Node<T> *cur = tail;
        while (cur->next != tail) {
            cur = cur->next;
        }
        Node<T> *temp = new Node<T>(data);
        temp->next = tail;
        cur->next = temp;
    }
}
template<typename T>
void deleteNode(Node<T> *&tail, T value) {
    if (tail == NULL) {
        cout << "Empty List" << endl;
        return;
    } else {
        Node<T> *prev = tail;
        Node<T> *cur = tail->next;
        while (cur->data != value && cur != tail) {
            prev = cur;
            cur = cur->next;
        }
        if (cur->data == value) {
            prev->next = cur->next;
            if (cur == tail) {
                tail = (tail == tail->next) ? NULL : prev;
            }
            cur->next = NULL;
            delete cur;
        } else {
            cout << "Value " << value << " not found in the list." << endl;
        }
    }
}
template<typename T>
void reverseList(Node<T>*& tail) {
    if (tail == NULL || tail->next == tail) {
        return;
    }
    Node<T>* prev = NULL;
    Node<T>* cur = tail;
    Node<T>* nextNode;
    while (cur != NULL) {
        nextNode = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nextNode;
        if (cur == tail) {
            break; 
        }
    }
    tail = prev;
}
template<typename T>
int searchNode(Node<T> *tail, T target) {
    Node<T> *temp = tail;
    int pos = 1;
    do {
        if (temp->data == target) {
            return pos;
        }
        temp = temp->next;
        pos++;
    } while (temp != tail);

    return -1;
}
template<typename T>
void print(Node<T> *tail) {
    Node<T> *temp = tail;
    if (tail == NULL) {
        cout << "EMPTY LIST" << endl;
        return;
    }
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail);
    cout << endl;
}
int main() {
    Node<int> *tailInt = NULL;
    Node<string> *tailString = NULL;
    int choice;
    do {
        cout << "\nSelect an option:\n"
             << "1. Insert Node\n"
             << "2. Delete Node\n"
             << "3. Reverse List\n"
             << "4. Search Node\n"
             << "5. Print List\n"
             << "0. Exit\n"
             << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
            	int element, data;
                cout << "Enter the element after which to insert: ";
                cin >> element;
                cout << "Enter the data to insert: ";
                cin >> data;
                insertNode(tailInt, element, data);
                break;
            }
            case 2: {
                int value;
                cout << "Enter the value to delete: ";
                cin >> value;
                deleteNode(tailInt, value);
                break;
            }
            case 3:
                reverseList(tailInt);
                cout << "List reversed." << endl;
                break;
            case 4: {
                int target;
                cout << "Enter the value to search for: ";
                cin >> target;
                int position = searchNode(tailInt, target);
                if (position != -1) {
                    cout << "Value " << target << " found at position " << position << endl;
                } else {
                    cout << "Value " << target << " not found in the list." << endl;
                }
                break;
            }
            case 5:
                cout << "Current List (int): ";
                print(tailInt);
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

