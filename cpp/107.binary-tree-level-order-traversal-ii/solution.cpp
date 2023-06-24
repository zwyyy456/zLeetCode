/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
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
#include <queue>
#include <algorithm>
#include <vector>
using std::queue;
using std::vector;

class Solution {
  public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        queue<TreeNode *> q;
        vector<vector<int>> res;
        int depth = 0;
        if (root != nullptr)
            q.push(root);
        while (!q.empty()) {
            vector<int> temp;
            int size = q.size();
            // 如何识别节点在同一层？利用queue的size()来进行处理。
            for (int i = 0; i < size; i++) {
                TreeNode *node = q.front();
                q.pop();
                temp.push_back(node->val);
                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);
            }
            res.push_back(temp);
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
