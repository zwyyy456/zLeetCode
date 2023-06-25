/*
 * @lc app=leetcode id=1145 lang=cpp
 *
 * [1145] Binary Tree Coloring Game
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
  public:
    int get_num(TreeNode *root) { // 获取当前树的节点数
        if (root != nullptr)
            return get_num(root->left) + get_num(root->right) + 1;
        else
            return 0;
    }
    TreeNode *get_pos(int x, int n, TreeNode *root) { // 获取当前x对应的指针
        if (root == nullptr)
            return nullptr;
        else {
            if (root->val == x)
                return root;
            else {
                TreeNode *l = get_pos(x, n, root->left);
                TreeNode *r = get_pos(x, n, root->right);
                if (l != nullptr)
                    return l;
                else
                    return r;
            }
        }
    }
    bool btreeGameWinningMove(TreeNode *root, int n, int x) {
        // 先判断是不是完全树
        if (n == 1)
            return false;
        TreeNode *nodex = get_pos(x, n, root);
        int num_blue1 = n - get_num(nodex); // 表示占据父节点
        int num_blue2 = get_num(nodex->left); // 占据左子节点的节点数
        int num_blue3 = get_num(nodex->right); // 占据右子节点的节点数
        if (num_blue1 > n - num_blue1)
            return true;
        if (num_blue2 > n - num_blue2)
            return true;
        if (num_blue3 > n - num_blue3)
            return true;
        return false;
    }
};
// @lc code=end
