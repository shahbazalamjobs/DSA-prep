
// 1. Print a given matrix in spiral form



#include <iostream>
#include <vector>
using namespace std;

vector<int> spirallyTraverse(vector<vector<int>> &mat)
{
    int m = mat.size();
    int n = mat[0].size();

    vector<int> res;

    // Initialize boundaries
    int top = 0, bottom = m - 1, left = 0, right = n - 1;

    // Iterate until all elements are stored
    while (top <= bottom && left <= right)
    {

        // store top row from left to right
        for (int i = left; i <= right; ++i)
        {
            res.push_back(mat[top][i]);
        }
        top++;

        // store right column from top to bottom
        for (int i = top; i <= bottom; ++i)
        {
            res.push_back(mat[i][right]);
        }
        right--;

        // store bottom row from right to left (if exists)
        if (top <= bottom)
        {
            for (int i = right; i >= left; --i)
            {
                res.push_back(mat[bottom][i]);
            }
            bottom--;
        }

        // store left column from bottom to top (if exists)
        if (left <= right)
        {
            for (int i = bottom; i >= top; --i)
            {
                res.push_back(mat[i][left]);
            }
            left++;
        }
    }
    return res;
}

int main()
{

    vector<vector<int>> mat = {{1, 2, 3, 4},
                               {5, 6, 7, 8},
                               {9, 10, 11, 12},
                               {13, 14, 15, 16}};

    vector<int> res = spirallyTraverse(mat);
    for (int ele : res)
        cout << ele << " ";
    return 0;
}