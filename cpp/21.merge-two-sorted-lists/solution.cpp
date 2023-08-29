// Created by zwyyy456 at 2023/08/06 15:06
// leetgo: 1.3.1
// https://leetcode.com/problems/merge-two-sorted-lists/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        ListNode *vhead = new ListNode;
        ListNode *tmp = vhead;
        while (list1 || list2) {
            if (list1 != nullptr && list2 != nullptr) {
                if (list1->val <= list2->val) {
                    tmp->next = list1;
                    tmp = tmp->next;
                    list1 = list1->next;
                } else {
                    tmp->next = list2;
                    tmp = tmp->next;
                    list2 = list2->next;
                }
            } else if (list1 != nullptr && list2 == nullptr) {
                tmp->next = list1;
                tmp = tmp->next;
                list1 = list1->next;
            } else if (list1 == nullptr && list2 != nullptr) {
                tmp->next = list2;
                tmp = tmp->next;
                list2 = list2->next;
            }
        }
        return vhead->next;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    ListNode *list1;
    LeetCodeIO::scan(cin, list1);
    ListNode *list2;
    LeetCodeIO::scan(cin, list2);

    Solution *obj = new Solution();

    auto res = obj->mergeTwoLists(list1, list2);

    LeetCodeIO::print(out_stream, res);
    cout << "
        output : " << out_stream.rdbuf() << endl;

                 delete obj;
    return 0;
}
