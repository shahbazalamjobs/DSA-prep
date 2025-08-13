
// 1. Brute Force - Inefficient
// TC: Worst: O((N*M)*(N + M)) + O(N*M)
// sc: O(1) // not using any extra space

#include <iostream>
#include <vector>
using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    // Step 1 & 2: Traverse matrix, mark cells with -1 where needed
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == 0)
            {
                // Mark all non-zero cells in row i with -1
                for (int col = 0; col < cols; col++)
                {
                    if (matrix[i][col] != 0 && matrix[i][col] != -1)
                    {
                        matrix[i][col] = -1;
                    }
                }
                // Mark all non-zero cells in column j with -1
                for (int row = 0; row < rows; row++)
                {
                    if (matrix[row][j] != 0 && matrix[row][j] != -1)
                    {
                        matrix[row][j] = -1;
                    }
                }
            }
        }
    }

    // Step 3: Convert all -1 cells to 0
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = 0;
            }
        }
    }
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 0, 6},
        {7, 8, 9}};

    setZeroes(matrix);

    for (auto &row : matrix)
    {
        for (auto val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}

// 2. Brute Force - Better
// TC: O(2*(N*M))
// SC: O(N) + O(M)
// N = no. of rows in the matrix and M = no. of columns in the matrix.
// Reason: O(N) is for using the row array and O(M) is for using the col array.

// Logic:
// Make two arrays: one for rows and one for columns, all set to 0.
// Go through the matrix. When you find a 0 at (i, j), mark row[i] and col[j] as 1.
// Go through the matrix again. If row[i] or col[j] is 1, set matrix[i][j] to 0.

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m)
{

    int row[n] = {0}; // row array
    int col[m] = {0}; // col array

    // Traverse the matrix:
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                // mark ith index of row wih 1:
                row[i] = 1;

                // mark jth index of col wih 1:
                col[j] = 1;
            }
        }
    }

    // Finally, mark all (i, j) as 0
    // if row[i] or col[j] is marked with 1.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (row[i] || col[j])
            {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans = zeroMatrix(matrix, n, m);

    cout << "The Final matrix is: n";
    for (auto it : ans)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << "n";
    }
    return 0;
}

// 3. Optimal Approach
// SC: O(1) extra space
// TC: O(n × m)

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m)
{

    // int row[n] = {0}; --> matrix[..][0]
    // int col[m] = {0}; --> matrix[0][..]

    int col0 = 1;
    // step 1: Traverse the matrix and
    // mark 1st row & col accordingly:
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                // mark i-th row:
                matrix[i][0] = 0;

                // mark j-th column:
                if (j != 0)
                    matrix[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }

    // Step 2: Mark with 0 from (1,1) to (n-1, m-1):
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] != 0)
            {
                // check for col & row:
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    // step 3: Finally mark the 1st col & then 1st row:
    if (matrix[0][0] == 0)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[0][j] = 0;
        }
    }
    if (col0 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            matrix[i][0] = 0;
        }
    }

    return matrix;
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans = zeroMatrix(matrix, n, m);

    cout << "The Final matrix is: n";
    for (auto it : ans)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << "n";
    }
    return 0;
}
