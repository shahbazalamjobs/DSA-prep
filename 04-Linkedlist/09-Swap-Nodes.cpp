
// Swap Nodes in pairs Cpp

// Original list: 1 2 3 4 5 
// After swapping pairs: 2 1 4 3 5


// 1. Iterative 
// TC: O(n)
// SC: O(1)

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

// Function to print linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to swap nodes in pairs
Node* swapPairs(Node* head) {
    if (!head || !head->next) return head;

    Node* dummy = new Node(0);
    dummy->next = head;
    Node* prev = dummy;

    while (head && head->next) {
        Node* first = head;
        Node* second = head->next;

        // Swapping
        prev->next = second;
        first->next = second->next;
        second->next = first;

        // Move pointers
        prev = first;
        head = first->next;
    }
    return dummy->next;
}

int main() {
    // Hardcoded linked list: 1->2->3->4->5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original list: ";
    printList(head);

    head = swapPairs(head);

    cout << "After swapping pairs: ";
    printList(head);

    return 0;
}

// 2. Recursive
// TC: O(n)
// SC: O(n)

// C++ program to pairwise swap elements
// in a given linked list

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Recursive function to swap data of nodes in pairs
void pairwiseSwap(Node* head) {
    
    // Base case: if the list is empty or has only
  	// one node, no swap
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    // Swap the data of the current node with the next node
    swap(head->data, head->next->data);

    // Recursion for the next pair
    pairwiseSwap(head->next->next);
}

void printList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    
    // Creating the linked list:
  	// 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    pairwiseSwap(head);
    
    printList(head);

    return 0;
}



// 3. Changing links
// TC: O(n)
// SC: O(1)

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

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* swapPairs(Node* head) {
    if (!head || !head->next) return head;

    Node* dummy = new Node(0);
    dummy->next = head;
    Node* prev = dummy;

    while (head && head->next) {
        Node* first = head;
        Node* second = head->next;

        // 🔗 Change links
        prev->next = second;
        first->next = second->next;
        second->next = first;

        // Move forward
        prev = first;
        head = first->next;
    }
    return dummy->next;
}

int main() {
    // Hardcoded: 1->2->3->4->5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original: ";
    printList(head);

    head = swapPairs(head);

    cout << "Swapped pairs: ";
    printList(head);
}
