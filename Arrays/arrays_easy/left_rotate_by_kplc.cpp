/*Left Rotate Array by K Place
Given an integer array nums and a non-negative integer k, rotate the array to the left by k steps.
Examples:
Input: nums = [1, 2, 3, 4, 5, 6], k = 2
Output: nums = [3, 4, 5, 6, 1, 2]
Explanation:
rotate 1 step to the left: [2, 3, 4, 5, 6, 1]
rotate 2 steps to the left: [3, 4, 5, 6, 1, 2]*/

class Solution {
public:
    void rotateArray(vector<int>& nums, int k) {
        k = k % nums.size();
        vector<int> temp(k);
        for(int i=0; i<k; i++){
            temp[i] = nums[i];
        }
        for(int i=k; i<nums.size(); i++){
            nums[i-k] = nums[i];
        }
        for(int i= nums.size()-k; i<nums.size(); i++){
            nums[i] = temp[i-(nums.size()-k)];
        }
    }
};