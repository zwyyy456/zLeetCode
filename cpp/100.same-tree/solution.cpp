/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        return cmp(p, q);
    }
    bool cmp(TreeNode *p, TreeNode *q) {
        if (p == nullptr && q == nullptr)
            return true;
        else if (p == nullptr && q != nullptr)
            return false;
        else if (p != nullptr && q == nullptr)
            return false;
        else if (p->val != q->val)
            return false;

        bool left_same = cmp(p->left, q->left);
        bool right_same = cmp(p->right, q->right);
        return left_same && right_same;
    }
};
// @lc code=end
