
// 🔹 Doubly Linked List (DLL)

// ✅ Definition
// A linear data structure where each node contains:

// Data
// A pointer to the previous node (prev)
// A pointer to the next node (next)

// ✅ Features
// Can be traversed both forward and backward.
// More flexible than a singly linked list.
// Extra space needed for prev pointer.

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    // Insert at head
    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    // Insert at tail
    void insertAtTail(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    // Insert at specific position (1-indexed)
    void insertAtPos(int pos, int val) {
        if (pos <= 1) {
            insertAtHead(val);
            return;
        }

        Node* temp = head;
        int count = 1;
        while (temp && count < pos - 1) {
            temp = temp->next;
            count++;
        }

        if (!temp || !temp->next) {
            insertAtTail(val);
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }

    // Delete from head
    void deleteHead() {
        if (!head) return;

        Node* temp = head;
        if (head == tail) { // single element
            head = tail = NULL;
        } else {
            head = head->next;
            head->prev = NULL;
        }
        delete temp;
    }

    // Delete from tail
    void deleteTail() {
        if (!tail) return;

        Node* temp = tail;
        if (head == tail) {
            head = tail = NULL;
        } else {
            tail = tail->prev;
            tail->next = NULL;
        }
        delete temp;
    }

    // Delete at specific position (1-indexed)
    void deleteAtPos(int pos) {
        if (!head) return;

        if (pos <= 1) {
            deleteHead();
            return;
        }

        Node* temp = head;
        int count = 1;
        while (temp && count < pos) {
            temp = temp->next;
            count++;
        }

        if (!temp) return;

        if (temp == tail) {
            deleteTail();
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }

    // Print forward
    void printForward() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Print backward
    void printBackward() {
        Node* temp = tail;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;

    dll.insertAtHead(10);
    dll.insertAtHead(5);
    dll.insertAtTail(20);
    dll.insertAtTail(25);
    dll.insertAtPos(3, 15);

    cout << "Forward: ";
    dll.printForward();

    cout << "Backward: ";
    dll.printBackward();

    dll.deleteHead();
    dll.deleteTail();
    dll.deleteAtPos(2);

    cout << "After deletions, Forward: ";
    dll.printForward();

    return 0;
}
