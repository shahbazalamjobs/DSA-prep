
// "In-place rotate matrix 90 degrees" means:

// You’re given an N×N square matrix, and you need to rotate it 90°
// clockwise without using extra space for another matrix (so, modify the same matrix).

/*

Example: Original matrix:

1  2  3
4  5  6
7  8  9

90° clockwise rotation:

7  4  1
8  5  2
9  6  3

*/

/*

// Simple Logic

1. Transpose the matrix → swap rows and columns.

1 4 7
2 5 8
3 6 9

2. Reverse each row → gives the rotated matrix.

7 4 1
8 5 2
9 6 3

*/

// 1. Brute Force

// TC: O(n^2)
// SC: O(n^2)

// Approach: Take another dummy matrix of n*n,
// We mainly need to move first row elements to first column in reverse order,
// second row elements to second column in reverse order and so on.

/*

Let us first try to find out a pattern to solve the problem for n = 4 (second example matrix above)

mat[0][0] goes to mat[3][0]
mat[0][1] goes to mat[2][0]
mat[1][0] goes to mat[3][1]
mat[3][3] goes to mat[0][3]

Do you see a pattern? Mainly we need to move mat[i][j] to mat[n-j-1][i].
We first move elements in a temporary matrix, then copy the temporary to the original.
If we directly copy elements within the matrix, it would cause data loss.

*/

// TC: O(n^2)
// SC: O(n^2)

#include <iostream>
#include <vector>
using namespace std;

void rotateMatrix(vector<vector<int>> &mat)
{
    int n = mat.size();
    vector<vector<int>> res(n, vector<int>(n));

    // Rotate the matrix 90 degrees counterclockwise
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            res[n - j - 1][i] = mat[i][j];
        }
    }

    // Copy the rotated matrix back
    // to the original matrix
    mat = res;
}

int main()
{
    vector<vector<int>> mat = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};

    rotateMatrix(mat);

    for (auto &row : mat)
    {
        for (int x : row)
        {
            cout << x << ' ';
        }
        cout << endl;
    }

    return 0;
}

// 1. Approach 2 - Better SC

// Reversing Rows and Transposing

// Reverse every individual row of the matrix
// Perform Transpose of the matrix

// Rotation Types
// Clockwise 90° Rotation: Transpose the matrix, then reverse each row.
// Counterclockwise 90° Rotation: Reverse each row, then transpose the matrix.

// TC: O(n2)
// SC: O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotateMatrix(vector<vector<int>> &mat)
{
    int n = mat.size();

    // Reverse each row
    for (int i = 0; i < n; i++)
        reverse(mat[i].begin(), mat[i].end());

    // Performing Transpose
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
            swap(mat[i][j], mat[j][i]);
    }
}

int main()
{
    vector<vector<int>> mat = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};
    rotateMatrix(mat);
    for (auto &row : mat)
    {
        for (int x : row)
        {
            cout << x << ' ';
        }
        cout << endl;
    }

    return 0;
}