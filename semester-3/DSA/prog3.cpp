#include <iostream>
#include <string>
using namespace std;
template <typename T>
class Node {
public:
    T data;
    Node* prev;
    Node* next;
    Node(T data) : data(data), next(nullptr), prev(nullptr) {}
    ~Node() {
        if (next != nullptr) {
            delete next;
            next = nullptr;
        }
        cout << "Memory freed with data " << data << endl;
    }
};
template <typename T>
void display(Node<T>*& head) {
    Node<T>* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
template <typename T>
int getLength(Node<T>* head) {
    int len = 0;
    Node<T>* temp = head;
    while (temp != nullptr) {
        len++;
        temp = temp->next;
    }
    return len;
}
template <typename T>
void insertAtHead(Node<T>*& head, Node<T>*& tail, T data) {
    if (head == nullptr) {
        Node<T>* temp = new Node<T>(data);
        head = temp;
        tail = temp;
    } else {
        Node<T>* temp = new Node<T>(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
template <typename T>
void insertAtTail(Node<T>*& tail, Node<T>*& head, T data) {
    if (tail == nullptr) {
        Node<T>* temp = new Node<T>(data);
        tail = temp;
        head = temp;
    } else {
        Node<T>* temp = new Node<T>(data);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}
template <typename T>
void insertAtPosition(Node<T>*& head, Node<T>*& tail, int pos, T data) {
    if (pos < 1 || pos > getLength(head) + 1) {
        cout << "Invalid position. Insertion failed." << endl;
        return;
    }

    if (pos == 1) {
        insertAtHead(head, tail, data);
    } else if (pos == getLength(head) + 1) {
        insertAtTail(tail, head, data);
    } else {
        Node<T>* temp = head;
        for (int i = 1; i < pos - 1; ++i) {
            temp = temp->next;
        }

        Node<T>* nodeToInsert = new Node<T>(data);
        nodeToInsert->next = temp->next;
        temp->next->prev = nodeToInsert;
        temp->next = nodeToInsert;
        nodeToInsert->prev = temp;
    }
}
template <typename T>
void deleteNode(Node<T>*& head, int pos) {
    if (pos < 1 || pos > getLength(head)) {
        cout << "Invalid position. Deletion failed." << endl;
        return;
    }
    if (pos == 1) {
        Node<T>* temp = head;
        temp->next->prev = nullptr;
        head = temp->next;
        temp->next = nullptr;
        delete temp;
    } else {
        Node<T>* cur = head;
        for (int i = 1; i < pos; ++i) {
            cur = cur->next;
        }

        cur->prev->next = cur->next;
        if (cur->next != nullptr) {
            cur->next->prev = cur->prev;
        }
        cur->next = nullptr;
        delete cur;
    }
}
template <typename T>
int searchNode(Node<T>* head, T target) {
    Node<T>* temp = head;
    int pos = 1;
    while (temp != nullptr) {
        if (temp->data == target) {
            return pos; 
        }
        temp = temp->next;
        pos++;
    }
    return -1;  
}
template <typename T>
void reverseList(Node<T>*& head, Node<T>*& tail) {
    Node<T>* current = head;
    Node<T>* prevNode = nullptr;
    Node<T>* nextNode = nullptr;
    while (current != nullptr) {
        nextNode = current->next;
        current->next = prevNode;
        current->prev = nextNode;
        prevNode = current;
        current = nextNode;
    }
    tail = head;
    head = prevNode;
}
int main() {
    Node<int>* headInt = nullptr;
    Node<int>* tailInt = nullptr;
    Node<string>* headString = nullptr;
    Node<string>* tailString = nullptr;
    int choice;
    do {
        cout << "\nSelect an option:\n"
             << "1. Insert at Head\n"
             << "2. Insert at Tail\n"
             << "3. Insert at Position\n"
             << "4. Delete a Node\n"
             << "5. Search for a Node\n"
             << "6. Reverse List\n"
             << "7. Display\n"
             << "0. Exit\n"
             << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int value;
                cout << "Enter the value to insert at the head: ";
                cin >> value;
                insertAtHead(headInt, tailInt, value);
                cout << "Inserted successfully." << endl;
                break;
            }
            case 2: {
                int value;
                cout << "Enter the value to insert at the tail: ";
                cin >> value;
                insertAtTail(tailInt, headInt, value);
                cout << "Inserted successfully." << endl;
                break;
            }
            case 3: {
                int pos;
                int value;
                cout << "Enter the position to insert at: ";
                cin >> pos;
                cout << "Enter the value to insert: ";
                cin >> value;
                insertAtPosition(headInt, tailInt, pos, value);
                cout << "Inserted successfully." << endl;
                break;
            }
            case 4: {
                int pos;
                cout << "Enter the position to delete from: ";
                cin >> pos;
                deleteNode(headInt, pos);
                cout << "Deleted successfully." << endl;
                break;
            }
            case 5: {
                int value;
                cout << "Enter the value to search for: ";
                cin >> value;
                int position = searchNode(headInt, value);
                if (position != -1) {
                    cout << "Value " << value << " found at position " << position << endl;
                } else {
                    cout << "Value " << value << " not found in the list." << endl;
                }
                break;
            }
            case 6: {
                cout << "Reversing the list." << endl;
                reverseList(headInt, tailInt);
                break;
            }
            case 7:
                cout << "Linked List Contents: ";
                display(headInt);
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

