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

Step 1: Check each 0 and count adjacent 1s

(0,1) → 0 : Neighbors: left=1, right=1, down=1 → 3
(1,0) → 0 : Neighbors: up=1, right=1, down=1 → 3
(1,2) → 0 : Neighbors: up=1, left=1, down=1 → 3
(2,1) → 0 : Neighbors: left=1, right=1, up=1 → 3

👉 Total coverage = 3 + 3 + 3 + 3 = 12

*/

// 1. Sum Zeroes of a vector 

// Time O(n²)
// SC O(1) 


#include <bits/stdc++.h> 
using namespace std;

int coverageOfMatrix(vector<vector<int>> &mat) {
    // Write your code here.

    int row = mat.size();
    if(row==0) return 0;

    int col = mat[0].size();

    int coverage = 0;

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



