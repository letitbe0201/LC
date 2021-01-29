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
 
Solution: https://leetcode.com/problems/linked-list-cycle-ii/discuss/44781/Concise-O(n)-solution-by-using-C%2B%2B-with-Detailed-Alogrithm-Description
          The distance between the head location and entry location is equal to the distance between the meeting location and the entry location along the direction of forward movement.
          When the slow pointer and the fast pointer encounter in the cycle, we can define a pointer "entry" that point to the head, this "entry" pointer moves one step each time so as the slow pointer. When this "entry" pointer and the slow pointer both point to the same location, this location is the node where the cycle begins.
*/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fastP = head;
        ListNode *slowP = head;
        ListNode *entry = head;
        
        while (fastP!=NULL && fastP->next!=NULL && fastP->next->next!=NULL) {
            fastP = fastP->next->next;
            slowP = slowP->next;
            
            if (fastP == slowP) {
                while (slowP != entry) {
                    // head<->entry == entry<->meet point 
                    slowP = slowP->next;
                    entry = entry->next;
                }
                return entry;
            }
        }
        return NULL;
    }
};

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