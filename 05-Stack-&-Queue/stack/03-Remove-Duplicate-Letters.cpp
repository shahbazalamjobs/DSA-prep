// Remove Duplicate Letters

// Given a string s, remove duplicate letters so that:

// Every letter appears once and only once
// The result is the smallest in lexicographical (dictionary) order among all possible results

// ex.
// Input:  s = "bcabc"
// Output: "abc"

// Input:  s = "cbacdcbc"
// Output: "acdb"

// Time: O(n)
// Space: O(1) (fixed 26 letters)


#include <bits/stdc++.h>
using namespace std;

string removeDuplicateLetters(string s) {
    vector<int> lastIndex(26);
    
    // Store last occurrence of each character
    for (int i = 0; i < s.size(); i++) {
        lastIndex[s[i] - 'a'] = i;
    }

    vector<bool> visited(26, false);
    stack<char> st;

    for (int i = 0; i < s.size(); i++) {
        char curr = s[i];

        // Skip if already included
        if (visited[curr - 'a']) continue;

        // Maintain lexicographically smallest order
        while (!st.empty() && curr < st.top() &&
               lastIndex[st.top() - 'a'] > i) {
            visited[st.top() - 'a'] = false;
            st.pop();
        }

        st.push(curr);
        visited[curr - 'a'] = true;
    }

    // Build result from stack
    string result = "";
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string s = "cbacdcbc";
    cout << removeDuplicateLetters(s); // Output: "acdb"
}