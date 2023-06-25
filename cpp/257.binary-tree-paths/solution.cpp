/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
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
#include <string>
using std::vector;
using std::string;
class Solution {
  private:
    void Traversal(TreeNode *cur, vector<int> &path, vector<string> &res) {
        path.push_back(cur->val);
        if (cur->left == nullptr && cur->right == nullptr) {
            string sPath;
            for (int i = 0; i < path.size() - 1; i++) {
                sPath += std::to_string(path[i]);
                sPath += "->";
            }
            sPath += to_string(path[path.size() - 1]);
            result.push_back(sPath);
            return;
        }
        if (cur->left != nullptr) {
            Traversal(cur->left, path, res);
            path.pop_back();
        }
        if (cur->right != nullptr) {
            Traversal(cur->right, path, res);
            path.pop_back();
        }
    }

  public:
    vector<string> binaryTreePaths(TreeNode *root) {
    }
};
// @lc code=end
