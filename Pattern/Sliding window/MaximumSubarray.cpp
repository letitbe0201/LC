/*
Author:     Yida
Problem:    Maximum Subarray
Difficulty: Easy
Source:     https://leetcode.com/problems/maximum-subarray/

Notes:
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
 
Solution: Kadane's algorithm. Iterate over each element, and pick the larger number between the visiting number or the sum of previous biggest subsequence and the visiting number.
*/



// Kadane's Algorithm
class Solution {
public:
    // Vector container "nums"
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxnum = nums[0];
        
        if (nums.empty())
            return 0;
        else
            // Largest subsequence should be either the current nums[i] itself or nums[i]+previous_largest_subsequence
            for (int i=0; i<nums.size(); i++) {
                //cout << nums[i] << " ";
                sum = max(nums[i], sum+nums[i]);
                maxnum = max(maxnum, sum);
            }
        return maxnum;
    }
};