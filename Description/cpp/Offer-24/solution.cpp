// Created by Bob at 2023/06/06 09:11
// https://leetcode.cn/problems/fan-zhuan-lian-biao-lcof/

/*
剑指 Offer 24. 反转链表 (Easy)
定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链
表的头节点。

**示例:**

```
输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
```

**限制：**

`0 <= 节点个数 <= 5000`

**注意**：本题与主站 206 题相同： [https://leetcode-cn.com/p
roblems/reverse-linked-list/](https://leetcode-cn.com/proble
ms/reverse-linked-list/)

*/

#include <algorithm>
#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *vhead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return vhead;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    ListNode *head;
    LeetCodeIO::scan(cin, head);

    Solution *obj = new Solution();

    auto res = obj->reverseList(head);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
