/*
 * @lc app=leetcode id=654 lang=cpp
 *
 * [654] Maximum Binary Tree
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
    int getMax(vector<int> &nums, int l, int r) {
        int m_index = l;
        for (int i = l; i < r; i++) {
            if (nums[i] >= nums[m_index])
                m_index = i;
        }
        return m_index;
    }
    TreeNode *build_tree(vector<int> &nums, int l, int r) {
        if (l == r)
            return nullptr;
        int mid = getMax(nums, l, r);
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = build_tree(nums, l, mid);
        root->right = build_tree(nums, mid + 1, r);
        return root;
    }

  public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        return build_tree(nums, 0, nums.size());
        }
};
// @lc code=end
