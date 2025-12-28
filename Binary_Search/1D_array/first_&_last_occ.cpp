/*34. Find First and Last Position of Element in Sorted Array

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.
Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]*/

class Solution {
public:
    int lowerBound(vector<int> &nums, int x){
        int ans = nums.size();
        int low = 0;
        int high = nums.size()-1;

        while(low <= high){
            int mid  = (low+high)/2;
            if(nums[mid] >= x){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid +1;
            }
        }
        return ans;
    }
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
    vector<int> searchRange(vector<int>& nums, int x) {
        int lb = lowerBound(nums, x);
        if(lb == nums.size() || nums[lb] != x) return {-1, -1};
        return {lb, upperBound(nums, x)-1};
    }
};

/*EASY WAY

class Solution{
public:

    int firstOccurrence(vector<int> &nums, int target){
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int first = -1;

        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] == target){
                first = mid;
                high = mid -1;
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return first;
    }
    int lastOccurrence(vector<int> &nums, int target){
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int last = -1;

        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] == target){
                last = mid;
                low = mid + 1;
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return last;
    }
    vector<int> searchRange(vector<int> &nums, int target) {
        int first = firstOccurrence(nums, target);
        if(first == -1) return {-1, -1};
        int last = lastOccurrence(nums, target);
        return {first, last};
    }
};*/
