/*
 * @lc app=leetcode id=538 lang=cpp
 *
 * [538] Convert BST to Greater Tree
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
    int sum = 0;
    void sum_tree(TreeNode *root) {
        if (root == nullptr)
            return;
        sum_tree(root->right);
        sum += root->val;
        root->val = sum;
        sum_tree(root->left);
        return;
    }

  public:
    TreeNode *convertBST(TreeNode *root) {
        sum_tree(root);
        return root;
    }
};
// @lc code=end
