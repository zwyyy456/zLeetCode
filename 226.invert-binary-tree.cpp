/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
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

#include <queue>
using std::queue;
//层序遍历，翻转
class Solution {
  public:
    TreeNode *invertTree(TreeNode *root) {
        traverse(root);
        return root;
    }
    void traverse(TreeNode *root) {
        if (root == nullptr)
            return;
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        traverse(root->left);
        traverse(root->right);
    }
};
// @lc code=end
