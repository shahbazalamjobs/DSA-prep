
// A binary string is a string made up of only 0 and 1.
// The condition is: no two 1s should be next to each other.

// ✅ Valid strings (no two 1s together):
// 0, 1, 00, 01, 10, 010, 1010

// ❌ Invalid strings (have consecutive 1s):
// 11, 110, 1011, 1110

// 1.
// TC:  O(N⋅f(N)) // It follows fibonacci seq and upper bound worst case will be O(N^2)
// SC: O(N)

#include <bits/stdc++.h>
using namespace std;

void generateStrings(string str, int n, int last)
{
    // If length of string is n, print it
    if (str.length() == n)
    {
        cout << str << " ";
        return;
    }

    // Always can put '0'
    generateStrings(str + "0", n, 0);

    // Can put '1' only if last was not '1'
    if (last == 0)
    {
        generateStrings(str + "1", n, 1);
    }
}

int main()
{
    int N;
    cout << "Enter N: ";
    cin >> N;

    generateStrings("", N, 0);

    return 0;
}
