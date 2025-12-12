/*53. Maximum Subarray
Given an integer array nums, find the subarray with the largest sum, and return its sum.
Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:
Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long sum = 0, maxi = LONG_MIN;

        for(int i=0; i<nums.size(); i++){
            sum = sum +nums[i];

            if(sum > maxi){
                maxi = sum;
            }
            if(sum < 0){
                sum = 0;
            }
        }
        return maxi;
    }
};