/*
Author:     Yida
Problem:    Target Sum
Difficulty: Medium
Source:     https://leetcode.com/problems/target-sum/

Notes:
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.
Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 
-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3
There are 5 ways to assign symbols to make the sum of nums be target 3.
 
Constraints:
The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.
 
Solution: https://leetcode.com/problems/target-sum/discuss/455024/DP-IS-EASY!-5-Steps-to-Think-Through-DP-Questions.
          This is a solution without memorization. We can further improve efficiency by having a dictionary memorizing (cur_index, cur_sum) to avoid repeating computations.
          
*/



class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int index = nums.size()-1;
        int sum = 0;
        
        sum = knapsack(nums, S, index, sum);
        return sum;
    }
    
    int knapsack(vector<int>& nums, int S, int cur_index, int cur_sum) {
        int pos, neg = 0;
        // 2 Base cases: either the result meets the goal or we fail
        if (cur_index<0 && cur_sum==S)
            return 1;
        if (cur_index<0)
            return 0;
        //+num for pos; -num for neg
        pos = knapsack(nums, S, cur_index-1, cur_sum+nums[cur_index]);
        neg = knapsack(nums, S, cur_index-1, cur_sum-nums[cur_index]);
        return pos+neg;
    }
};