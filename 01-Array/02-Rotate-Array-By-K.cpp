
// 1. Rotate Array by k right reversal algorithm

// Time Complexity	O(n)
// Space Complexity O(1)

#include <iostream>
#include <vector>
using namespace std;

// Reverse a subarray from index start to end
void reverse(vector<int> &arr, int start, int end)
{
    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void rotateArray(vector<int> &arr, int k)
{
    int n = arr.size();
    k = k % n; // In case k > n

    // Step 1: Reverse the whole array
    reverse(arr, 0, n - 1);

    // Step 2: Reverse first k elements
    reverse(arr, 0, k - 1);

    // Step 3: Reverse remaining elements
    reverse(arr, k, n - 1);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    rotateArray(arr, k);

    cout << "Rotated array: ";
    for (int val : arr)
        cout << val << " ";
    cout << endl;

    return 0;
}

// 2. Rotate Array by k left using array

#include <iostream>
using namespace std;

void reverse(int arr[], int start, int end)
{
    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void rotateArrayLeft(int arr[], int n, int k)
{
    k = k % n; // In case k > n
    reverse(arr, 0, k - 1);
    reverse(arr, k, n - 1);
    reverse(arr, 0, n - 1);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    rotateArrayLeft(arr, n, k);

    cout << "Left Rotated array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

// 2. rotata array by k right using temporary array

// Time Complexity: O(n)
// Space Complexity: O(k) since k array element needs to be stored in temp array

#include <iostream>
using namespace std;
void Rotatetoright(int arr[], int n, int k)
{
    if (n == 0)
        return;
    k = k % n;
    if (k > n)
        return;
    int temp[k];
    for (int i = n - k; i < n; i++)
    {
        temp[i - n + k] = arr[i];
    }
    for (int i = n - k - 1; i >= 0; i--)
    {
        arr[i + k] = arr[i];
    }
    for (int i = 0; i < k; i++)
    {
        arr[i] = temp[i];
    }
}
int main()
{
    int n = 7;
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int k = 2;
    Rotatetoright(arr, n, k);
    cout << "After Rotating the elements to right " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
