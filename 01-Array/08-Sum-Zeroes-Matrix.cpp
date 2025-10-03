/*

You are given a 2D grid of 0s and 1s.
For each 0, count how many 1s are directly adjacent (top, bottom, left, right).
The total of these counts is the coverage.


E.g.

Matrix:
1 0 1
0 1 0
1 0 1

Now check each 0:

At (0,1): Neighbors → left=1, right=1 → contributes 2
At (1,0): Neighbor → down=1 → contributes 1
At (1,2): Neighbor → down=1 → contributes 1
At (2,1): Neighbors → left=1, right=1 → contributes 2
👉 Total coverage = 2 + 1 + 1 + 2 = 6

*/

// 1. Sum Zeroes of a vector 

// Time O(n²)
// SC O(1) 


#include <bits/stdc++.h> 
int coverageOfMatrix(vector<vector<int>> &mat) {
    // Write your code here.

    int row = mat.size();
    if(row==0) return 0;

    int col = mat[0].size();

    int i, j, coverage = 0;

    for(int i=0; i< row; i++) {
        for(int j=0; j<col; j++) {
           if(mat[i][j] == 0) {
            if(i>0 && mat[i-1][j] == 1) {
                coverage++;
            }

            if(i< row-1 && mat[i+1][j] == 1) {
                coverage++;
            }

            if(j>0 && mat[i][j-1] == 1) {
                coverage++;
            }

            if(j< col-1 && mat[i][j+1] == 1) {
                coverage++;
            }
           }
        }
    }

    return coverage;
}

