/*Largest Subarray with Sum 0
You are given an integer array arr of size n which contains both positive and negative integers. Your task is to find the length of the longest contiguous subarray with sum equal to 0.
Return the length of such a subarray. If no such subarray exists, return 0.
Example 1
Input: arr = [15, -2, 2, -8, 1, 7, 10, 23]
Output: 5
Explanation:
The subarray [-2, 2, -8, 1, 7] sums up to 0 and has the maximum length among all such subarrays.*/

class Solution {
  public:
    int maxLen(vector<int>& arr) {
        // Your code goes here
        unordered_map<int, int> mpp;
        int maxi = 0;
        int sum = 0;
        for(int i=0; i<arr.size(); i++){
          sum += arr[i];
          if(sum == 0){
            maxi = i+1;
          }
          else{
            if(mpp.find(sum) != mpp.end()){
              maxi = max(maxi, i-mpp[sum]);
            }
            else{
              mpp[sum] = i;
            }
          }
        }
        return maxi;
    }
};