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
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insertFront(int data) {
        Node* newNode = new Node{data, head, nullptr};
        if (head != nullptr) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }
        head = newNode;
    }

    void insertEnd(int data) {
        Node* newNode = new Node{data, nullptr, tail};
        if (tail != nullptr) {
            tail->next = newNode;
        } else {
            head = newNode;
        }
        tail = newNode;
    }

    void deleteFront() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }

    void deleteEnd() {
        if (tail == nullptr) return;
        Node* temp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insertFront(10);
    dll.insertFront(20);
    dll.insertEnd(30);
    dll.insertEnd(40);

    cout << "List: ";
    dll.display();

    dll.deleteFront();
    cout << "After deleting front: ";
    dll.display();

    dll.deleteEnd();
    cout << "After deleting end: ";
    dll.display();

    return 0;
}
