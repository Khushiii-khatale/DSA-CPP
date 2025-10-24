/*Check for Prime Number

Hints
You are given an integer n. You need to check if the number is prime or not. Return true if it is a prime number, otherwise return false.

A prime number is a number which has no divisors except 1 and itself.

Examples:
Input: n = 5

Output: true

Explanation: The only divisors of 5 are 1 and 5 , So the number 5 is prime.*/

class Solution {
public:
    bool isPrime(int n) {
        //your code goes here
        if(n <= 0)
        return false;

        if(n >= 0){
            for(int i=2; i*i <= n; i++){
                if(n % i == 0)
                return false;
            }
            return true;
        }
    }
};
