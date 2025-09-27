
// Delete the k-th node (1-based index) from a singly linked list.

// 1.

// Time: O(n)
// Space: O(1)

// Logic:

// ✅ Approach / Logic
// If list is empty or k <= 0, return.
// If k == 1, move head to head->next and delete old head.
// Otherwise, traverse to the (k-1)-th node.
// If (k-1)-th node or its next is NULL, return (invalid k).
// Adjust links and delete the k-th node.

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

// Delete k-th node (1-based index)
void deleteKthNode(Node *&head, int k)
{
    if (!head || k <= 0)
        return;

    // Case 1: delete head
    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    // Case 2: traverse to (k-1)-th node
    Node *curr = head;
    for (int i = 1; curr != nullptr && i < k - 1; i++)
    {
        curr = curr->next;
    }

    // If k is invalid
    if (!curr || !curr->next)
        return;

    // Delete k-th node
    Node *temp = curr->next;
    curr->next = curr->next->next;
    delete temp;
}

// Print list
void printList(Node *head)
{
    while (head)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main()
{
    // Hardcoded linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    cout << "Original List: ";
    printList(head);

    int k = 4;
    deleteKthNode(head, k);

    cout << "After deleting " << k << "-th node: ";
    printList(head);

    return 0;
}

/* ---------- Alternate Version -------*/

// Remove every k-th node of the linked list

// Input: LinkedList: 1 -> 2 -> 3 -> 4 -> 5 -> 6, k = 2
// Output: 1 -> 3 -> 5

// Explanation: After removing every 2nd node of the linked list,
// the resultant linked list will be: 1 -> 3 -> 5 .

// Input: LinkedList: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10, k = 3
// Output: 1 -> 2 -> 4 -> 5 -> 7 -> 8 -> 10

// Explanation: After removing every 3rd node of the linked list,
// the resultant linked list will be: 1 -> 2 -> 4 -> 5 -> 7 -> 8 -> 10.

// Time: O(n)
// Space: O(1)

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

// Function to remove every k-th node
void removeEveryKthNode(Node *&head, int k)
{
    if (!head || k <= 0)
        return;

    // Special case: if k == 1, delete entire list
    if (k == 1)
    {
        while (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        return;
    }

    Node *curr = head;
    int count = 1;

    while (curr && curr->next)
    {
        if (count == k - 1)
        {
            Node *temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
            count = 0; // reset after deletion
        }
        curr = curr->next;
        count++;
    }
}

// Print list
void printList(Node *head)
{
    while (head)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main()
{
    // Hardcoded linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);

    cout << "Original List: ";
    printList(head);

    int k = 3;
    removeEveryKthNode(head, k);

    cout << "After removing every " << k << "-th node: ";
    printList(head);

    return 0;
}
