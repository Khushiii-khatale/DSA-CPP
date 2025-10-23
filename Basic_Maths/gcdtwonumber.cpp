/*GCD of two numbers

Given two positive integers a and b, find GCD of a and b.

Note: Don't use the inbuilt gcd function

Examples:

Input: a = 20, b = 28
Output: 4
Explanation: GCD of 20 and 28 is 4
Input: a = 60, b = 36
Output: 12
Explanation: GCD of 60 and 36 is 12*/

class Solution {
  public:
    int gcd(int a, int b) {
        if (a == 0)
            return b;
        if (b == 0)
            return a;
            
        if (a == b)
            return a;
            
        if (a > b)
            return gcd(a - b, b);   // ✅ recursive call
        else
            return gcd(a, b - a);   // ✅ recursive call
    }
};
