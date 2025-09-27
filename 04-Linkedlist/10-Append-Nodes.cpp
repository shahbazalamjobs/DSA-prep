
// Append Nodes at tail
// TC: O(n)
// SC: O(1) // (only one new node created)



#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to append a node at the end
void append(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) { // if list is empty
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Print linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = nullptr;

    // Append nodes
    append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 4);

    // Print
    printList(head);

    return 0;
}
