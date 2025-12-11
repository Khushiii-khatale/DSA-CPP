/*
Longest subarray with sum k
Given an array nums of size n and an integer k, find the length of the longest sub-array that sums to k. If no such sub-array exists, return 0.
Examples:
Input: nums = [10, 5, 2, 7, 1, 9],  k=15
Output: 4
Explanation:
The longest sub-array with a sum equal to 15 is [5, 2, 7, 1], which has a length of 4. This sub-array starts at index 1 and ends at index 4, and the sum of its elements (5 + 2 + 7 + 1) equals 15. Therefore, the length of this sub-array is 4.*/

class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        unordered_map<int, int> prefixIndex;
        int prefixSum = 0, maxLen = 0;
        for (int i = 0; i < nums.size(); ++i) {
            prefixSum += nums[i];
            if (prefixSum == k) {
                maxLen = i + 1;
            }
            if (prefixIndex.find(prefixSum - k) != prefixIndex.end()) {
                maxLen = max(maxLen, i - prefixIndex[prefixSum - k]);
            }
            // Store only the first occurrence for longest length
            if (prefixIndex.find(prefixSum) == prefixIndex.end()) {
                prefixIndex[prefixSum] = i;
            }
        }
        return maxLen;
    }
};