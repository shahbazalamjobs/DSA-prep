

// Circular Singly Linked List in C++

// ✅ Definition
// A linked list where the last node points back to the head, forming a circle.

// It can be:
// Singly Circular Linked List → Only next pointer, last node points to head.
// Doubly Circular Linked List → Both next and prev, last node connects back to head, head connects back to tail.

// ✅ Features
// Can be traversed infinitely unless stopped manually.
// Useful in scenarios where the list is continuously rotated or cycled.

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = NULL;
    }

    // Insert at head
    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            head->next = head; // points to itself
            return;
        }

        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }

    // Insert at tail
    void insertAtTail(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            head->next = head;
            return;
        }

        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }

    // Delete from head
    void deleteHead() {
        if (!head) return;

        if (head->next == head) { // only one node
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        Node* delNode = head;
        temp->next = head->next;
        head = head->next;
        delete delNode;
    }

    // Delete from tail
    void deleteTail() {
        if (!head) return;

        if (head->next == head) { // only one node
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;
        while (temp->next->next != head) {
            temp = temp->next;
        }
        Node* delNode = temp->next;
        temp->next = head;
        delete delNode;
    }

    // Delete by position (1-indexed)
    void deleteAtPos(int pos) {
        if (!head) return;

        if (pos == 1) {
            deleteHead();
            return;
        }

        Node* temp = head;
        int count = 1;
        while (count < pos - 1 && temp->next != head) {
            temp = temp->next;
            count++;
        }

        if (temp->next == head) return; // invalid pos

        Node* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;
    }

    // Display circular list
    void display() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    CircularLinkedList cll;

    cll.insertAtHead(10);
    cll.insertAtHead(5);
    cll.insertAtTail(20);
    cll.insertAtTail(25);

    cout << "Circular List: ";
    cll.display();

    cll.deleteHead();
    cll.deleteTail();
    cll.deleteAtPos(2);

    cout << "After deletions: ";
    cll.display();

    return 0;
}
