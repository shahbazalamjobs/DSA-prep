// reverse a queue

// 1. Using Stack (Most Common)
// Time: O(n)
// Space: O(n) (stack)

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseQueue(queue<int>& q) {
    stack<int> st;

    // Step 1: Push all elements into stack
    while (!q.empty()) {
        st.push(q.front());
        q.pop();
    }

    // Step 2: Push back to queue
    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }
}

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    reverseQueue(q);

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}


// 2. Using Recursion (Important for interviews)
// Time: O(n)
// Space: O(n) (recursion stack)


#include <iostream>
#include <queue>
using namespace std;

void reverseQueue(queue<int>& q) {
    // Base case
    if (q.empty()) return;

    int x = q.front();
    q.pop();

    // Reverse remaining queue
    reverseQueue(q);

    // Insert current element at back
    q.push(x);
}

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    reverseQueue(q);

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}