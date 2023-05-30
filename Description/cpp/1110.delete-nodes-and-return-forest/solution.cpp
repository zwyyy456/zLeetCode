// Created by Bob at 2023/05/30 08:52
// https://leetcode.cn/problems/delete-nodes-and-return-forest/

/*
1110. 删点成林 (Medium)
给出二叉树的根节点 `root`，树上每个节点都有一个不同的值。

如果节点值在 `to_delete` 中出现，我们就把该节点从树上删去，
最后得到一个森林（一些不相交的树构成的集合）。

返回森林中的每棵树。你可以按任意顺序组织答案。

**示例 1：**

**![](https://assets.leetcode-cn.com/aliyun-lc-upload/upload
s/2019/07/05/screen-shot-2019-07-01-at-53836-pm.png)**

```
输入：root = [1,2,3,4,5,6,7], to_delete = [3,5]
输出：[[1,2,null,4],[6],[7]]

```

**示例 2：**

```
输入：root = [1,2,4,null,3], to_delete = [3]
输出：[[1,2,4]]

```

**提示：**

- 树中的节点数最大为 `1000`。
- 每个节点都有一个介于 `1` 到 `1000` 之间的值，且各不相同。
- `to_delete.length <= 1000`
- `to_delete` 包含一些从 `1` 到 `1000`、各不相同的值。

*/

#include <bits/stdc++.h>
#include <unordered_set>
#include <vector>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    auto dfs(TreeNode *root, unordered_set<int> &to_delete, vector<TreeNode *> &res) -> TreeNode * {
        if (to_delete.find(root->val) == to_delete.end()) {
            if (root->left != nullptr) {
                root->left = dfs(root->left, to_delete, res);
            }
            if (root->right != nullptr) {
                root->right = dfs(root->right, to_delete, res);
            }
        }
    }
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
        // 前序遍历?
        vector<TreeNode *> res;
        unordered_set<int> del(to_delete.begin(), to_delete.end());
        dfs(root, del, res);
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    TreeNode *root;
    LeetCodeIO::scan(cin, root);
    vector<int> to_delete;
    LeetCodeIO::scan(cin, to_delete);

    Solution *obj = new Solution();

    auto res = obj->delNodes(root, to_delete);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
