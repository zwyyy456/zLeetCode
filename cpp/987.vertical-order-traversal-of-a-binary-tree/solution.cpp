// Created by zwyyy456 at 2023/06/10 19:22
// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

/*
987. Vertical Order Traversal of a Binary Tree (Hard)
Given the `root` of a binary tree, calculate the **vertical order traversal** of the binary tree.

For each node at position `(row, col)`, its left and right children will be at positions `(row + 1,
col - 1)` and `(row + 1, col + 1)` respectively. The root of the tree is at `(0, 0)`.

The **vertical order traversal** of a binary tree is a list of top-to-bottom orderings for each column
index starting from the leftmost column and ending on the rightmost column. There may be multiple
nodes in the same row and same column. In such a case, sort these nodes by their values.

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

#include <bits/stdc++.h>
#include <vector>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    pair<int, int> dfs(TreeNode *root) {
        if (root == nullptr) {
            return {0, 0};
        }
        auto [llen_left, rlen_left] = dfs(root->left);
        auto [llen_right, rlen_right] = dfs(root->right);

        int llen = max(llen_left + 1, llen_right - 1);
        int rlen = max(rlen_left - 1, rlen_right + 1);
        return {llen, rlen};
    }
    void dfs_push(TreeNode *root, int idx, vector<vector<pair<int, int>>> &res, int h_idx) {
        if (root == nullptr) {
            return;
        }
        res[idx].push_back({h_idx, root->val});
        dfs_push(root->left, idx - 1, res, h_idx + 1);
        dfs_push(root->right, idx + 1, res, h_idx + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode *root) {
        auto [llen, rlen] = dfs(root);
        int n = llen + rlen - 1;
        int root_idx = llen - 1;
        vector<vector<pair<int, int>>> res(n);
        dfs_push(root, root_idx, res, 0);
        for (int i = 0; i < n; ++i) {
            sort(res[i].begin(), res[i].end());
        }
        vector<vector<int>> ans(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < res[i].size(); ++j) {
                ans[i].push_back(res[i][j].second);
            }
        }
        return ans;
    }
};
// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    TreeNode *root;
    LeetCodeIO::scan(cin, root);

    Solution *obj = new Solution();

    auto res = obj->verticalTraversal(root);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
