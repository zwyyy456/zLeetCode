/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
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
#include <vector>
using std::vector;
class Solution {
  private:
    vector<int> res;
    //int sum = 0;

  public:
    void cnt_sum(TreeNode *root, int sum) {
        if (root->left == nullptr && root->right == nullptr) {
            sum += root->val;
            res.push_back(sum);
            return;
        }
        sum += root->val;
        if (root->left != nullptr) {
            cnt_sum(root->left, sum);
            //sum -= root->left->val;
        }
        if (root->right != nullptr) {
            cnt_sum(root->right, sum);
            //sum -= root->right->val;
        }
        return;
    }
    bool hasPathSum(TreeNode *root, int targetSum) {
        if (root == nullptr)
            return false;
        cnt_sum(root, 0);
        for (int i = 0; i < res.size(); i++)
            if (res[i] == targetSum)
                return true;
        return false;
    }
};
// @lc code=end
