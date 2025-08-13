
// Dutch National Flag

// Given an array containing only three distinct values (commonly thought of as 0, 1, and 2),
// rearrange the array in-place so that all 0s come first, then all 1s, then all 2s.
// Constraints: do it in one pass (O(n) time) using constant extra space (O(1)).

// Example:
// Input: [2, 0, 2, 1, 1, 0]
// Output: [0, 0, 1, 1, 2, 2]

// 1. DNF algo
// TC: O(n)
// ✅ SC: O(1)

#include <iostream>
#include <vector>
using namespace std;

void dutchNationalFlag(vector<int> &arr)
{
    int low = 0, mid = 0, high = arr.size() - 1;

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        { // arr[mid] == 2
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main()
{
    vector<int> arr = {2, 0, 2, 1, 1, 0};
    dutchNationalFlag(arr);

    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

// 2. Brute Force
// TC: O(n)
// ✅ SC: O(1)

#include <iostream>
#include <vector>
using namespace std;

void dutchNationalFlagBrute(vector<int> &arr)
{
    int count0 = 0, count1 = 0, count2 = 0;

    // Step 1: Count frequency of 0, 1, 2
    for (int num : arr)
    {
        if (num == 0)
            count0++;
        else if (num == 1)
            count1++;
        else
            count2++;
    }

    // Step 2: Fill array again in sorted order
    int index = 0;
    while (count0--)
        arr[index++] = 0;
    while (count1--)
        arr[index++] = 1;
    while (count2--)
        arr[index++] = 2;
}

int main()
{
    vector<int> arr = {2, 0, 2, 1, 1, 0};
    dutchNationalFlagBrute(arr);

    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

// Different problems using same type of logic:

// type 1: 1) Rainbow Sort — multiple categories (extended DNF)
// You have an array with more than 3 distinct values (e.g., {0,1,2,3,4} for colors).
// You need to sort them in one pass style, but now categories are more than 3.

// Input:  [3, 0, 1, 4, 2, 3, 0, 1]
// Output: [0, 0, 1, 1, 2, 3, 3, 4]

#include <bits/stdc++.h>
using namespace std;

void rainbowSort(vector<int> &arr, int minVal, int maxVal)
{
    int start = 0, end = arr.size() - 1;

    for (int val = minVal; val <= maxVal; val++)
    {
        int i = start;
        while (i <= end)
        {
            if (arr[i] == val)
            {
                swap(arr[i], arr[start]);
                start++;
                i++;
            }
            else
            {
                i++;
            }
        }
    }
}

int main()
{
    vector<int> arr = {3, 0, 1, 4, 2, 3, 0, 1};
    rainbowSort(arr, 0, 4);
    for (int x : arr)
        cout << x << " ";
}

// type 2: 2) Partition array around a pivot

// Given an array and a pivot element, rearrange it so that:
// All elements < pivot come first
// All elements == pivot come next
// All elements > pivot come last

// Input:  arr = [9, 12, 3, 5, 14, 10, 10], pivot = 10
// Output: [3, 5, 9, 10, 10, 14, 12]  // (order inside groups doesn't matter)

#include <bits/stdc++.h>
using namespace std;

void partitionAroundPivot(vector<int> &arr, int pivot)
{
    int low = 0, mid = 0, high = arr.size() - 1;

    while (mid <= high)
    {
        if (arr[mid] < pivot)
        {
            swap(arr[low++], arr[mid++]);
        }
        else if (arr[mid] == pivot)
        {
            mid++;
        }
        else
        { // arr[mid] > pivot
            swap(arr[mid], arr[high--]);
        }
    }
}

int main()
{
    vector<int> arr = {9, 12, 3, 5, 14, 10, 10};
    int pivot = 10;
    partitionAroundPivot(arr, pivot);
    for (int x : arr)
        cout << x << " ";
}

// type 3: 3) Segregate even and odd numbers
// Rearrange array so that even numbers come before odd numbers.

// Input:  [12, 17, 70, 15, 22, 65, 21, 90]
// Output: [12, 70, 22, 90, 17, 15, 65, 21]

// This is a 2-way partition problem (like DNF without the middle category).

#include <bits/stdc++.h>
using namespace std;

void segregateEvenOdd(vector<int> &arr)
{
    int low = 0, high = arr.size() - 1;

    while (low < high)
    {
        if (arr[low] % 2 == 0)
        {
            low++;
        }
        else if (arr[high] % 2 == 1)
        {
            high--;
        }
        else
        {
            swap(arr[low], arr[high]);
            low++;
            high--;
        }
    }
}

int main()
{
    vector<int> arr = {12, 17, 70, 15, 22, 65, 21, 90};
    segregateEvenOdd(arr);
    for (int x : arr)
        cout << x << " ";
}
