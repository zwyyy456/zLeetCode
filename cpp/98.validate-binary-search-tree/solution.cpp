/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
using std::stack;
class Solution {
  public:
    bool isValidBST(TreeNode *root) {
        TreeNode *pre = nullptr; // 用来记录前一个节点
        TreeNode *cur = root;
        stack<TreeNode *> stk;
        if (root == nullptr)
            return true;
        stk.push(cur);
        while (cur != nullptr || !stk.empty()) {
            if (cur != nullptr) {
                stk.push(cur);
                cur = cur->left;
            } else {
                cur = stk.top();
                stk.pop();
                if (pre != nullptr && pre->val >= cur->val)
                    return false;
                pre = cur;
                cur = cur->right;
            }
        }
    }
};

// @lc code=end
