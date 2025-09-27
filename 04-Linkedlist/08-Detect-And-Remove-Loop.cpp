
// Detect if a singly linked list has a loop.
// If yes, remove the loop and return the updated list.

// 1. Example of cycle loop

// Here, node 5 points back to node 3, forming a loop.
// Before (Cycle Present)

// 1 -> 2 -> 3 -> 4 -> 5
//           ^         |
//           |---------|

// After (Loop Removed)
// Here, node 5 points back to node 3, forming a loop.
// 1 -> 2 -> 3 -> 4 -> 5 -> NULL

// 1. [Naive Approach] Detect and Remove Loop using Hashing
// TC: O(n)
// SC: O()


// Logic
// Start from the head and keep adding nodes to a HashSet while moving forward.
// If a node is already in the HashSet, it means a loop exists → set prev->next = NULL to break it.
// If no repeat is found, then there is no loop.


// Function to detect and remove loop in
// a linked list

#include <bits/stdc++.h>
using namespace std;

void removeLoop(Node *head) {

    // hash set to hash addresses of
    // the linked list nodes
    unordered_set<Node *> st;

    // pointer to prev node
    Node *prev = nullptr;
    while (head != nullptr) {

        // if node not present in the map,
        // insert it in the map
        if (st.find(head) == st.end()) {
            st.insert(head);
            prev = head;
            head = head->next;
        }
      
        // if present, it is a cycle, make
        // last node's next pointer NULL
        else {
            prev->next = nullptr;
            break;
        }
    }
}

//Driver Code Starts
int main() {
  
	// Create a hard-coded linked list: 
	// 1 -> 3 -> 4
    Node *head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(4);

	// Create a loop
    head->next->next->next = head->next;

    removeLoop(head);
    printList(head);

    return 0;
}


// 2. [Efficient Approach] Using Floyd's Cycle Detection Algorithm 
// TC: O(n)
// SC: O(1)

// Use two pointers, slow (1 step) and fast (2 steps).
// If they meet → loop exists.
// If fast reaches NULL → no loop.
// Keep moving until one of these happens.

//Driver Code Starts
// C++ program Using Floyd's Cycle Detection Algorithm

#include <bits/stdc++.h>
using namespace std;


// Function to detect and remove loop in a linked list that
// may contain loop
void removeLoop(Node *head) {
  
    // If list is empty or has only one node without loop
    if (head == nullptr || head->next ==nullptr)
        return;

    Node *slow = head, *fast = head;

    // Move slow and fast 1 and 2 steps ahead respectively.
    slow = slow->next;
    fast = fast->next->next;

    // Search for loop using slow and fast pointers
    while (fast && fast->next) {
        if (slow == fast)
            break;
        slow = slow->next;
        fast = fast->next->next;
    }

    // If loop exists
    if (slow == fast) {
        slow = head;

        // this check is needed when slow and fast both meet
        // at the head of the LL
        if (slow == fast)
            while (fast->next != slow)
                fast = fast->next;
        else {
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        // since fast->next is the looping point 
        fast->next = nullptr;
    }
}

//Driver Code Starts
int main() {
  
	// Create a hard-coded linked list:
	// 1 -> 3 -> 4
    Node *head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(4);
  
	// Create a loop
    head->next->next->next = head->next;

    removeLoop(head);
    printList(head);

    return 0;
}