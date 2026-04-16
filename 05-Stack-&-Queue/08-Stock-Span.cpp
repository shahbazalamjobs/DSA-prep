
// Stock Span problem

// Given an array price[] where price[i] is the stock price on day i, find the span for each day.
// 👉 Span = number of consecutive days (including today) where price ≤ today’s price.

// e.g.
// Input:
// price = [100, 80, 60, 70, 60, 75, 85]

// Output:
// span  = [1,   1,  1,  2,  1,  4,  6]



// 1. ✅ Optimal Approach (Using Stack)

// Use a stack to store indices
// Pop elements while current price is greater than stack top

// For each i:

// While stack is not empty AND price[stack.top()] <= price[i] → pop
// If stack empty → span = i + 1
// Else → span = i - stack.top()
// Push current index into stack


// tc: O(n), sc: O(n)

#include <bits/stdc++.h>
using namespace std;

vector<int> stockSpan(vector<int>& price) {
    int n = price.size();
    vector<int> span(n);
    stack<int> st; // stores indices

    for (int i = 0; i < n; i++) {
        // Pop smaller or equal elements
        while (!st.empty() && price[st.top()] <= price[i]) {
            st.pop();
        }

        // Calculate span
        if (st.empty()) {
            span[i] = i + 1;
        } else {
            span[i] = i - st.top();
        }

        // Push current index
        st.push(i);
    }

    return span;
}

int main() {
    vector<int> price = {100, 80, 60, 70, 60, 75, 85};

    vector<int> result = stockSpan(price);

    for (int x : result) {
        cout << x << " ";
    }
}



// 2. brute force

// For each day i, go backwards and count how many consecutive days have price ≤ price[i].
// tc: O(N²) and sc: O(N)


#include <bits/stdc++.h>
using namespace std;

vector<int> stockSpan(vector<int>& price) {
    int n = price.size();
    vector<int> span(n);

    for (int i = 0; i < n; i++) {
        span[i] = 1; // at least 1 (itself)

        // check previous days
        for (int j = i - 1; j >= 0; j--) {
            if (price[j] <= price[i]) {
                span[i]++;
            } else {
                break;
            }
        }
    }

    return span;
}

int main() {
    vector<int> price = {100, 80, 60, 70, 60, 75, 85};

    vector<int> result = stockSpan(price);

    for (int x : result) {
        cout << x << " ";
    }
}