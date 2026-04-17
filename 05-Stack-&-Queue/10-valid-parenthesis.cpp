
// Valid Parentheses

// Given a string s containing just the characters:

// '(', ')', '{', '}', '[' and ']'

// Determine if the input string is valid.

// ✅ A string is valid if:
// Open brackets are closed by the same type
// Open brackets are closed in the correct order
// Every closing bracket has a corresponding opening bracket


// Examples

// Input: s = "()"
// Output: true

// Input: s = "()[]{}"
// Output: true

// Input: s = "(]"
// Output: false

// Input: s = "([)]"
// Output: false

// Input: s = "{[]}"
// Output: true


// 1) Using stack
// Time: O(n)
// Space: O(n) (stack)

#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack<char> st;

    for (char c : s) {
        // If opening bracket, push
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        }
        else {
            // If stack empty → invalid
            if (st.empty()) return false;

            char top = st.top();
            st.pop();

            // Check matching
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
            }
        }
    }

    // Stack should be empty
    return st.empty();
}

int main() {
    string s = "{[]}";
    cout << (isValid(s) ? "Valid" : "Invalid");
}



// 2) Using hashmap
// Time: O(n)
// Space: O(n)

#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

bool isValid(string s) {
    stack<char> st;

    // HashMap for matching brackets
    unordered_map<char, char> mp = {
        {')', '('},
        {'}', '{'},
        {']', '['}
    };

    for (char c : s) {
        // If it's a closing bracket
        if (mp.count(c)) {
            // Check if stack is empty OR top doesn't match
            if (st.empty() || st.top() != mp[c]) {
                return false;
            }
            st.pop();
        } else {
            // It's an opening bracket
            st.push(c);
        }
    }

    return st.empty();
}

int main() {
    string s = "([{}])";
    cout << (isValid(s) ? "Valid" : "Invalid");
}