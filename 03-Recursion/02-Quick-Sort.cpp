
// Quick Sort is a divide and conquer sorting algorithm.
// It works by picking a pivot element, then arranging (partitioning) the array so that:

// Elements smaller than pivot go to the left

// Elements greater than pivot go to the right

// Then it recursively sorts the left and right parts.

/*
Choose a pivot (e.g., last element).
Rearrange array → put pivot in its correct place.
Recursively apply the same logic to left and right subarrays.

Array: [10, 7, 8, 9, 1, 5]
Pivot = 5 → Partition → [1] [5] [10, 7, 8, 9]
Then sort left and right parts.
Finally → [1, 5, 7, 8, 9, 10] ✅

*/

// Best Case: O(n log n), SC = O(log n)
// Average Case: O(n log n), SC = O(log n)
// Worst Case: O(n²), SC = O(n)

#include <bits/stdc++.h>
using namespace std;

// Partition function
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high]; // Choosing last element as pivot
    int i = low - 1;       // Index of smaller element

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        { // If current element < pivot
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]); // Place pivot in correct position
    return i + 1;
}

// QuickSort function
void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high); // Partition index

        quickSort(arr, low, pi - 1);  // Sort left side
        quickSort(arr, pi + 1, high); // Sort right side
    }
}

// Driver code
int main()
{
    vector<int> arr = {10, 80, 30, 90, 40, 50, 70};
    int n = arr.size();

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int x : arr)
        cout << x << " ";
    return 0;
}
