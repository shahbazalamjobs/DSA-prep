
// Given two integer arrays nums1 and nums2, return an array of unique elements that appear in both arrays.
// The order of output does not matter.


// Intersection of Arrays

// [Note]:
// If arrays are sorted, use two pointers (O(n + m), O(1) space); if unsorted, use hash set for optimal time (O(n + m)).
// For sorted arrays, two-pointer is space-efficient; for unsorted, hash set gives best time complexity.

// | Condition                                    | Best Method        | Time Complexity        | Space Complexity |
// | -------------------------------------------- | ------------------ | ---------------------- | ---------------- |
// | Arrays are **sorted**                        | Two-pointer        | `O(n + m)`             | `O(1)` extra     |
// | Arrays **unsorted**                          | Hash set           | `O(n + m)`             | `O(n + k)`       |
// | Arrays unsorted, but want **no extra space** | Sort + two-pointer | `O(n log n + m log m)` | `O(1)` extra     |

// Given two integer unsorted arrays nums1 and nums2, return an array containing
// their intersection — elements that appear in both arrays.
// Each element in the result must be unique.
// Order of output does not matter.

// nums1 = [4, 9, 5], nums2 = [9, 4, 9, 8, 4]
// Output:
// [4, 9] (or [9, 4] — both are correct)

// 1. Using Hashset

// TC: O(n + m)
// SC: O(n + min(n, m))

#include <bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    unordered_set<int> set1(nums1.begin(), nums1.end());
    unordered_set<int> result;

    for (int num : nums2)
    {
        if (set1.count(num))
        {
            result.insert(num);
        }
    }

    return vector<int>(result.begin(), result.end());
}

int main()
{
    vector<int> nums1 = {4, 9, 5};
    vector<int> nums2 = {9, 4, 9, 8, 4};

    vector<int> ans = intersection(nums1, nums2);

    cout << "Intersection: ";
    for (int num : ans)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

// 2. Using 2 Pointers

//  Sort both arrays, then apply two pointers to find common unique elements.

// TC: O(n log n + m log m)
// SC: O(1)

#include <bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    int i = 0, j = 0;
    vector<int> result;

    while (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i] == nums2[j])
        {
            // Only insert if it's not already in result
            if (result.empty() || result.back() != nums1[i])
            {
                result.push_back(nums1[i]);
            }
            ++i;
            ++j;
        }
        else if (nums1[i] < nums2[j])
        {
            ++i;
        }
        else
        {
            ++j;
        }
    }

    return result;
}

int main()
{
    vector<int> nums1 = {4, 9, 5};
    vector<int> nums2 = {9, 4, 9, 8, 4};

    vector<int> ans = intersection(nums1, nums2);

    for (int num : ans)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

// 3. Brute Force

// Time: O(n * m) — nested loops
// Space: O(min(n, m)) — to store the result in a set

#include <bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    unordered_set<int> result;

    for (int i = 0; i < nums1.size(); i++)
    {
        for (int j = 0; j < nums2.size(); j++)
        {
            if (nums1[i] == nums2[j])
            {
                result.insert(nums1[i]);
                break; // Avoid duplicate insertions
            }
        }
    }

    return vector<int>(result.begin(), result.end());
}

int main()
{
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};

    vector<int> ans = intersection(nums1, nums2);

    cout << "Intersection: ";
    for (int num : ans)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

