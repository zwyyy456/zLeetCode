/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */

// 后序遍历
class Solution {
  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == q || root == p || root == nullptr)
            return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (left != nullptr && right != nullptr)
            return root;
        if (left == nullptr && right != nullptr)
            return right;
        else if (left != nullptr && right == nullptr)
            return left;
        else { //  (left == nullptr && right == nullptr)
            return nullptr;
        }
    }
};

// @lc code=end
