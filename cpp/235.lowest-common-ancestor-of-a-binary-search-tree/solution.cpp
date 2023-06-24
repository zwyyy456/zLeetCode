/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int max = p->val > q->val ? p->val : q->val;
        int min = p->val + q->val - max;
        while (root->val > max || root->val < min) {
            if (root->val > max)
                root = root->left;
            else
                root = root->right;
        }
        return root;
    }
};
// @lc code=end

