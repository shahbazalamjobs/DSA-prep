#include <iostream>
using namespace std;

bool checkPossibility(int nums[], int n)
{
    int count = 0;

    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i] > nums[i + 1])
        {
            count++;

            if (count > 1)
                return false;

            if (i == 0 || nums[i - 1] <= nums[i + 1])
            {
                nums[i] = nums[i + 1];
            }
            else
            {
                nums[i + 1] = nums[i];
            }
        }
    }

    return true;
}

int main()
{
    int nums[] = {4, 2, 3};
    int n = sizeof(nums) / sizeof(nums[0]);

    if (checkPossibility(nums, n))
    {
        cout << "True: Can be made non-decreasing with at most one change.\n";
    }
    else
    {
        cout << "False: Cannot be made non-decreasing with just one change.\n";
    }

    return 0;
}
