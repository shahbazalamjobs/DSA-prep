
/*

We are given a binary string (only 0 and 1).
A string is called beautiful if it has alternating 0s and 1s.

"0101" ✅
"1010" ✅
"101" ✅

"0001" ❌ (two 0s together)
"1110" ❌ (two 1s together)


We want to make the string beautiful by performing minimum operations.
👉 In one operation, we can flip (change) a character:

'0' → '1'
'1' → '0'

Ideal beautiful strings of length 4 can be only two types:
"0101"
"1010"

*/

// STR = "1001"

// 1. Brute Force Approach (Less optimized)
// TC: O(N)
// SC: O(N)

#include <bits/stdc++.h>
using namespace std;

int makeBeautiful(string s)
{
    int n = s.length();

    // Two possible target strings
    string alt1 = ""; // starts with '0'
    string alt2 = ""; // starts with '1'

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            alt1 += '0';
            alt2 += '1';
        }
        else
        {
            alt1 += '1';
            alt2 += '0';
        }
    }

    // Count mismatches with both
    int diff1 = 0, diff2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != alt1[i])
            diff1++;
        if (s[i] != alt2[i])
            diff2++;
    }

    // Minimum flips needed
    return min(diff1, diff2);
}

int main()
{
    string str = "1001";
    cout << "Minimum changes needed: " << makeBeautiful(str) << endl;
    return 0;
}

// 2. More space optimized
// TC: O(N)
// SC: O(1)

/*
⚡ Optimization:
We don’t actually need to store alt1 and alt2.
We can just check on the fly:

At even index → expect 0 in alt1, 1 in alt2
At odd index → expect 1 in alt1, 0 in alt2
That way, space reduces to O(1).
*/

#include <bits/stdc++.h>
using namespace std;

int makeBeautiful(string s)
{
    int n = s.length();
    int diff1 = 0, diff2 = 0;

    for (int i = 0; i < n; i++)
    {
        char expected1 = (i % 2 == 0) ? '0' : '1'; // pattern "0101.."
        char expected2 = (i % 2 == 0) ? '1' : '0'; // pattern "1010.."

        if (s[i] != expected1)
            diff1++;
        if (s[i] != expected2)
            diff2++;
    }

    return min(diff1, diff2);
}

int main()
{
    string str = "1001";
    cout << "Minimum changes needed: " << makeBeautiful(str) << endl;
    return 0;
}