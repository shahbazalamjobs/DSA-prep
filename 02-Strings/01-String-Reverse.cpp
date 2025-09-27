
// Reverse String Word Wise

// You are given a sentence (string with words separated by spaces).
// You need to reverse the order of words, but not the characters inside each word.

/*

Input:

"I love programming"

Output:

"programming love I"

*/

// 1. Using STL functions

#include <iostream>
#include <algorithm>
using namespace std;

void reverseStringWordWise(string &s)
{
    reverse(s.begin(), s.end()); // Step 1: reverse whole string

    int start = 0;
    for (int end = 0; end <= s.size(); end++)
    {
        if (end == s.size() || s[end] == ' ')
        {
            reverse(s.begin() + start, s.begin() + end); // Step 2: reverse each word
            start = end + 1;
        }
    }
}

int main()
{
    string s = "I love programming";
    reverseStringWordWise(s);
    cout << s << endl;
    return 0;
}

// 1.1 Using custom reverse function
// TC = O(n)
// SC = O(1)

#include <iostream>
using namespace std;

// Custom reverse function
void myReverse(string &s, int start, int end)
{
    while (start < end)
    {
        swap(s[start], s[end]);
        start++;
        end--;
    }
}

void reverseStringWordWise(string &s)
{
    // Step 1: reverse whole string
    myReverse(s, 0, s.size() - 1);

    // Step 2: reverse each word
    int start = 0;
    for (int end = 0; end <= s.size(); end++)
    {
        if (end == s.size() || s[end] == ' ')
        {
            myReverse(s, start, end - 1);
            start = end + 1;
        }
    }
}

int main()
{
    string s = "I love programming";
    reverseStringWordWise(s);
    cout << s << endl; // Output: "programming love I"
    return 0;
}

// 2. Using Vector (Manual Parsing)

// TC: O(n)
// SC: O(n)

#include <iostream>
#include <vector>
using namespace std;

string reverseWords(string s)
{
    vector<string> words;
    string word = "";

    // Split manually
    for (char c : s)
    {
        if (c == ' ')
        {
            if (!word.empty())
            {
                words.push_back(word);
                word = "";
            }
        }
        else
        {
            word += c;
        }
    }
    if (!word.empty())
        words.push_back(word);

    // Rebuild in reverse order
    string result = "";
    for (int i = words.size() - 1; i >= 0; i--)
    {
        result += words[i];
        if (i > 0)
            result += " ";
    }
    return result;
}

int main()
{
    string s = "I love programming";
    cout << reverseWords(s);
}
