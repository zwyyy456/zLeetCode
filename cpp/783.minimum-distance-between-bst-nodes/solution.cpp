// Created by zwyyy456 at 2023/09/04 17:20
// leetgo: 1.3.1
// https://leetcode.com/problems/minimum-distance-between-bst-nodes/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    const int mmax = 0x3f3f3f3f;
    int minDiffInBST(TreeNode *root) {
        TreeNode *pre = new TreeNode(-0x3f3f3f);
        return dfs(root, pre);
    }
    int dfs(TreeNode *root, TreeNode *pre) {
        if (root == nullptr) {
            return mmax;
        }
        int res = mmax;
        res = min(res, dfs(root->left, pre));
        res = min(res, root->val - pre->val);
        pre = root;
        res = min(res, dfs(root->right, pre));
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

    auto res = obj->minDiffInBST(root);

    LeetCodeIO::print(out_stream, res);
    cout << "
        output : " << out_stream.rdbuf() << endl;

                 delete obj;
    return 0;
}
