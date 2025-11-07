/*Print 1 to N using Recursion
Given an integer n, write a function to print all numbers from 1 to n (inclusive) using recursion.
You must not use any loops such as for, while, or do-while.
The function should print each number on a separate line, in increasing order from 1 to n.
Examples:
Input: n = 5

Output:
1  
2  
3  
4  
5*/

class Solution {
  public:
    void printNumbers(int n) {
        // Your code goes here
        if(n == 0){
          return;
        }
        printNumbers(n-1);
        cout << n << endl;
    }
};