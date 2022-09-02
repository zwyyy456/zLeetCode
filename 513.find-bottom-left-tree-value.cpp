/*
 * @lc app=leetcode id=513 lang=cpp
 *
 * [513] Find Bottom Left Tree Value
 */

// @lc code=start
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
    int findBottomLeftValue(TreeNode *root) {
    }
    int getDp(TreeNode *root) {
        if (root == nullptr)
            return 0;
        int l = getDp(root->left);
        int r = getDp(root->right);
        if (l < r) {
            return r + 1;
        }
        else {
            return l + 1;
        }
    }
};
// @lc code=end
