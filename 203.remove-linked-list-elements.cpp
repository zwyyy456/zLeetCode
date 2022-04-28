/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
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
    ListNode* removeElements(ListNode* head, int target) {
        if (head != nullptr) {
            while (head->val == target) {
                ListNode *ohead = head;
                head = head->next;
                delete ohead;
                if (head == nullptr)
                    return head;
            }
            if (head != nullptr) {
                ListNode *myhead = head;
                while (myhead->next != nullptr) {
                    if (myhead->next->val == target) {
                        ListNode *onext = myhead->next;
                        myhead->next = myhead->next->next;
                        delete onext;
                    }
                    else
                        myhead = myhead->next;    
                }
            }
        }
        return head;  
    }
};
// @lc code=end

