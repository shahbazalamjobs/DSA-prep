
// Divide → Split the array into two halves again and again until each part has only 1 element.

// Conquer → Merge the small sorted parts back together in order (like merging two sorted lists).

// Result → At the end, everything is merged into one big sorted array.
/**/
/*

Example: [38, 27, 43, 3]
Split → [38, 27] & [43, 3] → [38] [27] & [43] [3]
Merge → [27, 38] & [3, 43]
Merge again → [3, 27, 38, 43] ✅

⚡ Time Complexity: O(n log n)
⚡ Space Complexity: O(n)



Time complexity fromula:

🔹 Merge Sort Process

Divide step
Each time, the array is split into 2 halves.
This splitting continues until we get subarrays of size 1.
That means we can split at most log₂n times.
So the height of recursion tree = log n.

Merge step
At each level, we merge all elements.
Merging two sorted arrays of total size n takes O(n) time.
And there are log n levels of merging.

🔹 Formula

So total time complexity =
(work per level) × (number of levels)
= O(n) × O(log n)
= O(n log n)

*/

// 1.
// TC: O(nlogn)
// SC: O(n)+O(logn)≈O(n)

#include <bits/stdc++.h>
using namespace std;

// Function to merge two halves
void merge(vector<int> &arr, int left, int mid, int right)
{
    // Sizes of two subarrays
    int n1 = mid - left + 1; // O(1)
    int n2 = right - mid;    // O(1)

    // Temp arrays
    vector<int> L(n1), R(n2); // O(n1 + n2) ~ O(n)

    // Copy data
    for (int i = 0; i < n1; i++) // O(n1)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) // O(n2)
        R[j] = arr[mid + 1 + j];

    // Merge temp arrays back
    int i = 0, j = 0, k = left; // O(1)
    while (i < n1 && j < n2)
    { // O(n1 + n2) ~ O(n)
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    // Copy remaining elements
    while (i < n1)
        arr[k++] = L[i++]; // O(n1)
    while (j < n2)
        arr[k++] = R[j++]; // O(n2)
    // ✅ Overall merge() = O(n)
}

// Recursive merge sort
void mergeSort(vector<int> &arr, int left, int right)
{
    if (left >= right)
        return; // O(1) base case

    int mid = left + (right - left) / 2; // O(1)
    mergeSort(arr, left, mid);           // T(n/2)  // sort left half
    mergeSort(arr, mid + 1, right);      // T(n/2)  // sort right half
    merge(arr, left, mid, right);        // O(n)    // merge sorted halves }
    // ✅ Overall recurrence: T(n) = 2T(n/2) + O(n) → O(n log n)
}

int main()
{
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    cout << "Original array: ";
    for (int x : arr)
        cout << x << " "; // O(n)
    cout << endl;

    mergeSort(arr, 0, arr.size() - 1); // O(n log n)

    cout << "Sorted array:   ";
    for (int x : arr)
        cout << x << " "; // O(n)
    cout << endl;

    return 0;
}

// ✅ Final Overall Time Complexity = O(n log n)
// ✅ merge() per call = O(n)
// ✅ mergeSort() recursive tree depth = log n
