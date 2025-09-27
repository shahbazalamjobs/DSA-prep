
// Two strings are anagrams if they have the same characters with the same frequency, but order doesn’t matter.

// Example:
// "listen" → "silent" ✅ anagram
// "race" → "caree" ❌ not anagram

// 1. [Naive Approach] Using Sorting
// TC: O(n + m) or O(n)
// SC: O(1)

#include <algorithm>
#include <iostream>
using namespace std;

bool areAnagrams(string &s1, string &s2)
{

    if (s1.length() != s2.length())
        return false;

    // Sort both strings
    sort(s1.begin(), s1.end()); // O(n log n)
    sort(s2.begin(), s2.end()); // O(n log n)

    // Compare sorted strings
    return (s1 == s2); // O(n)
}

int main()
{

    string s1 = "geeks";
    string s2 = "kseeg";

    if (areAnagrams(s1, s2))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}

// 2. [Expected Approach 1] Using Hash Map or Dictionary
// TC: O(n + m) or O(n)
// SC: O(1) // fixed array of 26

#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool areAnagrams(string &s1, string &s2)
{

    if (s1.size() != s2.size())
    {
        return false;
    }

    // create a hashmap to store
    // character frequencies
    unordered_map<char, int> charCount;

    // count frequency of each
    // character in string s1
    for (char ch : s1)
        charCount[ch] += 1;

    // Count frequency of each
    // character in string s2
    for (char ch : s2)
        charCount[ch] -= 1;

    // check if all frequencies are zero
    for (auto &pair : charCount)
    {
        if (pair.second != 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{

    string s1 = "geeks";
    string s2 = "kseeg";

    if (areAnagrams(s1, s2))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

    return 0;
}

// 3. [Expected Approach 2] Using Frequency Array
// TC: O(n)
// SC: O(1) // fixed array of 26

#include <iostream>
#include <vector>
using namespace std;

bool areAnagrams(string &s1, string &s2)
{

    if (s1.length() != s2.length())
        return false;

    // for lowercase a-z
    vector<int> freq(26, 0);

    // Count frequency of each character in s1
    for (char ch : s1)
        freq[ch - 'a']++;

    // Subtract frequency using characters from s2
    for (char ch : s2)
        freq[ch - 'a']--;

    // If any count is not zero, not an anagram
    for (int count : freq)
    {
        if (count != 0)
            return false;
    }

    return true;
}

int main()
{

    string s1 = "geeks";
    string s2 = "kseeg";

    if (areAnagrams(s1, s2))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}