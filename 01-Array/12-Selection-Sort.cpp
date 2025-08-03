

// 1. Selection Sort

// 🔹 Worst Case: O(n²)
// Why? Because for every element, you scan the remaining ones to find the minimum.
// Total comparisons = (n-1) + (n-2) + ... + 1 = n(n-1)/2 ≈ O(n²)
// 🔹 Best Case: O(n²)
// Even if the array is already sorted, it still does all the comparisons.
// So best case is still O(n²).
// 🔹 Average Case: O(n²)
// Same logic — no improvement due to data arrangement.
// 💾 Space Complexity
// 🔹 Space: O(1)

#include <iostream>
using namespace std;

void selectionSort(int arr[], int n)
{
    // Outer loop to move the boundary of the unsorted part
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i; // Assume the first element is the minimum

        // Inner loop to find the actual minimum in the rest of the array
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j; // Found a new minimum
            }
        }

        // Swap the found minimum with the first element
        if (minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
