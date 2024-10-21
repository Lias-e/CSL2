#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() : head(nullptr) {}

    void addFront(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        newNode->prev = nullptr;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void backchain() {
        Node* temp = nullptr;
        Node* current = head;

        // Swap next and prev for all nodes
        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        // Before changing head, check for the cases like empty list and list with only one node
        if (temp != nullptr) {
            head = temp->prev;
        }
    }
};

int main() {
    DoublyLinkedList dll;
    dll.addFront(10);
    dll.addFront(20);
    dll.addFront(30);
    dll.addFront(40);

    cout << "Original list: ";
    dll.display();

    dll.backchain();

    cout << "Reversed list: ";
    dll.display();

    return 0;
}
