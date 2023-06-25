/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
#include <algorithm>
#include <stack>
#include <vector>
using std::stack;
using std::vector;
class Solution {
  public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> st;
        if (root == nullptr)
            return res;
        st.push(root);
        while (!st.empty()) {
            TreeNode *cur = st.top();
            st.pop();
            res.push_back(cur->val);
            if (cur->left != nullptr)
                st.push(cur->left);
            if (cur->right != nullptr)
                st.push(cur->right);
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
