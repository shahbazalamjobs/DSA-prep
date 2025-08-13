
// Majority Element problem using the Boyer–Moore Voting Algorithm (O(n) time, O(1) space).

// Given an array of size n, find the element that appears more than
// n/2 times (majority element). Assume such an element always exists.

/*
Input: arr[] = [1, 1, 2, 1, 3, 5, 1]
Output: 1
Explanation: Element 1 appears 4 times. Since ⌊7/2⌋ = 3, and 4 > 3, it is the majority element.

Input: arr[] = [7]
Output: 7
Explanation: Element 7 appears once. Since ⌊1/2⌋ = 0, and 1 > 0, it is the majority element.

Input: arr[] = [2, 13]
Output: -1
Explanation: No element appears more than ⌊2/2⌋ = 1 time, so there is no majority element.
*/

// 1. Moore Algorithm (Assume we have Majority element)
// TC: O(n),
// SC O(1)

// nums = [1, 2, 3, 4]
// n = 4 → n/2 = 2

#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int> &nums)
{
    int candidate = 0, count = 0;

    for (int num : nums)
    {
        if (count == 0)
        {
            candidate = num;
        }

        if (num == candidate)
        {
            count++;
        }
        else
        {
            count--;
        }
    }

    return candidate; // Majority element always exists
}

int main()
{
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    cout << "Majority Element: " << majorityElement(nums) << endl;
    return 0;
}

// 1.2 In case we dont have Majority element then this

#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int> &nums)
{
    int candidate = 0, count = 0;

    // Step 1: Find candidate
    for (int num : nums)
    {
        if (count == 0)
        {
            candidate = num;
        }
        if (num == candidate)
        {
            count++;
        }
        else
        {
            count--;
        }
    }

    // Step 2: (Optional) Verify candidate if not guaranteed
    count = 0;

    for (int num : nums)
    {
        if (num == candidate)
            count++;
    }

    if (count > nums.size() / 2)
    {
        return candidate;
    }

    return -1; // No majority element (only needed if not guaranteed)
}

int main()
{
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    cout << "Majority Element: " << majorityElement(nums) << endl;
    return 0;
}

// 2. Better Approach - Using Sorting
// TC: O(nlog(n))
// SC: O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int majorityElement(vector<int> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());

    // Potential majority element
    int candidate = arr[n / 2];

    // Count how many times candidate appears
    int count = 0;
    for (int num : arr)
    {
        if (num == candidate)
        {
            count++;
        }
    }

    if (count > n / 2)
    {
        return candidate;
    }

    // No majority element
    return -1;
}

int main()
{
    vector<int> arr = {1, 1, 2, 1, 3, 5, 1};

    cout << majorityElement(arr);

    return 0;
}

// 3. Hashing

// TC: O(n)
// SC: O(n)

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int majorityElement(vector<int> &arr)
{

    int n = arr.size();
    unordered_map<int, int> countMap;

    // Traverse the array and count occurrences using the hash map
    for (int num : arr)
    {
        countMap[num]++;

        // Check if current element count exceeds n / 2
        if (countMap[num] > n / 2)
        {
            return num;
        }
    }

    // If no majority element is found, return -1
    return -1;
}

int main()
{
    vector<int> arr = {1, 1, 2, 1, 3, 5, 1};
    cout << majorityElement(arr) << endl;

    return 0;
}

// 4. Brute Force

// TC: O(n^2)
// SC:  and O(1)

#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int> &arr)
{
    int n = arr.size();

    // Loop to consider each element as a
    // candidate for majority
    for (int i = 0; i < n; i++)
    {
        int count = 0;

        // Inner loop to count the frequency of arr[i]
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }

        // Check if count of arr[i] is more
        // than half the size of the array
        if (count > n / 2)
        {
            return arr[i];
        }
    }

    // If no majority element found, return -1
    return -1;
}

int main()
{
    vector<int> arr = {1, 1, 2, 1, 3, 5, 1};

    cout << majorityElement(arr) << endl;

    return 0;
}