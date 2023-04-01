// Created by zwyyy456 at 2023/03/25 13:21
// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

/*
987. Vertical Order Traversal of a Binary Tree (Hard)

Given the `root` of a binary tree, calculate the **vertical order traversal** of the binary tree.

For each node at position `(row, col)`, its left and right children will be at positions `(row + 1,
col - 1)` and `(row + 1, col + 1)` respectively. The root of the tree is at `(0, 0)`.

The **vertical order traversal** of a binary tree is a list of top-to-bottom orderings for each
column index starting from the leftmost column and ending on the rightmost column. There may be
multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the **vertical order traversal** of the binary tree.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/01/29/vtree1.jpg)

```
Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation:
Column -1: Only node 9 is in this column.
Column 0: Nodes 3 and 15 are in this column in that order from top to bottom.
Column 1: Only node 20 is in this column.
Column 2: Only node 7 is in this column.
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2021/01/29/vtree2.jpg)

```
Input: root = [1,2,3,4,5,6,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation:
Column -2: Only node 4 is in this column.
Column -1: Only node 2 is in this column.
Column 0: Nodes 1, 5, and 6 are in this column.
          1 is at the top, so it comes first.
          5 and 6 are at the same position (2, 0), so we order them by their value, 5 before 6.
Column 1: Only node 3 is in this column.
Column 2: Only node 7 is in this column.

```

**Example 3:**

![](https://assets.leetcode.com/uploads/2021/01/29/vtree3.jpg)

```
Input: root = [1,2,3,4,6,5,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation:
This case is the exact same as example 2, but with nodes 5 and 6 swapped.
Note that the solution remains the same since 5 and 6 are in the same location and should be ordered
by their values.

```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 1000]`.
- `0 <= Node.val <= 1000`
*/

// @lc code=begin
#include <vector>
#include <queue>
#include <utility>
#include "TreeNode.h"
using std::vector;
using std::pair;
using std::queue;
class Solution {
public:
    int get_lcol(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        return std::max(get_lcol(root->left), get_lcol(root->right) - 2);
    }
    int get_rcol(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        return std::max(get_rcol(root->left) - 2, get_rcol(root->right));
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // 求列数
        int left = get_lcol(root), right = get_rcol(root);
        // 求行数
        queue<TreeNode *> tmp;
        tmp.push(root);
        int level = 0;
        while (!tmp.empty()) {
            int sz = tmp.size();
            for (int i = 0; i < sz; ++i) {
                auto node = tmp.front();
                tmp.pop();
                if (node->left != nullptr) {
                    tmp.push(node->left);
                }
                if (node->right != nullptr) {
                    tmp.push(node->right);
                }
            }
            level++;
        }
        int num = left + right + 1;
        vector<vector<vector<int>>> res(num, vector<vector<int>>(level - 1));
        // 层序遍历来填充
        queue<pair<TreeNode *, int>> q;
        q.push({root, left});
        // res[left].push_back(root->val);
        int lvl = 0;
        while (!q.empty()) {
            int siz = q.size();
            for (int i = 0; i < siz; ++i) {
                auto [node, idx] = q.front();
                q.pop();
                res[idx][lvl].push_back(node->val);
                if (node->left != nullptr) {
                    q.push({node->left, idx - 1});
                }
                if (node->right != nullptr) {
                    q.push({node->right, idx + 1});
                }
            }
        }
        vector<vector<int>> ans(num);
        for (int i = 0; i < num; ++i) {
            for (int j = 0; j < res[i].size(); ++j) {
                if (res[i][j].size() == 1) {
                    ans[i].push_back(res[i][j][0]);
                } else if (res[i][j].size() > 1) {
                    std::sort(res[i][j].begin(), res[i][j].end());
                    for (int k = 0; k < res[i][j].size(); ++k) {
                        ans[i].push_back(res[i][j][k]);
                    }
                }
            }
        }
        return ans;
    }
};

// @lc code=end
