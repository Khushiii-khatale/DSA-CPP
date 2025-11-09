/*Quick Sorting

Hints
Given an array of integers called nums, sort the array in non-decreasing order using the quick sort algorithm and return the sorted array.
A sorted array in non-decreasing order is an array where each element is greater than or equal to all preceding elements in the array.
Examples:
Input: nums = [7, 4, 1, 5, 3]
Output: [1, 3, 4, 5, 7]
Explanation: 1 <= 3 <= 4 <= 5 <= 7.
Thus the array is sorted in non-decreasing order.*/

class Solution {
    int partition(vector<int> &arr, int low, int high) {
        int pivot = arr[low];
        int i = low, j = high;

        while (i < j) {
            // move i right while <= pivot (but stop at high-1)
            while (i <= high - 1 && arr[i] <= pivot) i++;
            // move j left while > pivot (but stop at low+1)
            while (j >= low + 1 && arr[j] > pivot) j--;
            if (i < j) swap(arr[i], arr[j]);
        }
        // place pivot at its final position
        swap(arr[low], arr[j]);
        return j; // pivot index
    }

    void qs(vector<int> &arr, int low, int high) {
        if (low >= high) return;
        int pIndex = partition(arr, low, high);
        qs(arr, low, pIndex - 1);   // left of pivot
        qs(arr, pIndex + 1, high);  // right of pivot
    }

public:
    vector<int> quickSort(vector<int>& nums) {
        if (!nums.empty())
            qs(nums, 0, (int)nums.size() - 1);
        return nums;
    }
};
