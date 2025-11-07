Sum of First N Numbers

Given an integer N, return the sum of first N natural numbers. Try to solve this using recursion.
Examples:
Input : N = 4
Output : 10
Explanation : first four natural numbers are 1, 2, 3, 4.
Sum is 1 + 2 + 3 + 4 => 10.

class Solution{	
	public:
		int NnumbersSum(int N){
			//your code goes here
            if(N == 0){
                return 0;
            }
            return N + NnumbersSum(N-1);
		}
};