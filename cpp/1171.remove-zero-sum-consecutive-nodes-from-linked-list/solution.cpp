// Created by zwyyy456 at 2023/06/11 15:50
// https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/

/*
1171. Remove Zero Sum Consecutive Nodes from Linked List (Medium)
Given the `head` of a linked list, we repeatedly delete consecutive sequences of nodes that sum to
`0` until there are no such sequences.

After doing so, return the head of the final linked list.  You may return any such answer.

(Note that in the examples below, all sequences are serializations of `ListNode` objects.)

**Example 1:**

```
Input: head = [1,2,-3,3,1]
Output: [3,1]
Note: The answer [1,2,1] would also be accepted.

```

**Example 2:**

```
Input: head = [1,2,3,-3,4]
Output: [1,2,4]

```

**Example 3:**

```
Input: head = [1,2,3,-3,-2]
Output: [1]

```

**Constraints:**

- The given linked list will contain between `1` and `1000` nodes.
- Each node in the linked list has `-1000 <= node.val <= 1000`.

*/

#include <bits/stdc++.h>
#include <unordered_map>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    ListNode *removeZeroSumSublists(ListNode *head) {
        // 前缀和
        ListNode *vhead = new ListNode(0, head);
        ListNode *res = vhead;
        unordered_map<int, ListNode *> prefix;
        stack<int> pre;
        int sum = 0;
        while (vhead != nullptr) {
            if (prefix.find(sum + vhead->val) == prefix.end()) {
                sum += vhead->val;
                pre.push(sum);
                prefix[sum] = vhead;
            } else {
                // 说明出现了和为 0 的连续结点
                sum += vhead->val;
                while (!pre.empty() && pre.top() != sum) {
                    int val = pre.top();
                    delete prefix[val];
                    prefix.erase(val);
                    pre.pop();
                }
                vhead = vhead->next;
                prefix[sum]->next = vhead;
            }
        }
        return res->next;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    ListNode *head;
    LeetCodeIO::scan(cin, head);

    Solution *obj = new Solution();

    auto res = obj->removeZeroSumSublists(head);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
