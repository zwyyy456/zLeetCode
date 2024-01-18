// Created by Bob at 2023/06/06 09:27
// https://leetcode.cn/problems/reverse-linked-list/

/*
206. 反转链表 (Easy)
给你单链表的头节点 `head` ，请你反转链表，并返回反转后的链表
。

**示例 1：**

![](https://assets.leetcode.com/uploads/2021/02/19/rev1ex1.j
pg)

```
输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]

```

**示例 2：**

![](https://assets.leetcode.com/uploads/2021/02/19/rev1ex2.j
pg)

```
输入：head = [1,2]
输出：[2,1]

```

**示例 3：**

```
输入：head = []
输出：[]

```

**提示：**

- 链表中节点的数目范围是 `[0, 5000]`
- `-5000 <= Node.val <= 5000`

**进阶：** 链表可以选用迭代或递归方式完成反转。你能否用两种
方法解决这道题？

*/

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
        ListNode *l = head, *r = head->next;
        l->next = nullptr;
        while (r != nullptr) {
            ListNode *tmp = r->next;
            r->next = l;
            l = r;
            r = tmp;
        }
        return l;
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
