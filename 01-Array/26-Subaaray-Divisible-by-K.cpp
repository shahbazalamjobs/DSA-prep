

// C++ Code to Count Subarrays With Sum Divisible By K

// 1. using Prefix Sum and Hash map (Optimized)

/*

Logic:

1. Key Idea: Prefix Sums + Modulo

If the sum of elements from index 0 to j is prefixSum[j]

And the sum from index 0 to i-1 is prefixSum[i-1]

Then the sum of subarray arr[i...j] = prefixSum[j] - prefixSum[i-1]

For this subarray’s sum to be divisible by k:

(prefixSum[j]−prefixSum[i−1]) modk = 0

That’s equivalent to:

prefixSum[j]modk=prefixSum[i−1]modk

So — if two prefix sums have the same remainder when divided by k,

the subarray between them is divisible by k.

2. What the code does

Variables:

sum → running prefix sum modulo k
prefCnt → hash map counting how many times each remainder has appeared
res → total number of subarrays found


// Loop over each element:
sum = ((sum + arr[i]) % k + k) % k;



*/

// TC: O(n)
// SC: O(min(n, k))

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subCount(vector<int> &arr, int k)
{
    int n = arr.size(), res = 0;
    unordered_map<int, int> prefCnt;
    int sum = 0;

    // Iterate over all ending points
    for (int i = 0; i < n; i++)
    {

        // prefix sum mod k (handling negative prefix sum)
        sum = ((sum + arr[i]) % k + k) % k; // Means the subarray from start (0) to i is itself divisible by k.

        // If sum == 0, then increment the result by 1
        // to count subarray arr[0...i]
        if (sum == 0)
            res += 1;

        // Add count of all starting points for index i
        res += prefCnt[sum]; // Count subarrays ending at i:

        prefCnt[sum] += 1; // Update frequency map:
    }
    return res;
}

int main()
{
    vector<int> arr = {4, 5, 0, -2, -3, 1};
    int k = 5;

    cout << subCount(arr, k);
}

/*
| i | arr\[i] | sum (mod k) | sum==0? | res before | prefCnt before | Add from prefCnt | res after | prefCnt after   |
| - | ------- | ----------- | ------- | ---------- | -------------- | ---------------- | --------- | --------------- |
| 0 | 4       | 4           | no      | 0          | {}             | +0               | 0         | {4:1}           |
| 1 | 5       | 4           | no      | 0          | {4:1}          | +1               | 1         | {4:2}           |
| 2 | 0       | 4           | no      | 1          | {4:2}          | +2               | 3         | {4:3}           |
| 3 | -2      | 2           | no      | 3          | {4:3}          | +0               | 3         | {4:3, 2:1}      |
| 4 | -3      | 4           | no      | 3          | {4:3, 2:1}     | +3               | 6         | {4:4, 2:1}      |
| 5 | 1       | 0           | yes(+1) | 6          | {4:4, 2:1}     | +0               | 7         | {4:4, 2:1, 0:1} |


// Final result: 7

*/

// 2. Iterating over all subarrays

// C++ Code to Count Subarrays With Sum Divisible By K
// by iterating over all possible subarrays

// TC: O(n^2)
// SC: O(1)

#include <iostream>
#include <vector>

using namespace std;

int subCount(vector<int> &arr, int k)
{
    int n = arr.size(), res = 0;

    // Iterating over starting indices of subarray
    for (int i = 0; i < n; i++)
    {
        int sum = 0;

        // Iterating over ending indices of subarray
        for (int j = i; j < n; j++)
        {
            sum = (sum + arr[j]) % k;
            if (sum == 0)
                res += 1;
        }
    }
    return res;
}

int main()
{
    vector<int> arr = {4, 5, 0, -2, -3, 1};
    int k = 5;

    cout << subCount(arr, k);
}