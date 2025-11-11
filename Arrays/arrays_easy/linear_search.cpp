/*Linear Search
Given an array of integers nums and an integer target, find the smallest index (0 based indexing) where the target appears in the array. If the target is not found in the array, return -1.
Examples:
Input: nums = [2, 3, 4, 5, 3], target = 3
Output: 1
Explanation
The first occurence of 3 in nums is at index 1*/

class Solution {
public:
    int linearSearch(vector<int>& nums, int target) {
        //your code goes here
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == target)
            return i;
        }
        return -1;
    }
};