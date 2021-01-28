/*
Author:     Yida
Problem:    Linked List Cycle II
Difficulty: Medium
Source:     https://leetcode.com/problems/linked-list-cycle-ii/

Notes:
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
Notice that you should not modify the linked list.

Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
 
Solution: TODO 
*/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*TODO*/

/* BRUTE FORCE
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        vector<ListNode*> container;
        ListNode *index;
        index = head;
        // Loop through every elements, return any repeating node(if there's any.)
        // Return NULL if we meets a null.
        while (index!=NULL) {
            for (int i=0; i<container.size(); i++) {
                if(container[i]==index)
                    return index;
            }
            // Store every elements
            container.push_back(index);
            index = index->next;
        }
        return NULL;
    }
};
*/