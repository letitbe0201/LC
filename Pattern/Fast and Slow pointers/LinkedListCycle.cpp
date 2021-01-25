/*
Author:     Yida
Problem:    Linked List Cycle
Difficulty: Easy
Source:     https://leetcode.com/problems/linked-list-cycle/

Notes:
Given head, the head of a linked list, determine if the linked list has a cycle in it.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
Return true if there is a cycle in the linked list. Otherwise, return false.

Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
 
Solution: https://leetcode.com/problems/linked-list-cycle/discuss/1031527/Two-pointer-solution-wvideo-whiteboard-explanation
          We make two pointers, a fast pointer and a slow pointer. The fast pointer moves foward by two nodes at each step and the slow pointer moves only one node at each step.
          If these two pointer meet, we know that there's a loop in the linked-list. Otherwise, the fast pointers meets NULL, and return FALSE.
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
    bool hasCycle(ListNode *head) {
        // The faster pointer moves by two while the slow pointer takes one step in each iteration.
        ListNode *fastP = head;
        ListNode *slowP = head;
        
        while (fastP!=NULL && fastP->next!=NULL && fastP->next->next!=NULL) {
            fastP = fastP->next->next;
            slowP = slowP->next;
            // Two pointers meet, which means that the linked-list contains a loop
            if (fastP == slowP) return true;
        }
        return false;
    }
};

/*
class Solution_2 {
public:
    vector<ListNode *> container;
    ListNode *index;
    bool hasCycle(ListNode *head) {
        index = head;
        if (head==NULL) return false;
        while (index->next!=NULL) {
            for (int i=0; i<container.size(); i++) {
                if (index==container[i])
                    return true;
            }
            container.push_back(index);
            index = index->next;
        }
        return false;
    }
};
*/