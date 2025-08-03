
// 1. Bubble Sort

// TC:
// Best: O(n) (when already sorted with an optimized version using a swapped flag)
// Average/Worst: O(n^2)
// Space Complexity: O(1)

#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    // Outer loop for all passes
    for (int i = 0; i < n - 1; ++i)
    {
        // Inner loop for comparing adjacent elements
        for (int j = 0; j < n - i - 1; ++j)
        {
            // Swap if elements are in the wrong order
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;

    bubbleSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
