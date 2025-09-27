
// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// 1.

// Time Complexity
// Each operation (push, pop, top, getMin) → O(1)
// Amortized & Worst Case: O(1)

// Space Complexity
// Uses two stacks:
// s → stores all elements → O(n)
// minS → stores only minimum elements, in worst case every pushed element is new min → O(n)
// ✅ Overall: O(n)

#include <iostream>
#include <stack>
using namespace std;

class MinStack {
    stack<int> s;       // main stack
    stack<int> minS;    // helper stack to track minimums

public:
    // Push element onto stack
    void push(int x) {
        s.push(x);
        // If minS is empty or x <= current minimum, push to minS
        if (minS.empty() || x <= minS.top()) {
            minS.push(x);
        }
    }

    // Remove top element
    void pop() {
        if (s.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        // If top element is the current minimum, pop from minS also
        if (s.top() == minS.top()) {
            minS.pop();
        }
        s.pop();
    }

    // Get top element
    int top() {
        if (s.empty()) {
            cout << "Stack is empty\n";
            return -1; // or throw exception
        }
        return s.top();
    }

    // Retrieve minimum element in O(1)
    int getMin() {
        if (minS.empty()) {
            cout << "Stack is empty\n";
            return -1; // or throw exception
        }
        return minS.top();
    }
};

int main() {
    MinStack ms;
    ms.push(5);
    ms.push(3);
    ms.push(7);
    ms.push(2);

    cout << "Current Min: " << ms.getMin() << endl; // 2
    ms.pop();
    cout << "Current Min: " << ms.getMin() << endl; // 3
    ms.pop();
    cout << "Top: " << ms.top() << endl;            // 3
    cout << "Current Min: " << ms.getMin() << endl; // 3

    return 0;
}
