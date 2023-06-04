// Created by zwyyy456 at 2023/05/22 09:13
// https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths/

/*
1080. Insufficient Nodes in Root to Leaf Paths (Medium)
Given the `root` of a binary tree and an integer `limit`, delete all **insufficient nodes** in the
tree simultaneously, and return the root of the resulting binary tree.

A node is **insufficient** if every root to **leaf** path intersecting this node has a sum strictly
less than `limit`.

A **leaf** is a node with no children.

**Example 1:**

![](https://assets.leetcode.com/uploads/2019/06/05/insufficient-11.png)

```
Input: root = [1,2,3,4,-99,-99,7,8,9,-99,-99,12,13,-99,14], limit = 1
Output: [1,2,3,4,null,null,7,8,9,null,14]

```

**Example 2:**

![](https://assets.leetcode.com/uploads/2019/06/05/insufficient-3.png)

```
Input: root = [5,4,8,11,null,17,4,7,1,null,null,5,3], limit = 22
Output: [5,4,8,11,null,17,4,7,null,null,null,5]

```

**Example 3:**

![](https://assets.leetcode.com/uploads/2019/06/11/screen-shot-2019-06-11-at-83301-pm.png)

```
Input: root = [1,2,-3,-5,null,4,null], limit = -1
Output: [1,null,-3,4]

```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 5000]`.
- `-10⁵ <= Node.val <= 10⁵`
- `-10⁹ <= limit <= 10⁹`

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    bool dfs(int limit, TreeNode *root, int sum) {
        if (root->left == nullptr && root->right == nullptr) {
            return sum + root->val < limit;
        }
        if (root->left != nullptr && root->right == nullptr) {
            bool flag = dfs(limit, root->left, sum + root->val);
            if (flag) {
                delete root->left;
                root->left = nullptr;
            }
            return flag;
        }
        if (root->left == nullptr && root->right != nullptr) {
            bool flag = dfs(limit, root->right, sum + root->val);
            if (flag) {
                delete root->right;
                root->right = nullptr;
            }
            return flag;
        }
        bool left = dfs(limit, root->left, sum + root->val);
        bool right = dfs(limit, root->right, sum + root->val);
        if (left) {
            delete root->left;
            root->left = nullptr;
        }
        if (right) {
            delete root->right;
            root->right = nullptr;
        }
        return left && right;
    }
    TreeNode *sufficientSubset(TreeNode *root, int limit) {
        dfs(limit, root, 0);
        return root;
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
