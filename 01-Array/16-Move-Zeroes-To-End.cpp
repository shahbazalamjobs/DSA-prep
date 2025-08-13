

// 1. optimized

// tc: O(N)
// sc: o(1)

#include <iostream>
#include <vector>

using namespace std;

void moveZerosToEnd(vector<int> &nums)
{
    int insertPos = 0;

    // Move non-zero elements to the front
    for (int num : nums)
    {
        if (num != 0)
        {
            nums[insertPos++] = num;
        }
    }

    // Fill remaining positions with zeros
    while (insertPos < nums.size())
    {
        nums[insertPos++] = 0;
    }
}

int main()
{
    vector<int> nums = {0, 1, 0, 3, 12};

    moveZerosToEnd(nums);

    cout << "After moving zeros to the end: ";
    for (int num : nums)
    {
        cout << num << " ";
    }

    return 0;
}

// 2.  Brute force

// tc: O(N)
// sc: o(N) extra space used for temp vector

#include <iostream>
#include <vector>
using namespace std;

void moveZerosBruteForce(vector<int> &nums)
{
    int n = nums.size();
    vector<int> temp;

    // Step 1: Collect all non-zero elements
    for (int num : nums)
    {
        if (num != 0)
        {
            temp.push_back(num);
        }
    }

    // Step 2: Add zeros to the end
    while (temp.size() < n)
    {
        temp.push_back(0);
    }

    // Step 3: Copy back to original array
    for (int i = 0; i < n; ++i)
    {
        nums[i] = temp[i];
    }
}

int main()
{
    vector<int> nums = {2, 1, 0, 3, 5, 1, 0, 12};

    moveZerosBruteForce(nums);

    cout << "After brute force: ";
    for (int num : nums)
    {
        cout << num << " ";
    }

    return 0;
}
