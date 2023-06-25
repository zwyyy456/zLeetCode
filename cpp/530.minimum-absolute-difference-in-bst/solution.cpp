/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
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
    int min_dif = 0;
    TreeNode *pre = nullptr;

  public:
    int getMinimumDifference(TreeNode *root) {
        if (root == nullptr)
            return -1;
        int l = getMinimumDifference(root->left);
        if (pre != nullptr) {
            if (min_dif == 0)
                min_dif = root->val - pre->val;
            else
                min_dif = min_dif < root->val - pre->val ? min_dif : root->val - pre->val;
        }
        pre = root;
        int r = getMinimumDifference(root->right);
        return min_dif;
    }
};
// @lc code=end
