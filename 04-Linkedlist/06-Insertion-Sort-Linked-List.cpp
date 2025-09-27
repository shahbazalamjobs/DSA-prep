
// Given a singly linked list, the task is to sort the list
// (in ascending order) using the insertion sort algorithm.

// Input: 5->4->1->3->2
// Output: 1->2->3->4->5

// Input: 4->3->2->1
// Output: 1->2->3->4

// 1.
// TC:
// Worst Case = O(n²)
// Best Case = O(n)
// Average Case = O(n²)

// SC: O(1)

#include <iostream>
using namespace std;

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

// Function to insert at head
void insertAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

// Print linked list
void printList(Node *head)
{
    while (head)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Insertion sort function
Node *insertionSort(Node *head)
{
    if (!head || !head->next)
        return head; // empty or single node

    Node *dummy = new Node(0); // dummy head for sorted list
    Node *curr = head;

    while (curr)
    {
        Node *prev = dummy;
        Node *nextNode = curr->next; // store next before we change links

        // find the correct place to insert curr in sorted list
        while (prev->next && prev->next->data < curr->data)
        {
            prev = prev->next;
        }

        // Insert curr between prev and prev->next
        curr->next = prev->next;
        prev->next = curr;

        curr = nextNode; // move to next node in original list
    }

    return dummy->next; // skip dummy
}

int main()
{
    Node *head = nullptr;

    // Insert values (unsorted)
    insertAtHead(head, 5);
    insertAtHead(head, 3);
    insertAtHead(head, 4);
    insertAtHead(head, 1);
    insertAtHead(head, 2);

    cout << "Original List:\n";
    printList(head);

    head = insertionSort(head);

    cout << "Sorted List:\n";
    printList(head);

    return 0;
}
