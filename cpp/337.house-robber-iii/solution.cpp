// Created by zwyyy456 at 2023/05/30 15:54
// https://leetcode.com/problems/house-robber-iii/

/*
337. House Robber III (Medium)
The thief has found himself a new place for his thievery again. There is only one entrance to this
area, called `root`.

Besides the `root`, each house has one and only one parent house. After a tour, the smart thief
realized that all houses in this place form a binary tree. It will automatically contact the police
if **two directly-linked houses were broken into on the same night**.

Given the `root` of the binary tree, return the maximum amount of money the thief can rob **without
alerting the police**.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/03/10/rob1-tree.jpg)

```
Input: root = [3,2,3,null,3,null,1]
Output: 7
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.

```

**Example 2:**

![](https://assets.leetcode.com/uploads/2021/03/10/rob2-tree.jpg)

```
Input: root = [3,4,5,1,3,null,1]
Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.

```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 10⁴]`.
- `0 <= Node.val <= 10⁴`

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int dfs(TreeNode *root, bool flag) {
        // flag 为 true 说明当前结点可以被打劫
        if (root == nullptr) {
            return 0;
        }
        int val1 = 0, val2 = 0;
        // 不打劫当前结点
        val1 = dfs(root->left, true) + dfs(root->right, true);
        if (flag) {
            // 打劫当前结点
            val2 = dfs(root->left, false) + dfs(root->right, false) + root->val;
        }
        return max(val1, val2);
    }
    int rob(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        return dfs(root, true);
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    TreeNode *root;
    LeetCodeIO::scan(cin, root);

    Solution *obj = new Solution();

    auto res = obj->rob(root);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
