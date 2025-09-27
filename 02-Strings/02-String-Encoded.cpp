
// String Encoding

// Original: aaabbccccdaa
// Encoded: a3b2c4d1a2

// 1. loop

// TC: O(n)
// SC: O(1)

#include <iostream>
#include <string>
using namespace std;

// Run-Length Encoding
string encode(const string &s)
{
    string encoded = "";
    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        int count = 1;

        // Count consecutive characters
        while (i < n - 1 && s[i] == s[i + 1])
        {
            count++;
            i++;
        }

        // Append current character and its count
        encoded += s[i];
        encoded += to_string(count);
    }

    return encoded;
}

int main()
{
    string input = "aaabbccccdaa";
    cout << "Original: " << input << endl;

    string encoded = encode(input);
    cout << "Encoded: " << encoded << endl;

    return 0;
}
