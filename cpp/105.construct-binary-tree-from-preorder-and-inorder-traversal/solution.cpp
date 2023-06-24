/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode *get_root(vector<int> &preorder, int pre_l, int pre_r, vector<int> &inorder, int in_l, int in_r) {
        if (pre_l >= pre_r)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[pre_l]);
        int i = in_l;
        while (i < in_r) {
            if (inorder[i] == root->val)
                break;
            i++;
        }
        root->left = get_root(preorder, pre_l + 1, pre_l + 1 + i - in_l, inorder, in_l, i);
        root->right = get_root(preorder, pre_r + i + 1 - in_r, pre_r, inorder, i + 1, in_r);
        return root;
    }

  public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return get_root(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};
// @lc code=end
