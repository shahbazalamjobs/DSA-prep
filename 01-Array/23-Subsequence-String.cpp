
// Check if one string is a subsequence of another

// We want to know if all the characters of one string appear in the
// other string in the same order (but not necessarily together).
/*

Example 1:

s1 = "abc"
s2 = "ahbgdc"

Characters of "abc" appear in "ahbgdc" in the same order:

'a' → found at position 0
'b' → found at position 2
'c' → found at position 5
✅ So "abc" is a subsequence of "ahbgdc".

Example 2:

s1 = "axc"
s2 = "ahbgdc"

'a' → found at position 0
'x' → ❌ not found after 'a'
So "axc" is not a subsequence.

*/

// 1. Iterative Solution
// TC: O(n)
// SC: O(n)

#include <bits/stdc++.h>
using namespace std;

bool isSubSeq(const string &s1, const string &s2)
{
    int m = s1.length(), n = s2.length();

    if (m > n)
        return false;

    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (s1[i] == s2[j])
            i++;
        j++;
    }

    return i == m;
}

int main()
{
    string s1 = "gksrek";
    string s2 = "geeksforgeeks";
    isSubSeq(s1, s2) ? cout << "Yes " : cout << "No";
    return 0;
}

// 2. Recursion
// TC: O(n) -> recursion will call at most n times.
// SC: O(n) -> for recursion call stack.

#include <iostream>
#include <string>
using namespace std;

bool isSubsequenceRecHelper(string &s1, string &s2, int i, int j)
{
    if (i == s1.size())
        return true;
    if (j == s2.size())
        return false;

    if (s1[i] == s2[j])
        return isSubsequenceRecHelper(s1, s2, i + 1, j + 1);
    else
        return isSubsequenceRecHelper(s1, s2, i, j + 1);
}

bool isSubsequenceRec(string s1, string s2)
{
    return isSubsequenceRecHelper(s1, s2, 0, 0);
}

int main()
{
    string s1 = "abc", s2 = "ahbgdc";

    if (isSubsequenceRec(s1, s2))
        cout << s1 << " is a subsequence of " << s2 << endl;
    else
        cout << s1 << " is NOT a subsequence of " << s2 << endl;

    return 0;
}
