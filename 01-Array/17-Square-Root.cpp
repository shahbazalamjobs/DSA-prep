
// 1. Using Binary Search
// tc: O(logN)
// sc: o(1)

#include <iostream>
using namespace std;

int sqrtFloor(int n)
{
    if (n == 0 || n == 1)
        return n;

    int low = 1, high = n, ans = 0;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // To prevent overflow use long long for square
        long long square = 1LL * mid * mid;

        if (square == n)
            return mid;
        else if (square < n)
        {
            ans = mid;     // Update answer
            low = mid + 1; // Try to find a higher value
        }
        else
        {
            high = mid - 1;
        }
    }

    return ans;
}

int main()
{
    int n = 7;
    cout << "Floor square root of " << n << " is: " << sqrtFloor(n) << endl;
    return 0;
}

// 2. Brute Force
// tc: O(√n) (since loop runs until i*i > n)
// sc: o(1)


#include <iostream>
using namespace std;

int sqrtFloorBrute(int n)
{
    if (n == 0 || n == 1)
        return n;

    int ans = 1;
    for (int i = 1; i <= n / 2; ++i)
    {
        if (1LL * i * i == n)
        {
            return i; // perfect square
        }
        if (1LL * i * i > n)
        {
            return i - 1; // floor of sqrt
        }
    }

    return ans;
}

int main()
{
    int n = 7;
    cout << "Floor square root of " << n << " is: " << sqrtFloorBrute(n) << endl;
    return 0;
}

