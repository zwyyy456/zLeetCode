// Created by Bob at 2023/06/09 08:05
// https://leetcode.cn/problems/path-sum-iii/

/*
437. 路径总和 III (Medium)
给定一个二叉树的根节点 `root` ，和一个整数 `targetSum` ，求
该二叉树里节点值之和等于 `targetSum` 的 **路径** 的数目。

**路径** 不需要从根节点开始，也不需要在叶子节点结束，但是路
径方向必须是向下的（只能从父节点到子节点）。

**示例 1：**

![](https://assets.leetcode.com/uploads/2021/04/09/pathsum3-
1-tree.jpg)

```
输入：root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum =
8
输出：3
解释：和等于 8 的路径有 3 条，如图所示。

```

**示例 2：**

```
输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetS
um = 22
输出：3

```

**提示:**

- 二叉树的节点个数的范围是 `[0,1000]`
- `-10⁹ <= Node.val <= 10⁹`
- `-1000 <= targetSum <= 1000`

*/

#include <bits/stdc++.h>
#include <unordered_map>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int RootSum(TreeNode *root, unordered_map<TreeNode *, int> &record, int target) {
        if (root == nullptr) {
            return 0;
        }
        if (record.find(root) != record.end()) {
            return record[root];
        }
        int res = root->val == target ? 1 : 0;
        res += RootSum(root->left, record, target - root->val);
        res += RootSum(root->right, record, target - root->val);
        record[root] = res;
        return res;
    }
    int pathSum(TreeNode *root, int targetSum) {
        unordered_map<TreeNode *, int> record;
        RootSum(root, record, targetSum);
        int res = 0;
        for (auto &tp : record) {
            res += tp.second;
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
    int targetSum;
    LeetCodeIO::scan(cin, targetSum);

    Solution *obj = new Solution();

    auto res = obj->pathSum(root, targetSum);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
