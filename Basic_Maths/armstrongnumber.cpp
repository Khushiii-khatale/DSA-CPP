/*Check if the Number is Armstrong

Hints
You are given an integer n. You need to check whether it is an armstrong number or not. Return true if it is an armstrong number, otherwise return false.

An armstrong number is a number which is equal to the sum of the digits of the number, raised to the power of the number of digits.

Examples:
Input: n = 153

Output: true

Explanation: Number of digits : 3.

13 + 53 + 33 = 1 + 125 + 27 = 153.

Therefore, it is an Armstrong number.*/

class Solution {
public:
    bool isArmstrong(int n) {
        int original = n;
        int digits = 0;

        int temp = n;
        while(temp != 0){
            digits++;
            temp /= 10;
        }

        int sum = 0;
        temp = n;

        while(temp != 0){
            int digit = temp % 10;
            sum += pow(digit, digits);
            temp /= 10;
        }
        return (sum == original);
    }
};

