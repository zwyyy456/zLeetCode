/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
#include <stack>
#include <vector>
using std::stack;
using std::vector;
class Solution {
  public:
    vector<int> preorderTraversal(TreeNode *root) {
        stack<TreeNode *> stk;
        vector<int> res;
        if (root == nullptr)
            return res;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode *node = stk.top();
            stk.pop();
            res.push_back(node->val);
            if (node->right != nullptr)
                stk.push(node->right);
            if (node->left != nullptr)
                stk.push(node->left);
        }
        return res;
    }
};
// @lc code=end
