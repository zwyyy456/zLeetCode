// Created by Bob at 2023/06/06 09:06
// https://leetcode.cn/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/

/*
剑指 Offer 22. 链表中倒数第k个节点 (Easy)
输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的
习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。

例如，一个链表有 `6` 个节点，从头节点开始，它们的值依次是 `1
、2、3、4、5、6`。这个链表的倒数第 `3` 个节点是值为 `4` 的节
点。

**示例：**

```
给定一个链表: 1->2->3->4->5, 和 k = 2.

返回链表 4->5.
```

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    ListNode *getKthFromEnd(ListNode *head, int k) {
        int i = 0;
        ListNode *fast = head, *slow = head;
        for (int i = 0; i < k; ++i) {
            fast = fast->next;
        }
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
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

    auto res = obj->getKthFromEnd(head, k);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
