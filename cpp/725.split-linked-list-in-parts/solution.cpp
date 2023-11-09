// Created by zwyyy456 at 2023/11/05 20:55
// leetgo: 1.3.8
// https://leetcode.com/problems/split-linked-list-in-parts/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    vector<ListNode *> splitListToParts(ListNode *head, int k) {
        int cnt = 0;
        ListNode *tmp = head;
        while (tmp != nullptr) {
            cnt += 1;
            tmp = tmp->next;
        }
        int a = cnt / k, b = cnt % k;

        vector<ListNode *> res(k);
        for (int i = 0; i < k; ++i) {
            if (b > 0) {
                res.push_back(head);
                for (int j = 0; j < a; ++j) {
                    head = head->next;
                }
                if (head != nullptr) {
                    auto tmp = head->next;
                    head->next = nullptr;
                    head = tmp;
                }
            } else {
                res.push_back(head);
                for (int j = 0; j < a - 1; ++j) {
                    head = head->next;
                }
                if (head != nullptr) {
                    auto tmp = head->next;
                    head->next = nullptr;
                    head = tmp;
                }
            }
        }
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    ListNode *head;
    LeetCodeIO::scan(cin, head);
    int k;
    LeetCodeIO::scan(cin, k);

    Solution *obj = new Solution();
    auto res = obj->splitListToParts(head, k);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
