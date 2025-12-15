/*Print the matrix in spiral manner
Given an M * N matrix, print the elements in a clockwise spiral manner.
Return an array with the elements in the order of their appearance when printed in a spiral manner.
Example 1
Input: matrix = [[1, 2, 3], [4 ,5 ,6], [7, 8, 9]]
Output: [1, 2, 3, 6, 9, 8, 7, 4, 5]
Explanation:
The elements in the spiral order are 1, 2, 3 -> 6, 9 -> 8, 7 -> 4, 5*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int left = 0, right = m-1;
        int top = 0, bottom = n-1;
        vector <int> ans;

        while(top <= bottom && left <= right){
            for(int i=left; i<= right; i++){
                ans.push_back(matrix[top][i]);
            }
            top++;
            for(int i=top; i<= bottom; i++){
                ans.push_back(matrix[i][right]);
            }
            right--;
            if(left <= right){
                for(int i=right; i >= left; i--){
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if(top <= bottom){
                for(int i=bottom; i>= top; i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};