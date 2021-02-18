/*
Author:     Yida
Problem:    Merge Intervals
Difficulty: Medium
Source:     https://leetcode.com/problems/merge-intervals/

Notes:
Given an array of intervals where intervals[i] = [starti, endi], 
merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

Example 1:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
 
Solution: First, we sort the intervals using sort(). Then, we compare all the intervals. 
If we find overlap, merge them. Otherwise, put the numbers into output buffer.
*/



class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return intervals;
        
        vector<vector<int>> output; // Output buffer
        sort(intervals.begin(), intervals.end()); // Sort Intervals
        output.push_back(intervals[0]);
        for (int i=1; i<intervals.size(); i++) {
            if (intervals[i][0] <= output.back()[1]) // EX. [1,3][2,6] => 3>2
                output.back()[1] = max(output.back()[1], intervals[i][1]);
            else
                output.push_back(intervals[i]); // No overlap
        }
        return output;
    }
};