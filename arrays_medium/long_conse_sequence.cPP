/*Longest Consecutive Sequence in an Array
Given an array nums of n integers.
Return the length of the longest sequence of consecutive integers. The integers in this sequence can appear in any order.
Example 1
Input: nums = [100, 4, 200, 1, 3, 2]
Output: 4
Explanation:
The longest sequence of consecutive elements in the array is [1, 2, 3, 4], which has a length of 4. This sequence can be formed regardless of the initial order of the elements in the array.*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int longest = 1;
        unordered_set <int> st;

        for(int i=0; i<n; i++){
            st.insert(nums[i]);
        }
        for(auto it : st){
            if(st.find(it-1) == st.end()){
                int cnt = 1;
                int x = it;
                while(st.find(x+1) != st.end()){
                    x = x+1;
                    cnt = cnt+1;
                }
                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};