// Created by zwyyy456 at 2023/05/20 18:31
// https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/

/*
1373. Maximum Sum BST in Binary Tree (Hard)
Given a **binary tree** `root`, return the maximum sum of all keys of **any** sub-tree which is also
a Binary Search Tree (BST).

Assume a BST is defined as follows:

- The left subtree of a node contains only nodes with keys **less than** the node's key.
- The right subtree of a node contains only nodes with keys **greater than** the node's key.
- Both the left and right subtrees must also be binary search trees.

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/01/30/sample_1_1709.png)

```
Input: root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
Output: 20
Explanation: Maximum sum in a valid Binary search tree is obtained in root node with key equal to 3.

```

**Example 2:**

![](https://assets.leetcode.com/uploads/2020/01/30/sample_2_1709.png)

```
Input: root = [4,3,null,1,2]
Output: 2
Explanation: Maximum sum in a valid Binary search tree is obtained in a single root node with key
equal to 2.

```

**Example 3:**

```
Input: root = [-4,-2,-5]
Output: 0
Explanation: All values are negatives. Return an empty BST.

```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 4 * 10⁴]`.
- `-4 * 10⁴ <= Node.val <= 4 * 10⁴`

*/

#include <bits/stdc++.h>
#include <unordered_map>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    tuple<bool, int, int, int, bool> dfs(TreeNode *root, int &sums) {
        if (root == nullptr) {
            return {true, 0, 0, 0, true}; // flag, sum, min, max
        }
        auto [flag1, sum1, min1, max1, empty1] = dfs(root->left, sums);
        auto [flag2, sum2, min2, max2, empty2] = dfs(root->right, sums);
        if (flag1 && flag2 && (empty1 || root->val > max1) && (empty2 || root->val < min2)) {
            sums = max(sums, root->val + sum1 + sum2);
            if (!empty1 && !empty2) {
                return {true, sum1 + sum2 + root->val, min1, max2, false};
            }
            if (empty1 && empty2) {
                return {true, sum1 + sum2 + root->val, root->val, root->val, false};
            }
            if (!empty1 && empty2) {
                return {true, sum1 + sum2 + root->val, min1, root->val, false};
            }
            if (empty1 && !empty2) {
                return {true, sum1 + sum2 + root->val, root->val, max2, false};
            }
        }
        return {false, max(sum1, sum2), 0, 0, false};
    }
    int maxSumBST(TreeNode *root) {
        // unordered_map<int, int> sums;
        int sums = 0;
        // key 对应的 bst 的和。
        dfs(root, sums);
        return sums;
    }
};
// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    TreeNode *root;
    LeetCodeIO::scan(cin, root);

    Solution *obj = new Solution();

    auto res = obj->maxSumBST(root);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
