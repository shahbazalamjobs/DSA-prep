

// You are given a list of words.
// You need to group together words that are anagrams of each other.
// Anagram = words made up of the same letters, just rearranged.

/*

Input: ["eat", "tea", "tan", "ate", "nat", "bat"]
Output: [["eat","tea","ate"], ["tan","nat"], ["bat"]]

*/

// 1. [Naive Approach] Using sorted words as keys
// TC: O(n * k log k)
// SC: O(n * k)
// n = number of strings
// k = average length of each string

#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &inputStr)
{
    // Map: sorted string → list of anagrams
    unordered_map<string, vector<string>> mp;

    for (string s : inputStr)
    {
        string key = s;
        sort(key.begin(), key.end()); // sort each word to get its "signature"
        mp[key].push_back(s);
    }

    // Collect grouped anagrams into result
    vector<vector<string>> result;
    for (auto &entry : mp)
    {
        result.push_back(entry.second);
    }

    return result;
}

int main()
{
    vector<string> inputStr = {"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> grouped = groupAnagrams(inputStr);

    // Print result
    for (auto group : grouped)
    {
        cout << "{ ";
        for (auto word : group)
        {
            cout << word << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}

// 2. More Optimized: avoiding sorting each string. Using Frequency as keys
// Time Complexity: O(n * k)
// Space Complexity: O(n * k)

#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &inputStr)
{
    unordered_map<string, vector<string>> mp;

    for (string s : inputStr)
    {
        // Frequency array of 26 letters
        vector<int> freq(26, 0);
        for (char c : s)
        {
            freq[c - 'a']++;
        }

        // Build key string from frequency array
        string key = "";
        for (int count : freq)
        {
            key += "#" + to_string(count); // separator to avoid ambiguity
        }

        mp[key].push_back(s);
    }

    // Collect result
    vector<vector<string>> result;
    for (auto &entry : mp)
    {
        result.push_back(entry.second);
    }
    return result;
}

int main()
{
    vector<string> inputStr = {"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> grouped = groupAnagrams(inputStr);

    // Print result
    for (auto group : grouped)
    {
        cout << "{ ";
        for (auto word : group)
        {
            cout << word << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}
