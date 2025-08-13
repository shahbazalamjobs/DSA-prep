
// You have an already-sorted array that got “cut and pasted” once (rotated).
// Quickly find the position of a given number k; return -1 if it isn’t there.

// Logic: Because the array was originally sorted, one half of any sub-array is always sorted.
// Use that fact inside a binary search to decide which half to keep checking.
// Halve the search range each step ⇒ O(log n) time, O(1) space.

// 1.  Search in Rotated Sorted Array (BInary Search) -> Optimzed

// TC = O(log n)
// SC = O(1)

#include <iostream>
#include <vector>
using namespace std;

// Function to search in a rotated sorted array
int searchInRotatedSortedArray(const vector<int> &arr, int k)
{
    int low = 0, high = arr.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == k)
            return mid;

        // Check if left part is sorted
        if (arr[low] <= arr[mid])
        {
            if (arr[low] <= k && k < arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        // Right part is sorted
        else
        {
            if (arr[mid] < k && k <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }

    return -1; // Not found
}

// Main function to test the implementation
int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int k = 0;

    int index = searchInRotatedSortedArray(arr, k);

    if (index != -1)
        cout << "Element " << k << " found at index: " << index << endl;
    else
        cout << "Element " << k << " not found in the array." << endl;

    return 0;
}

// 2. Brute Force (linear scan)
// TC = O(n)
// SC = O(1)

// Brute-force function to search for k
int searchBruteForce(const vector<int> &arr, int k)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == k)
            return i; // Found at index i
    }
    return -1; // Not found
}
