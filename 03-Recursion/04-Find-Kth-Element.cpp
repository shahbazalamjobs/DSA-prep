
// Problem: Find K-th Element
// You are given two sorted arrays (say arr1 and arr2) and a number K.
// Your task is to find the K-th smallest element when both arrays are combined into one sorted array.

// Combine two sorted arrays (virtually, without actually merging if possible).
// Return the K-th smallest element.

/*

arr1 = [2, 3, 6, 7, 9]
arr2 = [1, 4, 8, 10]
K = 5

Merged Sorted Array:
[1, 2, 3, 4, 6, 7, 8, 9, 10]


The 5th element is 6 ✅

*/

// 1. Naive Approach (Brute-force)
// TC: O(m+n)
// SC: O(m+n) // using an extra array of size (m+n)

#include <bits/stdc++.h>
using namespace std;

int kthElement(vector<int> &a, vector<int> &b, int k)
{
    vector<int> arr3;

    int i = 0, j = 0;
    int m = a.size(), n = b.size();

    // merge step
    while (i < m && j < n)
    {
        if (a[i] < b[j])
            arr3.push_back(a[i++]);
        else
            arr3.push_back(b[j++]);
    }

    // remaining elements
    while (i < m)
        arr3.push_back(a[i++]);
    while (j < n)
        arr3.push_back(b[j++]);

    return arr3[k - 1]; // k-th element (1-based index)
}

int main()
{
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    int k = 5;

    cout << "The " << k << "-th element of two sorted arrays is: "
         << kthElement(a, b, k) << '\n';
}

// 2. Better Approach (Optimized space)
// Instead of merging the whole array, we just keep track
// of elements picked until we reach the k-th one.

// TC: O(k)
// SC=: O(1)

#include <bits/stdc++.h>
using namespace std;

int kthElement(vector<int> &a, vector<int> &b, int k)
{
    int i = 0, j = 0, cnt = 0;
    int m = a.size(), n = b.size();

    while (i < m && j < n)
    {
        int val;
        if (a[i] < b[j])
        {
            val = a[i++];
        }
        else
        {
            val = b[j++];
        }
        cnt++;
        if (cnt == k)
            return val;
    }

    // If elements are left in a[]
    while (i < m)
    {
        cnt++;
        if (cnt == k)
            return a[i];
        i++;
    }

    // If elements are left in b[]
    while (j < n)
    {
        cnt++;
        if (cnt == k)
            return b[j];
        j++;
    }

    return -1; // if k is invalid
}

int main()
{
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    int k = 5;

    cout << "The " << k << "-th element is: " << kthElement(a, b, k) << '\n';
}

// 3. Optimal Approach (Using Binary Search)
// TC: O(log(min(n1, n2)))
SC: 

#include <bits/stdc++.h>
using namespace std;

int findKthElement(vector<int> &arr1, vector<int> &arr2, int k)
{
    int n1 = arr1.size();
    int n2 = arr2.size();

    // Always apply binary search on smaller array
    if (n1 > n2)
        return findKthElement(arr2, arr1, k);

    int low = max(0, k - n2); // minimum from arr1
    int high = min(k, n1);    // maximum from arr1

    while (low <= high)
    {
        int cut1 = (low + high) / 2; // elements from arr1
        int cut2 = k - cut1;         // elements from arr2

        // l1, l2 = last elements of left half
        // r1, r2 = first elements of right half
        int l1 = (cut1 == 0) ? INT_MIN : arr1[cut1 - 1];
        int l2 = (cut2 == 0) ? INT_MIN : arr2[cut2 - 1];
        int r1 = (cut1 == n1) ? INT_MAX : arr1[cut1];
        int r2 = (cut2 == n2) ? INT_MAX : arr2[cut2];

        // ✅ Valid partition
        if (l1 <= r2 && l2 <= r1)
        {
            return max(l1, l2); // kth element is max of left side
        }
        // Too many from arr1 → move left
        else if (l1 > r2)
        {
            high = cut1 - 1;
        }
        // Too few from arr1 → move right
        else
        {
            low = cut1 + 1;
        }
    }
    return -1; // should not happen
}

int main()
{
    vector<int> arr1 = {2, 3, 6, 7, 9};
    vector<int> arr2 = {1, 4, 8, 10};
    int k = 5;

    cout << "K-th element is: " << findKthElement(arr1, arr2, k) << endl;
    return 0;
}
