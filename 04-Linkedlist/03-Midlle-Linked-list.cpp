

// Middle of a Linked list

// 1. [Expected Approach] Hare and Tortoise Algorithm
// TC: O(n)
// SC: O(1)

// Hare and Tortoise Algorithm

// Initialize both slow and fast pointers at the head.
// Move slow by one step and fast by two steps each iteration.
// When fast reaches the end (or null), slow will be at the middle.

// For even nodes, slow automatically ends at the second middle. [Imp]

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

// Insert at head (for testing)
void insertAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

// Function to find midpoint
Node *findMid(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;       // Move 1 step
        fast = fast->next->next; // Move 2 steps
    }
    return slow;
}

// Print list
void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main()
{
    Node *head = nullptr;

    // Create list: 1 -> 2 -> 3 -> 4 -> 5
    for (int i = 5; i >= 1; i--)
    {
        insertAtHead(head, i);
    }

    printList(head);

    Node *mid = findMid(head);
    if (mid != nullptr)
        cout << "Midpoint: " << mid->data << endl;

    return 0;
}

// 2.[Naive Approach] Two Passes

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        this->data = x;
        this->next = nullptr;
    }
};

int getLength(Node *head)
{

    int length = 0;

    // Count nodes in linked list
    while (head)
    {
        length++;
        head = head->next;
    }

    return length;
}

int getMiddle(Node *head)
{

    // finding length of the linked list
    int length = getLength(head);

    // traverse till we reached half of length
    int midIndex = length / 2;
    while (midIndex--)
    {
        head = head->next;
    }

    return head->data;
}

int main()
{

    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next = new Node(60);

    cout << getMiddle(head);

    return 0;
}