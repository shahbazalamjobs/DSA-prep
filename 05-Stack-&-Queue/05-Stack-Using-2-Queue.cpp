
// 1. Implement Stack Using 2 Queues in cpp

#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q1, q2; // Two queues

public:
    // Push element into stack
    void push(int x) {
        q1.push(x); // Always push into q1
    }

    // Pop element from stack
    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return;
        }

        // Move elements except last to q2
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        // Last element is the top of stack
        cout << "Popped: " << q1.front() << endl;
        q1.pop();

        // Swap q1 and q2
        swap(q1, q2);
    }

    // Get top element
    int top() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }

        // Move elements except last to q2
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        int topElement = q1.front();
        q2.push(topElement); // keep it in q2
        q1.pop();

        // Swap q1 and q2
        swap(q1, q2);

        return topElement;
    }

    // Check if stack is empty
    bool empty() {
        return q1.empty();
    }
};

int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top: " << st.top() << endl; // 30
    st.pop(); // Pops 30

    cout << "Top: " << st.top() << endl; // 20
    st.pop(); // Pops 20

    cout << "Top: " << st.top() << endl; // 10
    st.pop(); // Pops 10

    st.pop(); // Empty case

    return 0;
}


// TC:
// Push → O(1)
// Pop → O(n)
// Top → O(n)
// Empty → O(1)

// SC: 
// O(n) (for storing n elements across q1 and q2 together, since only one queue is filled at a time).