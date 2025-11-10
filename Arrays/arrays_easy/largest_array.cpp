/*Largest Element
Given an array of integers nums, return the value of the largest element in the array
Examples:
Input: nums = [3, 3, 6, 1]
Output: 6
Explanation: The largest element in array is 6
Input: nums = [3, 3, 0, 99, -40]
Output: 99
Explanation: The largest element in array is 99*/

class Solution {
public:
    int largestElement(vector<int>& nums) {
        int largest = nums[0];
        for(int i=1; i < nums.size(); i++){
            if(nums[i] > largest)
            largest = nums[i];
        }
        return largest;
    }
};