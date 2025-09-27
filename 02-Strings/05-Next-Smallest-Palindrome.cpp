

// You are given a number/string (like "1234").
// You need to find the next palindrome that is greater than this number.

// A palindrome is something that reads the same forward and backward (like 121, 1331, 1221).

// Example 1:
// Input: "1234"
// Next palindrome is "1331"
// "1221" is smaller than 1234 (so not valid).
// "1331" is the next bigger palindrome. ✅

// Example 2:
// Input: "999"
// Next palindrome is "1001"
// After 999, the next palindrome is 1001.

// TC: O(N)
// SC: O(N)

#include <bits/stdc++.h>
using namespace std;

string nextPalindrome(string num)
{
    int n = num.size();
    string pal = num;

    // Step 1: Mirror left half to right half  --> O(N/2) ≈ O(N)
    for (int i = 0; i < n / 2; i++)
    {
        pal[n - 1 - i] = pal[i];
    }

    // Step 2: Compare two strings --> O(N)
    if (pal > num)
        return pal;

    // Step 3: Increment middle digits --> Worst case carry can propagate across all digits --> O(N)
    int carry = 1;
    int mid = (n - 1) / 2;

    while (mid >= 0 && carry)
    {
        int digit = (pal[mid] - '0') + carry;
        carry = digit / 10;
        pal[mid] = (digit % 10) + '0';
        mid--;
    }

    // Step 4: Overflow case (e.g., 999 -> 1001) --> Construct new string of size n+1 --> O(N)
    if (carry)
    {
        pal = "1" + string(n - 1, '0') + "1";
        return pal;
    }

    // Step 5: Mirror again after increment --> O(N/2) ≈ O(N)
    for (int i = 0; i < n / 2; i++)
    {
        pal[n - 1 - i] = pal[i];
    }

    return pal;
}

int main()
{
    string num;
    cout << "Enter number: ";
    cin >> num;

    cout << "Next palindrome: " << nextPalindrome(num) << endl;
    return 0;
}

// 2. now same problem for array of numbers
// TC: O(N)
// SC: O(N)

#include <bits/stdc++.h>
using namespace std;

vector<int> nextPalindrome(vector<int> num)
{
    int n = num.size();
    vector<int> pal = num;

    // Step 1: Mirror left half to right half
    for (int i = 0; i < n / 2; i++)
    {
        pal[n - 1 - i] = pal[i];
    }

    // Step 2: If palindrome is greater, return it
    if (pal > num)
        return pal;

    // Step 3: Increment the middle with carry
    int carry = 1;
    int mid = (n - 1) / 2;

    while (mid >= 0 && carry)
    {
        int digit = pal[mid] + carry;
        pal[mid] = digit % 10;
        carry = digit / 10;
        mid--;
    }

    // If overflow (like 999 → 1001)
    if (carry)
    {
        vector<int> result(n + 1, 0);
        result[0] = result[n] = 1;
        return result;
    }

    // Step 4: Mirror again
    for (int i = 0; i < n / 2; i++)
    {
        pal[n - 1 - i] = pal[i];
    }

    return pal;
}

int main()
{
    vector<int> num = {9, 9, 9}; // Example input

    vector<int> ans = nextPalindrome(num);

    cout << "Next palindrome: ";
    for (int d : ans)
        cout << d;
    cout << endl;
}
