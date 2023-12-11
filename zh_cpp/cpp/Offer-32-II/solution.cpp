// Created by Bob at 2023/06/07 09:26
// https://leetcode.cn/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/

/*
剑指 Offer 32 - II. 从上到下打印二叉树 II (Easy)
从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每
一层打印到一行。

例如:

给定二叉树: `[3,9,20,null,null,15,7]`,

```
    3
   / \
  9  20
    /  \
   15   7

```

返回其层次遍历结果：

```
[
  [3],
  [9,20],
  [15,7]
]

```

**提示：**

1. `节点总数 <= 1000`

注意：本题与主站 102 题相同： [https://leetcode-cn.com/probl
ems/binary-tree-level-order-traversal/](https://leetcode-cn.
com/problems/binary-tree-level-order-traversal/)

*/

#include <bits/stdc++.h>
#include <iterator>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        queue<TreeNode *> q;
        if (root == nullptr) {
            return res;
        }
        q.push(root);
        while (!q.empty()) {
            int cnt = q.size();
            vector<int> tmp;
            for (int i = 0; i < cnt; ++i) {
                auto *node = q.front();
                q.pop();
                tmp.push_back(node->val);
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            res.push_back(tmp);
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
