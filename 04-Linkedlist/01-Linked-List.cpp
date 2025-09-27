

// Linked List Implemetation

#include <bits/stdc++.h>
using namespace std;

// Definition of a Node
struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

// Insert at Head
void insertAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

// Insert at Tail
void insertAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Delete a node (by value)
void deleteNode(Node *&head, int val)
{
    if (head == nullptr)
        return; // empty list

    // Case 1: Node to delete is the head
    if (head->data == val)
    {
        Node *temp = head;
        head = head->next; // move head
        delete temp;       // free memory
        return;
    }

    // Case 2: Search for the node to delete
    Node *temp = head;
    while (temp->next != nullptr && temp->next->data != val)
    {
        temp = temp->next;
    }

    // If node not found
    if (temp->next == nullptr)
        return;

    // Node found → delete it
    Node *toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

// Print Linked List
void printList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Driver Code
int main()
{
    Node *head = nullptr;

    insertAtHead(head, 10); // List: 10
    insertAtHead(head, 20); // List: 20 -> 10
    insertAtTail(head, 30); // List: 20 -> 10 -> 30
    insertAtTail(head, 40); // List: 20 -> 10 -> 30 -> 40

    cout << "Original List: ";
    printList(head);

    // Delete operations
    deleteNode(head, 20); // delete head
    cout << "After deleting 20: ";
    printList(head);

    deleteNode(head, 30); // delete middle node
    cout << "After deleting 30: ";
    printList(head);

    deleteNode(head, 40); // delete tail
    cout << "After deleting 40: ";
    printList(head);

    return 0;
}
