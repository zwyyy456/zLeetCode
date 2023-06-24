/*
 * @lc app=leetcode id=669 lang=cpp
 *
 * [669] Trim a Binary Search Tree
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
  private:
    TreeNode *find_root(TreeNode *root, int low, int high) {
        while (root != nullptr && (root->val > high || root->val < low)) {
            if (root->val > high)
                root = root->left;
            else if (root->val < low)
                root = root->right;
        }
        return root;
    }

  public:
    TreeNode *trimBST(TreeNode *root, int low, int high) {
        TreeNode *res = find_root(root, low, high);
        TreeNode *node = res;
        TreeNode *pre = node;
        while (node != nullptr && node->val != high) {
            if (node->val < high) {
                pre = node;
                node = node->right;
            } else if (node->val > high) {
                node = node->left;
                pre->right = node;
            }
        }
        if (node != nullptr)
            node->right = nullptr;
        node = res;
        pre = node;
        while (node != nullptr && node->val != low) {
            if (node->val < low) {
                node = node->right;
                pre->left = node;
            } else if (node->val > low) {
                pre = node;
                node = node->left;
            }
        }
        if (node != nullptr)
            node->left = nullptr;
        return res;
    }
};
// @lc code=end
