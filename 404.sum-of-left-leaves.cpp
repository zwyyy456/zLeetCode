/*
 * @lc app=leetcode id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
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
    int get_sum(TreeNode *root, int sum) {
        if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr)
            sum += root->left->val;
        if (root->left == nullptr && root->right == nullptr)
            return sum;
        if (root->left != nullptr)
            sum = get_sum(root->left, sum);
        if (root->right != nullptr)
            sum = get_sum(root->right, sum);
        return sum;
    }

  public:
    int sumOfLeftLeaves(TreeNode *root) {
        return get_sum(root, 0);
    }
};
// @lc code=end
