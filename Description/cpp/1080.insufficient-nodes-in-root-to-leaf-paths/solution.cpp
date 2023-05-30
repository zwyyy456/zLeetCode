// Created by Bob at 2023/05/22 10:30
// https://leetcode.cn/problems/insufficient-nodes-in-root-to-leaf-paths/

/*
1080. 根到叶路径上的不足节点 (Medium)
给你二叉树的根节点 `root` 和一个整数 `limit` ，请你同时删除
树中所有 **不足节点**，并返回最终二叉树的根节点。

假如通过节点 `node` 的每种可能的 “根-叶” 路径上值的总和全都
小于给定的 `limit`，则该节点被称之为 **不足节点**，需要被删
除。

**叶子节点**，就是没有子节点的节点。

**示例 1：**

![](https://assets.leetcode.com/uploads/2019/06/05/insuffici
ent-11.png)

```
输入：root = [1,2,3,4,-99,-99,7,8,9,-99,-99,12,13,-99,14], l
imit = 1
输出：[1,2,3,4,null,null,7,8,9,null,14]

```

**示例 2：**

![](https://assets.leetcode.com/uploads/2019/06/05/insuffici
ent-3.png)

```
输入：root = [5,4,8,11,null,17,4,7,1,null,null,5,3], limit =
22
输出：[5,4,8,11,null,17,4,7,null,null,null,5]

```

**示例 3：**

![](https://assets.leetcode.com/uploads/2019/06/11/screen-sh
ot-2019-06-11-at-83301-pm.png)

```
输入：root = [1,2,-3,-5,null,4,null], limit = -1
输出：[1,null,-3,4]

```

**提示：**

- 树中节点数目在范围 `[1, 5000]` 内
- `-10⁵ <= Node.val <= 10⁵`
- `-10⁹ <= limit <= 10⁹`

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    TreeNode *sufficientSubset(TreeNode *root, int limit) {
        limit -= root->val;
        if (root->left != nullptr && root->right != nullptr) {
            return limit < 0 ? root : nullptr;
        }
        if (root->left) {
            root->left = sufficientSubset(root->left, limit);
        }
        if (root->right) {
            root->right = sufficientSubset(root->right, limit);
        }
        return root->left == nullptr && root->right == nullptr ? nullptr : root;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    TreeNode *root;
    LeetCodeIO::scan(cin, root);
    int limit;
    LeetCodeIO::scan(cin, limit);

    Solution *obj = new Solution();

    auto res = obj->sufficientSubset(root, limit);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
