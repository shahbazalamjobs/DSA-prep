// 1. Brute Force - Simplest

// Time	O(k + n)
// Space O(1)

#include <iostream>
#include <vector>
using namespace std;

int findKthPositive(vector<int> &arr, int k)
{
    int n = arr.size();
    int missing = 0;
    int curr = 1;
    int i = 0;

    while (true)
    {
        if (i < n && arr[i] == curr)
        {
            i++;
        }
        else
        {
            missing++;
            if (missing == k)
                return curr;
        }
        curr++;
    }
}

int main()
{
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;
    cout << "The " << k << "th missing positive number is: " << findKthPositive(arr, k) << endl;
    return 0;
}

// 2. Optimal Approach (Binary search)
// Time C:  O(log n)
// Space C: O(1)

#include <bits/stdc++.h>
using namespace std;

int findKthMissing(vector<int> &arr, int k)
{
    int low = 0, high = arr.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2; // or (low  + high) / 2 but for safety use 1st only.

        // How many numbers are missing till index mid?
        int missing = arr[mid] - (mid + 1);

        if (missing < k)
        {
            // Missing numbers till mid are less than k, so go right
            low = mid + 1;
        }
        else
        {
            // We have at least k missing numbers till mid, go left
            high = mid - 1;
        }
    }

    // At this point, low is the smallest index where missing >= k
    // So the kth missing number is:
    return low + k;
}

int main()
{
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;
    int result = findKthMissing(arr, k);
    cout << "The " << k << "-th missing number is: " << result << endl;
    return 0;
}

// 3.

// Time	O(k + n)
// Space	O(1)

#include <iostream>
#include <vector>
using namespace std;

int findKthPositive(vector<int> &arr, int k)
{
    int n = arr.size();
    int missing = 0;
    int curr = 1;
    int i = 0;

    while (true)
    {
        if (i < n && arr[i] == curr)
        {
            i++;
        }
        else
        {
            missing++;
            if (missing == k)
                return curr;
        }
        curr++;
    }
}

int main()
{
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;
    cout << "The " << k << "th missing positive number is: " << findKthPositive(arr, k) << endl;
    return 0;
}