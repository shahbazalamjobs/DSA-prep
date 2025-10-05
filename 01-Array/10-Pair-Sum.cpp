/*
You are given:

An array of integers.

A target number.

👉 Find two numbers in the array that add up to the target,
and return their indices.
*/

// 1. Hash Map (unordered_map) -> Most Optimized -> Work for unsorted array as well
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> numToIndex;

    for (int i = 0; i < nums.size(); ++i)
    {
        int complement = target - nums[i];

        if (numToIndex.count(complement))
        {
            return {numToIndex[complement], i};
        }

        numToIndex[nums[i]] = i;
    }

    return {};
}

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(nums, target);

    if (!result.empty())
    {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    }
    else
    {
        cout << "No two sum solution found." << endl;
    }

    return 0;
}

// 2. using 2 pointers (for sorted array) if unsorted then sort the array
// Time Complexity: O(nlogn) + O(n) = O(nlogn)
// Space Complexity: O(1)

// [Note:] For unsorted array, sorting is taking us nlogn time complexity and O(n) for looping
// If we had sorted array then tc would be for loop i.e. O(n)

#include <bits/stdc++.h>
using namespace std;

string twoSum(int n, vector<int> &arr, int target)
{
    sort(arr.begin(), arr.end());
    int left = 0, right = n - 1;
    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (sum == target)
        {
            return "YES";
        }
        else if (sum < target)
            left++;
        else
            right--;
    }
    return "NO";
}

int main()
{
    int n = 5;
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    string ans = twoSum(n, arr, target);
    cout << "This is the answer for variant 1: " << ans << endl;
    return 0;
}


// 3. Brute Force
// TC: O(N2)
// SC: : O(1)

#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(int n, vector<int> &arr, int target)
{
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return {-1, -1};

}



