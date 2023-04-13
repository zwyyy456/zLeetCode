// Created by zwyyy456 at 2023/04/10 09:44
// https://leetcode.com/problems/next-greater-node-in-linked-list/

/*
1019. Next Greater Node In Linked List (Medium)

You are given the `head` of a linked list with `n` nodes.

For each node in the list, find the value of the **next greater node**. That is, for each node, find
the value of the first node that is next to it and has a **strictly larger** value than it.

Return an integer array `answer` where `answer[i]` is the value of the next greater node of the
`ith` node ( **1-indexed**). If the `ith` node does not have a next greater node, set `answer[i] =
0`.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/08/05/linkedlistnext1.jpg)

```
Input: head = [2,1,5]
Output: [5,5,0]

```

**Example 2:**

![](https://assets.leetcode.com/uploads/2021/08/05/linkedlistnext2.jpg)

```
Input: head = [2,7,4,3,5]
Output: [7,0,5,5,0]

```

**Constraints:**

- The number of nodes in the list is `n`.
- `1 <= n <= 10⁴`
- `1 <= Node.val <= 10⁹`
*/

// @lc code=begin
#include <stack>
#include "listnode.h"
#include <vector>
#include <utility>
using std::vector;
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        std::stack<std::pair<int, int>> stk;
        int i = 0;
        vector<int> res;
        while (head != nullptr) {
            res.push_back(0);
            while (!stk.empty() && head->val > stk.top().second) {
                auto [idx, val] = stk.top();
                res[idx] = head->val;
                stk.pop();
            }
            stk.push({i, head->val});
            ++i;
            head = head->next;
        }
        return res;
    }
};

// @lc code=end
