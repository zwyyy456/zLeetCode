/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *zhead = new ListNode(0);
        zhead->next = head;
        ListNode *fast = zhead;
        ListNode *slow = zhead;
        int i = 0;
        while (fast->next != nullptr) {
            fast = fast->next;
            i++;
        }
        for (int j = 0; j < n - i; j++) {
            slow = slow->next;
        }
        slow->next = slow->next->next;
        delete zhead;
        return head;
    }
};
// @lc code=end

