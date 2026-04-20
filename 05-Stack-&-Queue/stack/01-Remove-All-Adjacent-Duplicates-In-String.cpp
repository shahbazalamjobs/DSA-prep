
// You are given a string s consisting of lowercase English letters. 
// A duplicate removal consists of choosing two adjacent and equal letters and removing them. 
// We repeatedly make duplicate removals on s until we no longer can. 
// Return the final string after all such duplicate removals have been made. 
// It can be proven that the answer is unique.


// input : s = abbaca
// output: ca

// input  s = azxxzy
// output : ay


// 1) Using string (stack logic)
// Time: O(n) (each char processed once)
// Space: O(n) (for result)


// Instead of an actual stack, we can use a string as a stack (faster and cleaner).

// 💡 Key Idea (Pareto Style)
// 90% of the problem = compare with last character
// If same → remove
// If different → add

#include <iostream>
using namespace std;

string removeDuplicates(string s) {
    string result;

    for (char c : s) {
        // If result is not empty and last char is same → remove it
        if (!result.empty() && result.back() == c) {
            result.pop_back();
        } 
        else {
            result.push_back(c);
        }
    }

    return result;
}

int main() {
    string s = "abbaca";
    cout << removeDuplicates(s);
    return 0;
}


// 2) Using stack
// Time: O(n)
// Space: O(n)

#include <iostream>
#include <stack>
using namespace std;

string removeDuplicates(string s) {
    stack<char> st;

    for (char c : s) {
        if (!st.empty() && st.top() == c) {
            st.pop();  // remove duplicate
        } else {
            st.push(c);
        }
    }

    // Build result from stack
    string result = "";
    while (!st.empty()) {
        result = st.top() + result;
        st.pop();
    }

    return result;
}

int main() {
    string s = "abbaca";
    cout << removeDuplicates(s);
}


// 3. 2 pointer (Space optimized)
TC: O(n)
SC: O(1)


#include <iostream>
using namespace std;

string removeDuplicates(string s) {
    int j = 0; // write pointer

    for (int i = 0; i < s.size(); i++) {
        s[j] = s[i];  // write current char

        // If duplicate found → remove it
        if (j > 0 && s[j] == s[j - 1]) {
            j -= 2;  // remove last two chars
        }

        j++;
    }

    return s.substr(0, j);
}

int main() {
    string s = "abbaca";
    cout << removeDuplicates(s);
}