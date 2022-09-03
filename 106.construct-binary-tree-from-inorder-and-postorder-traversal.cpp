/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
/* 最直接的版本，递归创建了vecotr，耗时耗空间
class Solution {
  public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // TreeNode *node = new TreeNode;
        return get_root(inorder, postorder);
    }
    TreeNode *get_root(vector<int> &inorder, vector<int> &postorder) {
        if (postorder.size() == 0)
            return nullptr;
        TreeNode *root = new TreeNode(postorder[postorder.size() - 1]);
        // root->val = postorder[postorder.size() - 1];
        int i = 0;
        while (i < inorder.size()) {
            if (root->val == inorder[i])
                break;
            i++;
        }
        //中序遍历的左半部分
        vector<int> l_inorder(inorder.begin(), inorder.begin() + i);
        vector<int> r_inorder(inorder.begin() + i + 1, inorder.end());
        vector<int> l_postorder(postorder.begin(), postorder.begin() + i);
        vector<int> r_postorder(postorder.begin() + i, postorder.end() - 1);
        root->left = get_root(l_inorder, l_postorder);
        //中序遍历切出来的右半部分
        root->right = get_root(r_inorder, r_postorder);
        return root;
    }
}; */

// 利用vector索引的优化版本
class Solution {
  private:
    TreeNode *get_root(vector<int> &inorder, vector<int> &postorder, int in_l, int in_r, int p_l, int p_r) {
        if (p_l >= p_r)
            return nullptr;
        TreeNode *root = new TreeNode(postorder[p_r - 1]);
        int i = 0;
        while (i < in_r) {
            if (root->val == inorder[i])
                break;
            i++;
        }
        //注意这里p_r应该赋什么值，应该根据inorder与postorder长度相等而得出
        root->left = get_root(inorder, postorder, in_l, i, p_l, p_l + i - in_l);
        // 注意这里p_l的值也一样
        root->right = get_root(inorder, postorder, i + 1, in_r, p_r + i - in_r, p_r - 1);
        return root;
    }

  public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return get_root(inorder, postorder, 0, inorder.size(), 0, postorder.size());
    }
};
// @lc code=end
