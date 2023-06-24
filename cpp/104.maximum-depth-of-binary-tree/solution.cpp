/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
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
using std::queue;
// class Solution {
//   public:
//     int maxDepth(TreeNode *root) {
//         int dp = 0;
//         queue<TreeNode *> q;
//         if (root == nullptr)
//             return dp;
//         q.push(root);
//         while (!q.empty()) {
//             int sz = q.size();
//             for (int i = 0; i < sz; i++) {
//                 TreeNode *node = q.front();
//                 q.pop();
//                 if (node->left != nullptr)
//                     q.push(node->left);
//                 if (node->right != nullptr)
//                     q.push(node->right);
//             }
//             dp++;
//         }
//         return dp;
//     }
// };

class Solution {
  public:
    int dp = 0;
    int maxDepth(TreeNode *root) {
        return getDp(root);
    }
    int getDp(TreeNode *root) {
        if (root == nullptr)
            return 0;
        int l = getDp(root->left);
        int r = getDp(root->right);
        return (l < r ? r : l) + 1;
    }
};
// @lc code=end
