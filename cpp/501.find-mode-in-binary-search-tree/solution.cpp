/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
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
class Solution {
  private:
    int cnt = 0;
    TreeNode *pre = nullptr;
    void traverse(TreeNode *root, vector<int> &res) {
        if (root == nullptr)
            return;
        traverse(root->left, res);
        if (pre != nullptr) {
            if (root->val == pre->val) {
                cnt++;
            } else {
                if (res.empty()) {
                    res.push_back(pre->val);
                    res.push_back(cnt);
                    cnt = 0;
                } else {
                    if (cnt == res[res.size() - 1]) {
                        res.push_back(pre->val);
                        res.push_back(cnt);
                        cnt = 0;
                    } else if (cnt > res[res.size() - 1]) {
                        while (!res.empty())
                            res.pop_back();
                        res.push_back(pre->val);
                        res.push_back(cnt);
                        cnt = 0;
                    } else
                        cnt = 0;
                }
            }
        }
        pre = root;
        traverse(root->right, res);

        return;
    }

  public:
    vector<int> findMode(TreeNode *root) {
        vector<int> res;
        traverse(root, res);
        if (!res.empty()) {
            if (cnt == res[res.size() - 1]) {
                res.push_back(pre->val);
                res.push_back(cnt);
                cnt = 0;
            } else if (cnt > res[res.size() - 1]) {
                while (!res.empty())
                    res.pop_back();
                res.push_back(pre->val);
                res.push_back(cnt);
                cnt = 0;
            }
        } else {
            res.push_back(pre->val);
            res.push_back(cnt);
            cnt = 0;
        }
        vector<int> result;
        for (int i = 0; i < res.size(); i = i + 2) {
            result.push_back(res[i]);
        }
        return result;
    }
};
// @lc code=end
