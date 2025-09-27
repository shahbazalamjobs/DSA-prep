
// Next greater Elements

// You are given an array of numbers.
// Example: [4, 5, 2, 25]
// For each element in the array, you need to find the next greater element (NGE) on its right.
// The next greater element of an element x is the first element to the right which is greater than x.
// If there is no greater element to the right, put -1 for that element.

// Eg.
// Input: [4, 5, 2, 25]
// Output: [5, 25, 25, -1]

// 1.  Using Stack (Optimized method)
//  TC: O(n)
//  SC: O(n)

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextLargerElement(vector<int> &arr)
{
    int n = arr.size();
    vector<int> res(n, -1);
    stack<int> stk;

    for (int i = n - 1; i >= 0; i--)
    {

        // Pop elements from the stack that are less
        // than or equal to the current element
        while (!stk.empty() && stk.top() <= arr[i])
        {
            stk.pop();
        }

        // If the stack is not empty, the top element
        // is the next greater element
        if (!stk.empty())
        {
            res[i] = stk.top();
        }

        // Push the current element onto the stack
        stk.push(arr[i]);
    }

    return res;
}

int main()
{

    vector<int> arr = {6, 8, 0, 1, 3};
    vector<int> res = nextLargerElement(arr);

    for (int x : res)
    {
        cout << x << " ";
    }

    return 0;
}


// 2. loop
//  TC: O(n^2)
//  SC: O(1)

#include <iostream>
#include <vector>
using namespace std;

vector<int> nextLargerElement(vector<int> &arr) {
    int n = arr.size();
    vector<int> res(n, -1);

    // iterate through each element in the array
    for (int i = 0; i < n; i++) {

        // check for the next greater element
        // in the rest of the array
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                res[i] = arr[j];
                break;
            }
        }
    }

    return res;
}

int main() {

    vector<int> arr = {6, 8, 0, 1, 3};
    vector<int> res = nextLargerElement(arr);
    for (int x : res) {
        cout << x << " ";
    }

    return 0;
}