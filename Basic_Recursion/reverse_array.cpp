/*Reverse an array

Hints
Given an array arr of n elements. The task is to reverse the given array. The reversal of array should be inplace.

Examples:
Input: n=5, arr = [1,2,3,4,5]
Output: [5,4,3,2,1]
Explanation: The reverse of the array [1,2,3,4,5] is [5,4,3,2,1]*/

class Solution{
public:
    void reverse(int arr[], int n){
        int left = 0; int right = n-1;

        if(left < right){
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;

            left++;
            right--;
        }
};
