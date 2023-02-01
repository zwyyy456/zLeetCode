/*
 * @lc app=leetcode id=1669 lang=cpp
 *
 * [1669] Merge In Between Linked Lists
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
class Solution {
  public:
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {
        ListNode *head = list1;
        ListNode *tail2 = list2;
        ListNode *head2 = list1;
        for (int i = 0; i < a - 1; i++) {
            head = head->next;
        }
        for (int i = 0; i < b; i++) {
            head2 = head2->next;
        }
        while (tail2->next != nullptr)
            tail2 = tail2->next;
        tail2->next = head2->next;
        head2->next = nullptr;
        head->next = list2;
        return list1;
    }
};
// @lc code=end
