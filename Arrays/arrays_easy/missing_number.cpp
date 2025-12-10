/*Find missing number
Given an integer array of size n containing distinct values in the range from 0 to n (inclusive), return the only number missing from the array within this range.
Examples:
Input: nums = [0, 2, 3, 1, 4]
Output: 5
Explanation:
nums contains 0, 1, 2, 3, 4 thus leaving 5 as the only missing number in the range [0, 5]
Input: nums = [0, 1, 2, 4, 5, 6]
Output: 3
Explanation:
nums contains 0, 1, 2, 4, 5, 6 thus leaving 3 as the only missing number in the range [0, 6]*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xor1 = 0;
        int xor2 = 0;
         for(int i = 0; i <= n; i++){
            xor1 = xor1 ^ i;
         }
         for(int num : nums){
            xor2 = xor2 ^ num;
         }
         return xor1 ^ xor2;
    }
};