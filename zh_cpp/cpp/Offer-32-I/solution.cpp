// Created by Bob at 2023/06/07 09:22
// https://leetcode.cn/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/

/*
剑指 Offer 32 - I. 从上到下打印二叉树 (Medium)
从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺
序打印。

例如:

给定二叉树: `[3,9,20,null,null,15,7]`,

```
    3
   / \
  9  20
    /  \
   15   7

```

返回：

```
[3,9,20,15,7]

```

**提示：**

1. `节点总数 <= 1000`

*/

#include <bits/stdc++.h>
#include <queue>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    vector<int> levelOrder(TreeNode *root) {
        vector<int> res;
        queue<TreeNode *> q;
        if (root == nullptr) {
            return res;
        }
        q.push(root);
        while (!q.empty()) {
            auto *node = q.front();
            q.pop();
            res.push_back(node->val);
            if (node->left != nullptr) {
                q.push(node->left);
            }
            if (node->right != nullptr) {
                q.push(node->right);
            }
        }
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    TreeNode *root;
    LeetCodeIO::scan(cin, root);

    Solution *obj = new Solution();

    auto res = obj->levelOrder(root);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
