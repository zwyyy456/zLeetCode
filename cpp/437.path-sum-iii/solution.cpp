// Created by zwyyy456 at 2023/06/09 06:55
// https://leetcode.com/problems/path-sum-iii/

/*
437. Path Sum III (Medium)
Given the `root` of a binary tree and an integer `targetSum`, return the number of paths where the
sum of the values along the path equals `targetSum`.

The path does not need to start or end at the root or a leaf, but it must go downwards (i.e.,
traveling only from parent nodes to child nodes).

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/04/09/pathsum3-1-tree.jpg)

```
Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
Output: 3
Explanation: The paths that sum to 8 are shown.

```

**Example 2:**

```
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: 3

```

**Constraints:**

- The number of nodes in the tree is in the range `[0, 1000]`.
- `-10⁹ <= Node.val <= 10⁹`
- `-1000 <= targetSum <= 1000`

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    pair<int, int> dfs(TreeNode *root, int target) {
        // first 表示以 root 为根的路径数量，second 表示不以 root 为根的路径数量
        if (root == nullptr) {
            return {0, 0};
        }
        int num = 0;
        if (target == root->val) {
            num = 1;
        }
        auto [lwr, lnwr] = dfs(root->left, target);
        auto [rwr, rnwr] = dfs(root->right, target);
        auto [lwr1, lnwr1] = dfs(root->left, target - root->val);
        auto [rwr1, rnwr1] = dfs(root->right, target - root->val);
        return {num + lnwr1 + rnwr1, lwr + rwr + lnwr + rnwr};
    }
    int pathSum(TreeNode *root, int targetSum) {
        // if (root == nullptr) {
        // 	return 0;
        // }
        // int left_num = pathSum(root->left, targetSum);
        // int right_num = pathSum(root->right, targetSum);
        auto [num1, num2] = dfs(root, targetSum);
        return num1 + num2;
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
