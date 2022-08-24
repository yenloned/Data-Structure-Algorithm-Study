//https://leetcode.com/problems/climbing-stairs/
/*
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example:
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
*/

class Solution {
    //Bottom-Up solution, Time Complexity of O(n), Space Complexity of O(1)
    //Reference: https://www.youtube.com/watch?v=Y0lT9Fck7qI&ab_channel=NeetCode
public:
    int climbStairs(int n) {
        
        int first = 1;
        int second = 1;
        
        int result = 0;
        
        //sum the last 2 steps in each iteration
        //in the opposite view (bottom-up), there will only be 1 / 2 steps forward (e.g. 3 -> 4 / 3 -> 5). Therefore, the steps of 3 can climb will be the sum of step4 and step5.
        for (int i = 0; i < n-1; i++) {
            int temp = first;
            //sum last and second last
            first = first + second;
            //second last
            second = temp;
        }
        
        return first;
    }
};

//Memorization solution can also solve this question with same Time and Space Complexity