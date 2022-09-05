/*
 * @lc app=leetcode id=700 lang=cpp
 *
 * [700] Search in a Binary Search Tree
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
    bool in_tree(TreeNode *root, int val, TreeNode **res) {
        if (root == nullptr)
            return false;
        if (root->val == val) {
            *res = root;
            return true;
        }
        bool in_l = in_tree(root->left, val, res);
        bool in_r = in_tree(root->right, val, res);
        return (in_l || in_r);
    }

  public:
    TreeNode *searchBST(TreeNode *root, int val) {
        TreeNode *root1 = new TreeNode;
        if (in_tree(root, val, &root1))
            return root1;
        else {
            delete root1;
            return nullptr;
        }
    }
};
// @lc code=end
