/*Set Matrix Zeroes
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0. You must do it in place.
Example 1
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Explanation:
Element at position (1,1) is 0, so set entire row 1 and column 1 to 0.*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int col0 = 1;

        // Mark zeros in first row and column
        for(int i = 0; i < n; i++) {
            if(matrix[i][0] == 0) col0 = 0;
            for(int j = 1; j < m; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Set matrix cells to zero using marks, skipping first row/col
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Handle first row
        if(matrix[0][0] == 0) {
            for(int j = 0; j < m; j++) matrix[0][j] = 0;
        }

        // Handle first column
        if(col0 == 0) {
            for(int i = 0; i < n; i++) matrix[i][0] = 0;
        }
    }
};