// Created by zwyyy456 at 2023/09/05 09:33
// leetgo: 1.3.1
// https://leetcode.com/problems/longest-univalue-path/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int pathlen(TreeNode *root, int &res) {
        if (root == nullptr) {
            return 0;
        }
        int lcnt = pathlen(root->left, res);
        int rcnt = pathlen(root->right, res);
        if (root->left != nullptr && root->val == root->left->val) {
            res = max(res, 1 + lcnt);
        }
        if (root->right != nullptr && root->val == root->right->val) {
            res = max(res, 1 + rcnt);
        }
        return 1 + max(lcnt, rcnt);
    }
    int longestUnivaluePath(TreeNode *root) {
        int res = 0;
        int tmp = pathlen(root, res);
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

    auto res = obj->longestUnivaluePath(root);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
