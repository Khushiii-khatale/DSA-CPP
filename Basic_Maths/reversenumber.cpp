/*Reverse a number

You are given an integer n. Return the integer formed by placing the digits of n in reverse order.

Examples:
Input: n = 25

Output: 52

Explanation: Reverse of 25 is 52.

Input: n = 123

Output: 321

Explanation: Reverse of 123 is 321.*/

class Solution {
public:
    int reverseNumber(int n) {
        int rev = 0;
        while(n>0){
            int digit = x % 10;
            rev = rev * 10 + digit;
            n = n / 10;
        }
    return rev;
    }

};