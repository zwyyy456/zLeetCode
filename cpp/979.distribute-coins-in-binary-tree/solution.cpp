// Created by zwyyy456 at 2023/07/14 20:26
// leetgo: 1.3.2
// https://leetcode.com/problems/distribute-coins-in-binary-tree/

#include <bits/stdc++.h>
#include <unordered_map>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int dfs_val(TreeNode *root, unordered_map<TreeNode *, int> &vals) {
        if (root == nullptr) {
            return 0;
        }
        vals[root] = root->val + dfs_val(root->left, vals) + dfs_val(root->right, vals);
        return vals[root];
    }
    int dfs_cnt(TreeNode *root, unordered_map<TreeNode *, int> &cnts) {
        if (root == nullptr) {
            return 0;
        }
        cnts[root] = 1 + dfs_cnt(root->left, cnts) + dfs_cnt(root->right, cnts);
        return cnts[root];
    }
    int dfs(TreeNode *root, unordered_map<TreeNode *, int> &vals, unordered_map<TreeNode *, int> &cnts) {
        if (root == nullptr) {
            return 0;
        }
        int res = 0;
        root->val = root->val + vals[root->left] - cnts[root->left] + vals[root->right] - cnts[root->right];
        res += abs(vals[root->left] - cnts[root->left]) + abs(vals[root->right] - cnts[root->right]);
        if (root->left) {
            root->left->val -= vals[root->left] - cnts[root->left];
            vals[root->left] = cnts[root->left];
        }
        if (root->right) {
            root->right->val -= vals[root->right] - cnts[root->right];
            vals[root->right] = cnts[root->right];
        }
        int left = dfs(root->left, vals, cnts);
        int right = dfs(root->right, vals, cnts);
        res += left + right;
        return res;
    }
    int distributeCoins(TreeNode *root) {
        unordered_map<TreeNode *, int> vals;
        unordered_map<TreeNode *, int> cnts;
        dfs_val(root, vals);
        dfs_cnt(root, cnts);
        int res = dfs(root, vals, cnts);
        return res;
    }
};
// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    TreeNode *root;
    LeetCodeIO::scan(cin, root);

    Solution *obj = new Solution();

    auto res = obj->distributeCoins(root);

    LeetCodeIO::print(out_stream, res);
    cout << "
        output : " << out_stream.rdbuf() << endl;

                 delete obj;
    return 0;
}
