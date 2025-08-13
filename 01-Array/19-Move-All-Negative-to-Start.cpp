
// You are given an array of numbers (some negative, some positive).
// 👉 Your task is to move all negative numbers to the front of the array and positive numbers to the back.

// You don’t need to keep the original order of the numbers.
// Just make sure all negatives come before positives.

// 1.  Quick Sort Partition

// TC = O(n)
// SC = O(1)

#include <bits/stdc++.h>
using namespace std;

vector<int> move(vector<int> &arr)
{
    int j = 0;
    for (int i = 0; i < arr.size(); i++)
    {

        // If negative number is present
        // swap it with arr[j]
        if (arr[i] < 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }

    return arr;
}

int main()
{
    vector<int> arr = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
    vector<int> ans = move(arr);

    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

// 2. 2 pointers approach

// ✅ Approach: Use the two-pointer technique: one pointer from the start and one from the end.
// Swap negative numbers to the left and positive numbers to the right.
// Since the order doesn’t matter, this approach is both efficient (O(n) time, O(1) space) and simple.

// TC = O(n)
// SC = O(1)

#include <iostream>
#include <vector>
using namespace std;

void rearrangeArray(vector<int> &arr)
{
    int left = 0, right = arr.size() - 1;

    while (left <= right)
    {
        if (arr[left] < 0 && arr[right] < 0)
        {
            // Both are negative, move left pointer
            left++;
        }
        else if (arr[left] >= 0 && arr[right] < 0)
        {
            // Swap left and right
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
        else if (arr[left] >= 0 && arr[right] >= 0)
        {
            // Both are positive, move right pointer
            right--;
        }
        else
        {
            // Left is negative, right is positive - both are in correct positions
            left++;
            right--;
        }
    }
}

int main()
{
    vector<int> arr = {1, 2, -3, 4, -4, -5};

    rearrangeArray(arr);

    cout << "Rearranged array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

// 3. Brute Force
// TC = O(n)
// SC = O(n) -> extra space for temporary array to store results.

// ✅ Idea: Create a new array.
// First, put all negative numbers into it.
// Then, add all positive numbers.
// Copy the result back to the original array if needed.

#include <iostream>
#include <vector>
using namespace std;

void rearrangeArray(vector<int> &arr)
{
    vector<int> temp;

    // Step 1: Add negative numbers first
    for (int num : arr)
    {
        if (num < 0)
            temp.push_back(num);
    }

    // Step 2: Add positive numbers
    for (int num : arr)
    {
        if (num >= 0)
            temp.push_back(num);
    }

    // Step 3: Copy back to original array
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = temp[i];
    }
}

int main()
{
    vector<int> arr = {1, 2, -3, 4, -4, -5};

    rearrangeArray(arr);

    cout << "Rearranged array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

// 4.  Simplest but time complex -> sort

#include <bits/stdc++.h>

// TC = O(nlog(n))
// SC = O(log n)

vector<int> move(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    return arr;
}