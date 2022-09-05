/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    bool isValidBST(TreeNode *root) {
        if (root->left != nullptr && root->right != nullptr) {
            if (root->left->left == nullptr && root->left->right == nullptr && root->right->left == nullptr && root->right->right == nullptr)
                if ((root->left->val < root->val) && (root->right->val > root->val))
                    return true;
        }
        if (root->left == nullptr && root->right != nullptr) {
            if (root->right->left == nullptr && root->right->right == nullptr) {
                if (root->right->val > root->val)
                    return true;
            }
        }
        if (root->left != nullptr && root->right == nullptr) {
            if (root->left->left == nullptr && root->left->right == nullptr) {
                if (root->left->val < root->val)
                    return true;
            }
        }
        bool l = isValidBST(root->left);
        bool r = isValidBST(root->right);
        return l && r;
    }
};
// @lc code=end
