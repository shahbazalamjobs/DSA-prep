
// 1. Merge sort using linked list
// TC: O(n log n)
// SC: O(log n)

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

// Insert at head
void insertAtHead(Node*& head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

// Print list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Find middle of linked list (for splitting)
Node* getMiddle(Node* head) {
    if (head == nullptr) return head;
    Node* slow = head;
    Node* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow; // middle node
}

// Merge two sorted linked lists
Node* mergeLists(Node* left, Node* right) {
    if (!left) return right;
    if (!right) return left;

    Node* result = nullptr;
    if (left->data <= right->data) {
        result = left;
        result->next = mergeLists(left->next, right);
    } else {
        result = right;
        result->next = mergeLists(left, right->next);
    }
    return result;
}

// Merge Sort function
Node* mergeSort(Node* head) {
    if (!head || !head->next) {
        return head; // base case
    }

    Node* middle = getMiddle(head);
    Node* nextToMiddle = middle->next;

    middle->next = nullptr; // split list into two halves

    Node* left = mergeSort(head);
    Node* right = mergeSort(nextToMiddle);

    return mergeLists(left, right);
}

// Driver Code
int main() {
    Node* head = nullptr;

    // Example list: 7 -> 3 -> 5 -> 2 -> 8 -> 1
    insertAtHead(head, 1);
    insertAtHead(head, 8);
    insertAtHead(head, 2);
    insertAtHead(head, 5);
    insertAtHead(head, 3);
    insertAtHead(head, 7);

    cout << "Original List: ";
    printList(head);

    head = mergeSort(head);

    cout << "Sorted List:   ";
    printList(head);

    return 0;
}
