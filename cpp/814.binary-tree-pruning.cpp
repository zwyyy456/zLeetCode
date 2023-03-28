// Created by zwyyy456 at 2023/03/24 09:13
// https://leetcode.com/problems/binary-tree-pruning/

/*
814. Binary Tree Pruning (Medium)

Given the `root` of a binary tree, return the same tree where every subtree (of the given tree) not
containing a  `1` has been removed.

A subtree of a node `node` is `node` plus every node that is a descendant of `node`.

**Example 1:**

![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/06/1028_2.png)

```
Input: root = [1,null,0,0,1]
Output: [1,null,0,null,1]
Explanation:
Only the red nodes satisfy the property "every subtree not containing a 1".
The diagram on the right represents the answer.

```

**Example 2:**

![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/06/1028_1.png)

```
Input: root = [1,0,1,0,0,0,1]
Output: [1,null,1,null,1]

```

**Example 3:**

![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/05/1028.png)

```
Input: root = [1,1,0,1,1,0,1,0]
Output: [1,1,0,1,1,null,1]

```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 200]`.
- `Node.val` is either `0` or `1`.
*/

// @lc code=begin
#include "TreeNode.h"
class Solution {
public:
    TreeNode *dfs(TreeNode *root) {
        if (root == nullptr) {
            return nullptr;
        }
        root->left = dfs(root->left);
        root->right = dfs(root->right);
        if (root->val == 0) {
            if (root->left == nullptr && root->right == nullptr) {
                return nullptr;
            }
            return root;
        }
        return root;
    }
    TreeNode* pruneTree(TreeNode* root) {
        return dfs(root); 
    }
};

// @lc code=end
