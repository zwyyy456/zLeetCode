// Created by Bob at 2023/06/07 09:31
// https://leetcode.cn/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof/

/*
剑指 Offer 32 - III. 从上到下打印二叉树 III (Medium)
请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右
的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到
右的顺序打印，其他行以此类推。

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
  [20,9],
  [15,7]
]

```

**提示：**

1. `节点总数 <= 1000`

*/

#include <algorithm>
#include <bits/stdc++.h>
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
        int lvl = 0;
        while (!q.empty()) {
            int cnt = q.size();
            ++lvl;
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
            if (lvl % 2 == 0) {
                reverse(tmp.begin(), tmp.end());
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
