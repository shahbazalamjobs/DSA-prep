
// 1. Reverse a Linked List
// TC: O(n)
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

// Insert at head (just for building list quickly)
void insertAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

// Reverse linked list
Node *reverseList(Node *head)
{
    Node *prev = nullptr;
    Node *curr = head;
    Node *next = nullptr;

    while (curr != nullptr)
    {
        next = curr->next; // save next
        curr->next = prev; // reverse pointer
        prev = curr;       // move prev forward
        curr = next;       // move curr forward
    }
    return prev; // new head
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

    // Create list: 1->2->3->4->NULL
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);

    cout << "Original List: ";
    printList(head);

    head = reverseList(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}

// 2. Recursive way
// TC: O(n)
// SC: O(n)

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

// Recursive reverse function
Node *reverseRecursive(Node *head)
{
    // Base case: empty list OR only one node
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    // Reverse rest of the list
    Node *newHead = reverseRecursive(head->next);

    // Fix current node’s link
    head->next->next = head;
    head->next = nullptr;

    return newHead; // return new head of reversed list
}

// Helper: insert at head
void insertAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

// Helper: print list
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
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);

    cout << "Original List: ";
    printList(head);

    head = reverseRecursive(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}

// 3. Stack
// TC: O(n)
// SC: O(n)

#include <iostream>
#include <stack>
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

// Reverse using stack
Node *reverseUsingStack(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    stack<Node *> st;

    // Push all nodes onto stack
    Node *temp = head;
    while (temp != nullptr)
    {
        st.push(temp);
        temp = temp->next;
    }

    // Pop to rebuild reversed list
    Node *newHead = st.top();
    st.pop();
    temp = newHead;

    while (!st.empty())
    {
        temp->next = st.top();
        st.pop();
        temp = temp->next;
    }
    temp->next = nullptr; // last node should point to NULL

    return newHead;
}

// Insert at head
void insertAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
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
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);

    cout << "Original List: ";
    printList(head);

    head = reverseUsingStack(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}
