/*
Author:     Yida
Problem:    Longest Substring Without Repeating Characters
Difficulty: Medium
Source:     https://leetcode.com/problems/longest-substring-without-repeating-characters/

Notes:
Given a string s, find the length of the longest substring without repeating characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
 
Solution: Dict contains the index of shown characters(-1 otherwise).
          When "dict[s[i]]>start", which means the char is in the dict, we replace the start point with the new index.
          Compare previous maximum with the new length (i-start).
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
            vector<int> dict(256, -1); // Character container
            int maxl = 0; // Max length
            int start = -1; // Index of the start point without repeating chars.
        
        	// s[i] is the character
            for (int i=0; i<s.length(); i++) {
                if (dict[s[i]] > start) // Hold when the char is already in the dict
                    start = dict[s[i]];
                dict[s[i]] = i; // Assign the index number to the dictionary
                maxl = max(maxl, i-start);
            } 
            return maxl;
        }
};

