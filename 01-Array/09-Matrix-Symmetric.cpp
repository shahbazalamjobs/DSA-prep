// 1. Simple

// Time O(n²)
// SC O(1) as passed by reference (&matrix) other wise is passed by value then O(n) matrix

#include <bits/stdc++.h>
using namespace std;

// Function to check if a matrix is symmetric
bool isMatrixSymmetric(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();

    // Matrix must be square to be symmetric
    if (row != col)
        return false;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] != matrix[j][i])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int n;
    cout << "Enter size of square matrix (n x n): ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> matrix[i][j];
        }
    }

    if (isMatrixSymmetric(matrix))
    {
        cout << "The matrix is symmetric.\n";
    }
    else
    {
        cout << "The matrix is not symmetric.\n";
    }

    return 0;
}

// 1. More optimized

// Time O(n(n-1)/2)
// SC O(1)

/*

Logic

In a square matrix, there are three parts:

The diagonal (where i == j) — always symmetric to itself.

The upper triangle (where j > i)

The lower triangle (where i > j)

To check if the matrix is symmetric, we only need to compare:

Upper triangle values with their corresponding lower triangle values.


for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j)

*/

/*


matrix = 

1 2 3
2 4 5
3 5 8


Check these positions only:

matrix[0][1] vs matrix[1][0] → 2 vs 2 ✅

matrix[0][2] vs matrix[2][0] → 3 vs 3 ✅

matrix[1][2] vs matrix[2][1] → 5 vs 5 ✅

*/


bool isMatrixSymmetric(const vector<vector<int>> &matrix)
{
    int n = matrix.size();

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (matrix[i][j] != matrix[j][i])
            {
                return false;
            }
        }
    }
    return true;
}
