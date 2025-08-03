
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
