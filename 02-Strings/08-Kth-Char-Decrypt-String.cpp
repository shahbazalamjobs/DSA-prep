

// You are given an encrypted string where:
// A substring is followed by a number = how many times it repeats.

// Example:
// "a2b3cd3" → decrypted = "aabbbcdcdcd"
// "ab12c3" → decrypted = "ababababababababababababccc"
// [Note] : ab12 mean ab 12 times not a -> 1 and b -> 12 times

/*
Encrypted: "a2b3cd3", K = 5

"a2" → "aa" (length 2)
"b3" → "bbb" (length 3, total = 5)

So the 5th char lies in "b3". → Answer = "b" ✅
*/

// 1.
// TC: O(N)
// SC: O(N)

#include <bits/stdc++.h>
using namespace std;

// Function to find Kth character in decrypted string
char findKthChar(const string &s, long long K)
{
    int n = s.size();
    int i = 0;

    while (i < n)
    {
        // Step 1: Extract the substring (letters only)
        string sub = "";
        while (i < n && isalpha(s[i]))
        {
            sub += s[i];
            i++;
        }

        // Step 2: Extract the count (digits only)
        string numStr = "";
        while (i < n && isdigit(s[i]))
        {
            numStr += s[i];
            i++;
        }
        long long count = stoll(numStr);

        // Step 3: Calculate total length contributed by this block
        long long blockLen = (long long)sub.size() * count;

        // Step 4: Check if K falls in this block
        if (K <= blockLen)
        {
            // Find which repetition and which char inside substring
            long long index = (K - 1) % sub.size();
            return sub[index];
        }

        // Else, move K forward
        K -= blockLen;
    }

    return '?'; // In case K is invalid
}

int main()
{
    string encrypted;
    long long K;

    // Example input
    // encrypted = "a2b3cd3";
    // K = 5 → answer = 'b'
    cin >> encrypted >> K;

    cout << findKthChar(encrypted, K) << endl;

    return 0;
}

// 2.  Space optimized above code by not using substring
// TC: O(N)
// SC: O(1)

#include <bits/stdc++.h>
using namespace std;

// Function to find Kth character in decrypted string
char findKthChar(const string &s, long long K)
{
    int n = s.size();
    int i = 0;

    while (i < n)
    {
        // Step 1: Count length of substring (letters only)
        int start = i;
        int subLen = 0;
        while (i < n && isalpha(s[i]))
        {
            subLen++;
            i++;
        }

        // Step 2: Extract the count (digits only) without storing string
        long long count = 0;
        while (i < n && isdigit(s[i]))
        {
            count = count * 10 + (s[i] - '0');
            i++;
        }

        // Step 3: Calculate total length contributed by this block
        long long blockLen = (long long)subLen * count;

        // Step 4: Check if K falls in this block
        if (K <= blockLen)
        {
            // Find position inside substring
            long long index = (K - 1) % subLen;
            return s[start + index]; // direct access from original string
        }

        // Else, move K forward
        K -= blockLen;
    }

    return '?'; // In case K is invalid
}

int main()
{
    string encrypted;
    long long K;

    // Example input
    // encrypted = "a2b3cd3";
    // K = 5 → answer = 'b'
    cin >> encrypted >> K;

    cout << findKthChar(encrypted, K) << endl;

    return 0;
}
