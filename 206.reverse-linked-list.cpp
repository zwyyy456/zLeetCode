/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
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
    ListNode* reverseList(ListNode* head) {
        ListNode *pre, *cur;
        ListNode *myhead = new ListNode(0);
        myhead->next = head;
        if (myhead->next == nullptr) {
            delete myhead;
            return head;
        }
        cur = myhead->next;
        if (cur->next == nullptr) {
            delete myhead;
            return head;
        }
        cur = cur->next;
        // if (cur->next != nullptr)
        //     pre = cur->next;
        while (cur->next != nullptr) {
            ListNode *temp = cur->next;
            pre = myhead->next;
            myhead->next = cur;
            myhead->next->next = pre; 
            cur = temp;
        }
        pre = myhead->next;
        myhead->next = cur;
        myhead->next->next = pre;
        head->next = nullptr;
        head = myhead->next;
        delete myhead;
        return head;
        
    }
};
// @lc code=end

