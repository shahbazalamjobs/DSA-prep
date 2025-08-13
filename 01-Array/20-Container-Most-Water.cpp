
// You're given an array height, where each element represents the height of a
// vertical line at a specific position on the x-axis. For example, for height = [1, 4, 2, 3], these lines are at positions:

// Line 0: height 1
// Line 1: height 4
// Line 2: height 2
// Line 3: height 3

// You need to find two lines that form a container with the x-axis that can hold the most water.

// Think of these lines as the sides of a bucket, and the water is stored between them.

// 🧠 How is Water Stored?
// Between two lines:
// The height of the water is the shorter of the two lines.
// The width is the distance between the two lines.

// So, for two lines at index i and j, the area (amount of water) =
// min(height[i], height[j]) * (j - i)

// Your goal: find such i and j that this value is maximum.

// Example
// Input: height = [1, 4, 2, 3]
// Check all pairs:

// Between 0 and 1: min(1,4) * (1-0) = 1
// Between 0 and 2: min(1,2) * (2-0) = 1 * 2 = 2
// Between 0 and 3: min(1,3) * (3-0) = 1 * 3 = 3
// Between 1 and 3: min(4,3) * (3-1) = 3 * 2 = 6 ✅ max
// etc...

// 1. 2 Pointer
// 💡 Optimal Strategy (Two Pointers):
// Start with two pointers: one at start, one at end.

// Calculate area.
// Move the pointer that has the smaller height (because it’s the limiting factor).
// Keep updating the max area.

// TC: O(n)
// SC: O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxArea(vector<int> &height)
{
    int left = 0;                  // Start pointer
    int right = height.size() - 1; // End pointer
    int maxWater = 0;

    while (left < right)
    {
        int h = min(height[left], height[right]); // Shorter wall
        int w = right - left;                     // Distance between walls
        int area = h * w;                         // Water area
        maxWater = max(maxWater, area);           // Update max area

        // Move the smaller wall inward
        if (height[left] < height[right])
            left++;
        else
            right--;
    }

    return maxWater;
}

int main()
{
    vector<int> height = {1, 4, 2, 3};
    cout << "Max water that can be stored: " << maxArea(height) << endl;
    return 0;
}

// 2.  Brute Force

// TC: O(n²)
// SC: O(1)

int maxArea(vector<int> &height)
{
    int n = height.size();
    int maxWater = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int h = min(height[i], height[j]);
            int w = j - i;
            int area = h * w;
            maxWater = max(maxWater, area);
        }
    }

    return maxWater;
}