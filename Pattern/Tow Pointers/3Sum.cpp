/*
Author:     Yida
Problem:    3Sum
Difficulty: Medium
Source:     https://leetcode.com/problems/3sum/

Notes:
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
Notice that the solution set must not contain duplicate triplets.

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
 
Solution: Similar to 2 sum problem. We use three pointers (an index, head and rear pointer) to iterate over the array.
          Since the array is sorted, it's obviously to either move the head forward or rear pointer backward if the sum is not equal to 0.
          Also, we use while loop to avoid picking repeating patterns.
*/



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 2D vector
        vector<vector<int>> goal;
        int array_size = nums.size();
        // Sort before iteration
        sort(nums.begin(), nums.end());

        if (array_size<3) return {};
        else  {
            for (auto i=0; i<array_size;) {
                auto head = i+1;
                auto rear = array_size-1;
                
                while (head < rear) {
                    auto sum = nums[i]+nums[head]+nums[rear];
                
                    if (sum == 0) {
                        goal.push_back({nums[i], nums[head], nums[rear]});
                        head++;
                        rear--;
                        // Avoid repeating elements
                        while((head<rear) && (nums[head]==nums[head-1])) head++;
                        while((head<rear) && (nums[rear]==nums[rear+1])) rear--;
                    }
                    else if (sum < 0) {
                        // Since the array is sorted, we know that the rear head pointer should increase
                        head++;
                        while((head<rear) && (nums[head]==nums[head-1])) head++;
                    }
                    else {
                        rear--;
                        while((head<rear) && (nums[rear]==nums[rear+1])) rear--;
                    }
                }
                
                i++;
                while((i<array_size) && (nums[i]==nums[i-1])) i++; // Avoid repeating element
            }
            return goal;
        }
    }
};