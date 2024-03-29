/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
    bool compare(TreeNode *left, TreeNode *right) {
        // 首先排除空节点的情况
        if (left == NULL && right != NULL)
            return false;
        else if (left != NULL && right == NULL)
            return false;
        else if (left == NULL && right == NULL)
            return true;
        // 排除了空节点，再排除数值不相同的情况
        else if (left->val != right->val)
            return false;

        // 此时就是：左右节点都不为空，且数值相同的情况
        // 此时才做递归，做下一层的判断
        bool outside = compare(left->left, right->right); // 左子树：左、 右子树：右
        bool inside = compare(left->right, right->left);  // 左子树：右、 右子树：左
        bool isSame = outside && inside;                  // 左子树：中、 右子树：中 （逻辑处理）
        return isSame;
    }
    bool isSymmetric(TreeNode *root) {
        if (root == NULL)
            return true;
        return compare(root->left, root->right);
    }
};

// @lc code=end
