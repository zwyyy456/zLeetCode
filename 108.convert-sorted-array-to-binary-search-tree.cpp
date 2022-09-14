/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
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
    TreeNode *build_tree(vector<int> &nums, int l, int r) {
        if (l >= r)
            return nullptr;
        TreeNode *root = new TreeNode(nums[(l + r) / 2]);
        root->left = build_tree(nums, l, (l + r) / 2);
        root->right = build_tree(nums, (l + r) / 2 + 1, r);
        return root;
    }

  public:
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return build_tree(nums, 0, nums.size());
    }
};
// @lc code=end
