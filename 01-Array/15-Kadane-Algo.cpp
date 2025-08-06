
// Given an integer array arr, find the contiguous subarray
// (containing at least one number) which has the largest sum
// and returns its sum and prints the subarray.

/*
Example 1:

Input: arr = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6

Explanation: [4,-1,2,1] has the largest sum = 6.

Examples 2:
Input: arr = [1]
Output: 1

Explanation: Array has only one element and which is giving positive sum of 1.
*/

// 1. Kadane Optimal Approach / Standard Kadane's Algo
// Here we are only returning sum not array

// tc: O(N)
// sc: o(1)

#include <iostream>
#include <vector>
#include <algorithm> // For std::max

using namespace std;

int kadane(vector<int> &nums)
{
    if (nums.empty())
        return 0; // Handle empty array case

    int max_current = nums[0];
    int max_global = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        max_current = max(nums[i], max_current + nums[i]);
        max_global = max(max_global, max_current);
    }

    return max_global;
}

int main()
{
    vector<int> test1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Test 1 (Expected: 6): " << kadane(test1) << endl;

    return 0;
}

// Here returning sum as well array

// tc: O(N)
// sc: o(k) k-> size of subarray

#include <iostream>
#include <vector>
#include <utility> // For std::pair
#include <climits>

using namespace std;

pair<int, vector<int>> kadaneWithSubarray(vector<int> &nums)
{
    if (nums.empty())
        return {0, {}};

    int max_current = nums[0];
    int max_global = nums[0];
    int start = 0, end = 0; // start and end indices of the max subarray
    int temp_start = 0;     // temporary start index for current sum

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > max_current + nums[i])
        {
            max_current = nums[i];
            temp_start = i;
        }
        else
        {
            max_current += nums[i]; // extend current subarray
        }

        // update global max and subarray indices if current sum exceeds previous max
        if (max_current > max_global)
        {
            max_global = max_current;
            start = temp_start;
            end = i;
        }
    }

    // extract the subarray that gave the maximum sum
    vector<int> subarray(nums.begin() + start, nums.begin() + end + 1);
    return {max_global, subarray};
}

int main()
{
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    auto result = kadaneWithSubarray(arr);
    int max_sum = result.first;
    vector<int> max_subarray = result.second;

    // demonstration of how to use the returned values:
    cout << "Returned max sum: " << max_sum << endl;
    cout << "Returned subarray: [";
    for (int i = 0; i < max_subarray.size(); i++)
    {
        cout << max_subarray[i];
        if (i != max_subarray.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}

// 2.1 Brute Force (just returning the maxSum)

// tc: O(n²)
// sc: o(1)

// Brute force Kadane's algorithm
int kadaneBruteForce(const vector<int> &nums)
{
    int maxSum = INT_MIN;
    int n = nums.size();

    for (int i = 0; i < n; ++i)
    {
        int currentSum = 0;
        for (int j = i; j < n; ++j)
        {
            currentSum += nums[j];
            maxSum = max(maxSum, currentSum);
        }
    }

    return maxSum;
}

// 2.1 Brute Force (returning the maxSum, vector)

// tc: O(n²)
// sc: o(n)

// Returns pair: {max sum, subarray vector}
pair<int, vector<int>> kadaneBruteForce2(const vector<int> &nums)
{
    int maxSum = INT_MIN;
    int n = nums.size();
    vector<int> bestSubarray;

    for (int i = 0; i < n; ++i)
    {
        int currentSum = 0;
        vector<int> temp;

        for (int j = i; j < n; ++j)
        {
            currentSum += nums[j];
            temp.push_back(nums[j]);

            if (currentSum > maxSum)
            {
                maxSum = currentSum;
                bestSubarray = temp;
            }
        }
    }

    return {maxSum, bestSubarray};
}