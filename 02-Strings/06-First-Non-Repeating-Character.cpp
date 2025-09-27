

// You are given a string.
// You need to find the first character that does not repeat in the string.

// If all characters are repeating, return the first character of the string.

/*

Example:

1) s = "aabbcddee"

a → repeats
b → repeats
c → appears only once ✅

2) s = "aabb"
a → repeats
b → repeats
No unique characters ❌ → return first character = 'a'

*/

// 1. HashMap as Frequency Counter
// TC: O(N)
// SC: O(1)

#include <bits/stdc++.h>
using namespace std;

char firstNonRepeatingChar(string &s)
{
    unordered_map<char, int> freq;

    // Step 1: Count frequency of each character
    for (char c : s)
    {
        freq[c]++;
    }

    // Step 2: Find the first character with frequency = 1
    for (char c : s)
    {
        if (freq[c] == 1)
        {
            return c; // first non-repeating character
        }
    }

    // Step 3: If none are unique, return the first character
    return s[0];
}

int main()
{
    string s;
    cin >> s;

    cout << firstNonRepeatingChar(s) << endl;
    return 0;
}

// 2. Array as Frequency Counter (More Efficient than Map)
// TC: O(N)
// SC: O(1)

char firstNonRepeatingChar(string &s)
{
    vector<int> freq(256, 0); // 256 ASCII
    for (char c : s)
        freq[c]++;

    for (char c : s)
    {
        if (freq[c] == 1)
            return c;
    }
    return s[0];
}

// 3. Using Frequency Array (More Efficient than Map)
// TC: O(n)
// SC: O(MAX_CHAR) or  SC = O(1)

#include <bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

char nonRep(const string &s)
{
    vector<int> freq(MAX_CHAR, 0);

    // Count frequency of each character
    for (char c : s)
    {
        freq[c - 'a']++;
    }

    // Find the first non-repeating character
    for (char c : s)
    {
        if (freq[c - 'a'] == 1)
        {
            return c;
        }
    }

    // If all characters repeat, return first character
    return s[0];
}

int main()
{
    string s = "geeksforgeeks";
    cout << nonRep(s) << endl; // Output: 'f'

    string s2 = "aabbcc";
    cout << nonRep(s2) << endl; // Output: 'a' (since all repeat)

    return 0;
}

// 4.  Brute Force (Not Recommended)
// TC: O(N^2)
// SC: O(1)

char firstNonRepeatingChar(string &s)
{
    for (int i = 0; i < s.size(); i++)
    {
        bool unique = true;
        for (int j = 0; j < s.size(); j++)
        {
            if (i != j && s[i] == s[j])
            {
                unique = false;
                break;
            }
        }
        if (unique)
            return s[i];
    }
    return s[0];
}
