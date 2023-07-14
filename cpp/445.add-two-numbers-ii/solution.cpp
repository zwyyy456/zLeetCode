// Created by zwyyy456 at 2023/07/03 22:34
// leetgo: 1.3.2
// https://leetcode.com/problems/add-two-numbers-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    string tostr(ListNode *l) {
        vector<char> tmp;
        while (l != nullptr) {
            tmp.push_back(l->val + '0');
            l = l->next;
        }
        return string(tmp.begin(), tmp.end());
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        string str1 = tostr(l1);
        string str2 = tostr(l2);
        vector<int> sum;
        int len = max(str1.size(), str2.size());
        int r1 = str1.size(), r2 = str2.size();
        int num = 0;
        for (int k = 1; k <= len; ++k) {
            int c1 = r1 - k >= 0 ? str1[r1 - k] - '0' : 0;
            int c2 = r2 - k >= 0 ? str2[r2 - k] - '0' : 0;
            int add = (c1 + c2 + num) % 10;
            sum.push_back(add);
            num = (c1 + c2 + num) / 10;
        }
        if (num != 0) {
            sum.push_back(num);
        }
        int r = sum.size() - 1;
        ListNode *head = new ListNode(sum[r--]);
        ListNode *res = head;
        while (r >= 0) {
            ListNode *tmp = new ListNode(sum[r--]);
            head->next = tmp;
            head = head->next;
        }
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    ListNode *l1;
    LeetCodeIO::scan(cin, l1);
    ListNode *l2;
    LeetCodeIO::scan(cin, l2);

    Solution *obj = new Solution();

    auto res = obj->addTwoNumbers(l1, l2);

    LeetCodeIO::print(out_stream, res);
    cout << "
        output : " << out_stream.rdbuf() << endl;

                 delete obj;
    return 0;
}
