/*
 * @lc app=leetcode id=513 lang=cpp
 *
 * [513] Find Bottom Left Tree Value
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
//二叉树层序遍历

#include <queue>
#include <vector>
using std::queue;
using std::vector;

class Solution {
  public:
    int findBottomLeftValue(TreeNode *root) {
        queue<TreeNode *> q;
        vector<int> res;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            res.push_back(q.front()->val);
            for (int i = 0; i < sz; i++) {
                TreeNode *node = q.front();
                q.pop();
                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);
            }
        }
        return res[res.size() - 1];
    }
};
// @lc code=end
