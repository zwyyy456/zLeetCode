// Created by Bob at 2023/06/06 09:37
// https://leetcode.cn/problems/fu-za-lian-biao-de-fu-zhi-lcof/

/*
剑指 Offer 35. 复杂链表的复制 (Medium)
请实现 `copyRandomList` 函数，复制一个复杂链表。在复杂链表中
，每个节点除了有一个 `next` 指针指向下一个节点，还有一个 `ra
ndom` 指针指向链表中的任意节点或者 `null`。

**示例 1：**

![](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/
2020/01/09/e1.png)

```
输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]

```

**示例 2：**

![](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/
2020/01/09/e2.png)

```
输入：head = [[1,1],[2,1]]
输出：[[1,1],[2,1]]

```

**示例 3：**

**![](https://assets.leetcode-cn.com/aliyun-lc-upload/upload
s/2020/01/09/e3.png)**

```
输入：head = [[3,null],[3,0],[3,null]]
输出：[[3,null],[3,0],[3,null]]

```

**示例 4：**

```
输入：head = []
输出：[]
解释：给定的链表为空（空指针），因此返回 null。

```

**提示：**

- `-10000 <= Node.val <= 10000`
- `Node.random` 为空（null）或指向链表中的节点。
- 节点数目不超过 1000 。

**注意：** 本题与主站 138 题相同： [https://leetcode-cn.com/
problems/copy-list-with-random-pointer/](https://leetcode-cn
.com/problems/copy-list-with-random-pointer/)

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	 head; LeetCodeIO::scan(cin, head);

	Solution *obj = new Solution();

	auto res = obj->copyRandomList(head);

	LeetCodeIO::print(out_stream, res);
	cout << "output: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
