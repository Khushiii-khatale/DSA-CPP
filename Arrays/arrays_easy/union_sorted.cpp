/*Union of two sorted arrays
Given two sorted arrays nums1 and nums2, return an array that contains the union of these two arrays. The elements in the union must be in ascending order.
The union of two arrays is an array where all values are distinct and are present in either the first array, the second array, or both.
Examples:
Input: nums1 = [1, 2, 3, 4, 5], nums2 = [1, 2, 7]
Output: [1, 2, 3, 4, 5, 7]
Explanation:
The elements 1, 2 are common to both, 3, 4, 5 are from nums1 and 7 is from nums2*/

class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i = 0;
        int j = 0;
        vector<int> sortedArr;

        while(i < n1 && j < n2){
            if(nums1[i] < nums2[j]){
                if(sortedArr.size() == 0 || sortedArr.back() != nums1[i]){
                    sortedArr.push_back(nums1[i]);
                }
                i++;
            }
            else{
                if(sortedArr.size() == 0 || sortedArr.back() != nums2[j]){
                    sortedArr.push_back(nums2[j]);
                }
                j++;
            }
        }

        while(j<n2){
            if(sortedArr.size() == 0 || sortedArr.back() != nums2[j]){
                sortedArr.push_back(nums2[j]);
            }
            j++;
        }

        while(i<n1){
            if(sortedArr.size() == 0 || sortedArr.back() != nums1[i]){
                sortedArr.push_back(nums1[i]);
            }
            i++;
        }

        return sortedArr;
    }
};