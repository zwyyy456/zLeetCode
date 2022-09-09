/*
 * @lc app=leetcode id=701 lang=cpp
 *
 * [701] Insert into a Binary Search Tree
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
    TreeNode *insertIntoBST(TreeNode *root, int val) {
        TreeNode *cur = root;
        TreeNode *pre;
        while (cur != nullptr) {
            pre = cur;
            if (val > cur->val)
                cur = cur->right;
            if (val < cur->val)
                cur = cur->left;
        }
        TreeNode *res = new TreeNode(val);
        if (val > pre->val) {
            
            pre->right = res;
        }
        if (val < pre->val) {
            
            pre->left = res;
        }
        return root;
    }
};
// @lc code=end
