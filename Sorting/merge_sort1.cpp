/*Merge Sorting
Given an array of integers, nums,sort the array in non-decreasing order using the merge sort algorithm. Return the sorted array.
A sorted array in non-decreasing order is one in which each element is either greater than or equal to all the elements to its left in the array.
Examples:
Input: nums = [7, 4, 1, 5, 3]
Output: [1, 3, 4, 5, 7]
Explanation: 1 <= 3 <= 4 <= 5 <= 7.
Thus the array is sorted in non-decreasing order.*/


class Solution {
    void merge(vector<int> &arr, int low, int mid, int high, vector<int> &temp) {
        temp.clear();                    // ensure empty before use
        int left = low, right = mid + 1;

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
                right++;
            }
        }
        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

    void ms(vector<int> &nums, int low, int high, vector<int> &temp) {
        if (low >= high) return;
        int mid = low + (high - low) / 2;
        ms(nums, low, mid, temp);              // function call
        ms(nums, mid + 1, high, temp);         // function call
        merge(nums, low, mid, high, temp);     // pass temp
    }

public:
    vector<int> mergeSort(vector<int>& nums) {
        if (nums.empty()) return {};
        vector<int> temp;
        temp.reserve(nums.size());
        ms(nums, 0, (int)nums.size() - 1, temp);
        return nums;
    }
};
