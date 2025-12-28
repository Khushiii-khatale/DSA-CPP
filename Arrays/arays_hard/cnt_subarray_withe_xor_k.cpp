/*Count subarrays with given xor K
Given an array of integers nums and an integer k, return the total number of subarrays whose XOR equals to k.
Example 1
Input : nums = [4, 2, 2, 6, 4], k = 6
Output : 4
Explanation : The subarrays having XOR of their elements as 6 are [4, 2],  [4, 2, 2, 6, 4], [2, 2, 6], and [6]*/

class Solution{
public:
    int subarraysWithXorK(vector<int> &nums, int k) {
        int xr = 0;
        map<int, int> mpp;
        mpp[xr]++; //{0,1}
        int cnt = 0;

        for(int i=0; i<nums.size(); i++){
            xr = xr ^ nums[i];
            int x = xr ^ k;
            cnt += mpp[x];
            mpp[xr]++;
        }
        return cnt;
    }
};