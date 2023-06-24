/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
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
#include <math.h>
class Solution {
  public:
    int getDp(TreeNode *root) {
        if (root == nullptr)
            return 0;
        int ldp = getDp(root->left);
        int rdp = getDp(root->right);
        return ((ldp < rdp ? rdp : ldp) + 1);
    }
    int countNodes(TreeNode *root) {
        if (root == nullptr)
            return 0;
        int lc, rc;
        if (getDp(root->left) == getDp(root->right)) {
            lc = pow(2, getDp(root->left)) - 1;
            rc = countNodes(root->right);
        } else {
            lc = countNodes(root->left);
            rc = pow(2, getDp(root->right)) - 1;
        }
        return lc + rc + 1;

        // int lc = countNodes(root->left);
        // int rc = countNodes(root->right);
    }
};
// @lc code=end
