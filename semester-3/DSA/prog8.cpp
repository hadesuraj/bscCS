#include <iostream>
using namespace std;
struct Node {
    float coeff;
    int expo;
    Node* link;
};
Node* insert(Node* head, float co, int ex) {
    Node* temp;
    Node* newP = new Node;
    newP->coeff = co;
    newP->expo = ex;
    newP->link = nullptr;
    if (head == nullptr || ex > head->expo) {
        newP->link = head;
        head = newP;
    } else {
        temp = head;
        while (temp->link != nullptr && temp->link->expo >= ex)
            temp = temp->link;
        newP->link = temp->link;
        temp->link = newP;
    }
    return head;
}
Node* create(Node* head) {
    int n, i;
    float coeff;
    int expo;
    cout << "Enter the number of terms: ";
    cin >> n;
    for (i = 0; i < n; i++) {
        cout << "Enter the coefficient for term " << i + 1 << ": ";
        cin >> coeff;
        cout << "Enter the exponent for term " << i + 1 << ": ";
        cin >> expo;
        head = insert(head, coeff, expo);
    }
    return head;
}
void print(Node* head) {
    if (head == nullptr)
        cout << "No Polynomial." << endl;
    else {
        Node* temp = head;
        while (temp != nullptr) {
            cout << "(" << temp->coeff << "x^" << temp->expo << ")";
            temp = temp->link;
            if (temp != nullptr)
                cout << " + ";
            else
                cout << endl;
        }
    }
}
void polyAdd(Node* head1, Node* head2) {
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    Node* head3 = nullptr;
    while (ptr1 != nullptr && ptr2 != nullptr) {
        if (ptr1->expo == ptr2->expo) {
            head3 = insert(head3, ptr1->coeff + ptr2->coeff, ptr1->expo);
            ptr1 = ptr1->link;
            ptr2 = ptr2->link;
        } else if (ptr1->expo > ptr2->expo) {
            head3 = insert(head3, ptr1->coeff, ptr1->expo);
            ptr1 = ptr1->link;
        } else if (ptr1->expo < ptr2->expo) {
            head3 = insert(head3, ptr2->coeff, ptr2->expo);
            ptr2 = ptr2->link;
        }
    }
    while (ptr1 != nullptr) {
        head3 = insert(head3, ptr1->coeff, ptr1->expo);
        ptr1 = ptr1->link;
    }
    while (ptr2 != nullptr) {
        head3 = insert(head3, ptr2->coeff, ptr2->expo);
        ptr2 = ptr2->link;
    }
    cout << "Added polynomial is: ";
    print(head3);
}
int main() {
    Node* head1 = nullptr;
    Node* head2 = nullptr;
    cout << "Enter the First polynomial" << endl;
    head1 = create(head1);
    cout << "Enter the second polynomial" << endl;
    head2 = create(head2);
    polyAdd(head1, head2);
    return 0;
}

