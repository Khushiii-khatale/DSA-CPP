/*Find out how many times the array is rotated

Given an integer array nums of size n, sorted in ascending order with distinct values. The array has been right rotated an unknown number of times, between 0 and n-1 (including). Determine the number of rotations performed on the array.
Example 1
Input : nums = [4, 5, 6, 7, 0, 1, 2, 3]
Output: 4
Explanation: The original array should be [0, 1, 2, 3, 4, 5, 6, 7]. So, we can notice that the array has been rotated 4 times.*/

class Solution {
public:
    int findKRotation(vector<int> &nums)  {
        int ans  = INT_MAX;
        int low = 0;
        int high = nums.size()-1;
        int index = -1;

        while(low <= high){
            int mid = (low+high)/2;

            if(nums[low] <= nums[high]){
                if(nums[low] <= ans){
                    index = low;
                    ans = nums[low];
                }
                break;
            }
            if(nums[low] <= nums[mid]){
                if(nums[low] < ans){
                    index = low;
                    ans = nums[low];
                }
                low = mid + 1;
            }
            else{
                high = mid -1;
                if(nums[mid] <= nums[high]){
                    index = mid;
                    ans = nums[mid];
                }
            }
        }
        return index;
    }
};