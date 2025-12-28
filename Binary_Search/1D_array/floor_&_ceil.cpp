/*Floor and Ceil in Sorted Array

Given a sorted array nums and an integer x. Find the floor and ceil of x in nums. The floor of x is the largest element in the array which is smaller than or equal to x. The ceiling of x is the smallest element in the array greater than or equal to x. If no floor or ceil exists, output -1.
Example 1
Input : nums =[3, 4, 4, 7, 8, 10], x= 5
Output: 4 7
Explanation: The floor of 5 in the array is 4, and the ceiling of 5 in the array is 7.*/

class Solution {
public:
    vector<int> getFloorAndCeil(vector<int> nums, int x) {
        int n = (int)nums.size();
        int floor_val = -1;

        // Find floor: rightmost index with nums[i] <= x
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= x) {
                floor_val = nums[mid];
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        int ceil_val = -1;
        // Find ceil: leftmost index with nums[i] >= x
        low = 0; high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= x) {
                ceil_val = nums[mid];
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return {floor_val, ceil_val};
    }
};