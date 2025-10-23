/*Divisors of a Number

You are given an integer n. You need to find all the divisors of n. Return all the divisors of n as an array or list in a sorted order.

A number which completely divides another number is called it's divisor.

Examples:
Input: n = 6

Output = [1, 2, 3, 6]

Explanation: The divisors of 6 are 1, 2, 3, 6.

Input: n = 8

Output: [1, 2, 4, 8]

Explanation: The divisors of 8 are 1, 2, 4, 8.*/

class Solution {
public:
    vector<int> divisors(int n) {
        vector<int> result;

    for(int i=1; i*i <= n; i++){
        if(n % i == 0)
            result.push_back(i);
        if(i != n / i)
            result.push_back(n / i);
    }
    sort(result.begin(), result.end());
    return result;
    }
};