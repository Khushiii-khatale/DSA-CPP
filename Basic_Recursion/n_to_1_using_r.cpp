/*Print N to 1 using Recursion

Given an integer n, write a function to print all numbers from n to 1 (inclusive) using recursion.
You must not use any loops such as for, while, or do-while.
The function should print each number on a separate line, in decreasing order from n to 1
Examples:
Input: 5
Output:
5
4
3
2
1*/

class Solution {
  public:
    void printNumbers(int n) {
        // Your code goes here
        if(n == 0){
          return;
        }
        cout << n << endl;
        printNumbers(n-1);
    }
};