

// Encoded: a3b2c4d1a2
// Decoded: aaabbccccdaa

// 1.
// TC: O(n + m)
// SC: O(m)

// n = length of encoded string
// m = length of decoded string

#include <iostream>
#include <string>
using namespace std;

// Run-Length Decoding
string decode(const string &s)
{
    string decoded = "";
    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        char ch = s[i]; // character
        string countStr = "";

        // Collect digits after character
        while (i + 1 < n && isdigit(s[i + 1]))
        {
            countStr += s[i + 1];
            i++;
        }

        int count = stoi(countStr); // convert string to int

        // Append the character 'count' times
        decoded.append(count, ch);
    }

    return decoded;
}

int main()
{
    string encoded = "a3b2c4d1a2";
    cout << "Encoded: " << encoded << endl;

    string decoded = decode(encoded);
    cout << "Decoded: " << decoded << endl;

    return 0;
}
