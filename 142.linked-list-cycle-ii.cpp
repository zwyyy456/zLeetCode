/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include "mListNode.h"
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *vhead = new ListNode(0, head);
        ListNode *fast = vhead, *slow = vhead;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                while (vhead != slow) {
                    vhead = vhead->next;
                    slow = slow->next;
                }
                delete vhead;
                return slow;
            }
        }
        return nullptr;
    }
};
// @lc code=end

