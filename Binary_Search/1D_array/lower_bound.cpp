/*Lower Bound

Given a sorted array of nums and an integer x, write a program to find the lower bound of x.
The lower bound algorithm finds the first and smallest index in a sorted array where the value at that index is greater than or equal to a given key i.e. x.
If no such index is found, return the size of the array.
Example 1
Input : nums= [1,2,2,3], x = 2
Output:1
Explanation:
Index 1 is the smallest index such that arr[1] >= x.*/

class Solution{
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
};