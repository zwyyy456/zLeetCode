/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
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
    TreeNode *deleteNode(TreeNode *root, int key) {
        if (root == nullptr)
            return root;
        TreeNode *node = root;
        TreeNode *pre = root;
        while (node != nullptr && node->val != key) {
            pre = node;
            if (key < node->val)
                node = node->left;
            else if (key > node->val)
                node = node->right;
        }
        if (node == nullptr)
            return root;
        else {
            TreeNode *tmp = nullptr;
            if (node->right != nullptr) {
                tmp = node->right;
                TreeNode *tmp_l = tmp->left;
                TreeNode *tmp_pre = tmp;
                while (tmp_l != nullptr) {
                    tmp_pre = tmp_l;
                    tmp_l = tmp_l->left;
                }
                tmp_pre->left = node->left;
            } else if (node->left != nullptr) {
                tmp = node->left;
                TreeNode *tmp_r = tmp->right;
                TreeNode *tmp_pre = tmp;
                while (tmp_r != nullptr) {
                    tmp_pre = tmp_r;
                    tmp_r = tmp_r->right;
                }
                tmp_pre->right = node->right;
            }
            if (key < pre->val) {
                pre->left = tmp;
            } else if (key > pre->val) {
                pre->right = tmp;
            } else {
                root = tmp;
            }
            return root;
        }
    }
};
// @lc code=end
