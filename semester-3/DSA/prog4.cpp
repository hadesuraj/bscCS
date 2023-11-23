#include <iostream>
using namespace std;
template <typename T, size_t SIZE>
class Stack {
private:
    int top;
    T arr[SIZE];
public:
    Stack() : top(-1) {
        for (size_t i = 0; i < SIZE; i++) {
            arr[i] = T();
        }
    }
    void push(const T& val) {
        if (top == static_cast<int>(SIZE - 1)) {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        arr[top] = val;
    }
    T pop() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return T();
        }
        T popValue = arr[top];
        arr[top] = T();
        top--;
        return popValue;
    }
    void display() const {
        cout << "All values in the Stack are: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    size_t size;
    cout << "Enter the size of the stack: ";
    cin >> size;
    if (size == 0) {
        cout << "Stack size must be greater than zero. Exiting program." << endl;
        return 1;
    }
    Stack<int, 5> s1;
    int opt, value;
    do {
        cout << "What operation do you want to perform? Select Option Number, Enter 0 to Exit." << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display" << endl;
        cin >> opt;
        switch (opt) {
            case 0:
                break;
            case 1:
                cout << "Enter an item to push in the stack: ";
                cin >> value;
                s1.push(value);
                break;
            case 2:
                cout << "Pop Function called - Popped Value: " << s1.pop() << endl;
                break;
            case 3:
                s1.display();
                break;
            default:
                cout << "Enter a proper option number" << endl;
        }
    } while (opt != 0);
    return 0;
}

