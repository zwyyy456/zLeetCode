/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
    int getDp(TreeNode *root) {
        if (root == nullptr)
            return 0;
        int ldp = getDp(root->left);
        int rdp = getDp(root->right);
        return (ldp < rdp ? rdp : ldp) + 1;
    }
    bool isBalanced(TreeNode *root) {
        if (root == nullptr)
            return true;

        int ldp = getDp(root->left);
        int rdp = getDp(root->right);
        if (ldp - rdp <= 1 && ldp - rdp >= -1) {
            bool l = isBalanced(root->left);
            bool r = isBalanced(root->right);
            return l && r;
        } else
            return false;
    }
};
// @lc code=end
