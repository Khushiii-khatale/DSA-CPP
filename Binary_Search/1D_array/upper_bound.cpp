/*Upper Bound

Given a sorted array of nums and an integer x, write a program to find the upper bound of x.
The upper bound of x is defined as the smallest index i such that nums[i] > x.
If no such index is found, return the size of the array.
Example 1
Input : n= 4, nums = [1,2,2,3], x = 2
Output:3
Explanation:
Index 3 is the smallest index such that arr[3] > x.*/

class Solution{
public:
    int upperBound(vector<int> &nums, int x){
        int ans = nums.size();
        int low = 0;
        int high = nums.size() - 1;

        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] > x){
                ans = mid;
                high = mid -1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};