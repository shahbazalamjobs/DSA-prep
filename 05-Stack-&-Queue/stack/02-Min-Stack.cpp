
// Min Stack (Short)

// Design a stack that supports push, pop, top, and getMin operations, all in O(1) time.

// 📘 Functions:
// MinStack() → Initialize stack
// push(int val) → Add element
// pop() → Remove top element
// top() → Return top element


#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> st;      // main stack
    stack<int> minSt;   // keeps track of minimums

public:
    // Constructor
    MinStack() {
    }

    // Push element
    void push(int val) {
        st.push(val);

        // If min stack is empty OR new value is smaller
        if (minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        } else {
            // Repeat the current minimum
            minSt.push(minSt.top());
        }
    }

    // Pop element
    void pop() {
        if (!st.empty()) {
            st.pop();
            minSt.pop();
        }
    }

    // Get top element
    int top() {
        return st.top();
    }

    // Get minimum element
    int getMin() {
        return minSt.top();
    }
};

// Dry run example
// Operations: push(5), push(2), push(8), push(1)

// st     = [5, 2, 8, 1]
// minSt  = [5, 2, 2, 1]

// getMin() → 1

// After pop():
// st     = [5, 2, 8]
// minSt  = [5, 2, 2]

// getMin() → 2