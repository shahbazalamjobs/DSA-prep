

// 1. Best: using total Sum
// Time: O(n)
// Space: O(1) (no extra space used except variables)

#include <iostream>
#include <vector>
using namespace std;

int findEquilibriumIndex(const vector<int> &arr)
{
    int totalSum = 0;
    for (int num : arr)
    {
        totalSum += num;
    }

    int leftSum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int rightSum = totalSum - leftSum - arr[i];

        if (leftSum == rightSum)
        {
            return i;
        }

        leftSum += arr[i];
    }

    return -1;
}

int main()
{
    vector<int> arr = {-7, 1, 5, 2, -4, 3, 0};
    int index = findEquilibriumIndex(arr);

    if (index != -1)
        cout << "Equilibrium Index: " << index << endl;
    else
        cout << "No Equilibrium Index found." << endl;

    return 0;
}

// 1.2 Same Like above but little difference

#include <iostream>

using namespace std;
int findEquilibriumIdx(int nums[], int n)
{
    int totalSum = 0;
    for (int i = 0; i < n; i++)
    {
        totalSum += nums[i];
    }
    int leftSum = 0, rightSum = totalSum;
    for (int i = 0; i < n; i++)
    {
        rightSum -= nums[i];
        if (leftSum == rightSum)
        {
            return i;
        }
        leftSum += nums[i];
    }
    return -1;
}
int main()
{
    int n = 5;
    int arr[] = {2, 3, -1, 8, 4};
    int equilibriumidx = findEquilibriumIdx(arr, n);
    cout << equilibriumidx << endl;
    return 0;
}

// 2. 2 Loops (Brute Force)
// Time Complexity: O(N^2)
// Space Complexity: O(1)

#include <iostream>
using namespace std;
int findEquilibriumIdx(int nums[], int n)
{
    int leftSum, rightSum;

    for (int i = 0; i < n; i++)
    {
        leftSum = 0;
        for (int j = 0; j < i; j++)
        {
            leftSum += nums[j];
        }
        rightSum = 0;
        for (int j = i + 1; j < n; j++)
        {
            rightSum += nums[j];
        }
        if (leftSum == rightSum)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int n = 5;
    int arr[] = {2, 3, -1, 8, 4};
    int equilibriumidx = findEquilibriumIdx(arr, n);
    cout << equilibriumidx << endl;
    return 0;
}