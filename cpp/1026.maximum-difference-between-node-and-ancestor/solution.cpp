// Created by zwyyy456 at 2023/04/21 12:41
// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/

/*
1026. Maximum Difference Between Node and Ancestor (Medium)
Given the `root` of a binary tree, find the maximum value `v` for which there exist **different**
nodes `a` and `b` where `v = |a.val - b.val|` and `a` is an ancestor of `b`.

A node `a` is an ancestor of `b` if either: any child of `a` is equal to `b` or any child of `a` is
an ancestor of `b`.

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/11/09/tmp-tree.jpg)

```
Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
Output: 7
Explanation: We have various ancestor-node differences, some of which are given below :
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2020/11/09/tmp-tree-1.jpg)

```
Input: root = [1,null,2,null,0,3]
Output: 3

```

**Constraints:**

- The number of nodes in the tree is in the range `[2, 5000]`.
- `0 <= Node.val <= 10⁵`

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
  public:
    int ans_ = 0;
    int maxAncestorDiff(TreeNode *root) {
        dfs(root);
        return ans_;
    }
    auto dfs(TreeNode *root) -> pair<int, int> {
        if (root == nullptr) {
            return {100001, -1};
        }
        int mn = root->val, mm = root->val;
        auto [left_mn, left_mm] = dfs(root->left);
        auto [right_mn, right_mm] = dfs(root->right);
        mn = min(mn, min(left_mn, right_mn));
        mm = max(mm, max(left_mm, right_mm));
        ans_ = max(ans_, max(root->val -mn, mm-root->val));
        return {mn, mm};
    }
};


// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    TreeNode *root;
    LeetCodeIO::scan(cin, root);

    Solution *obj = new Solution();

    auto res = obj->maxAncestorDiff(root);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
