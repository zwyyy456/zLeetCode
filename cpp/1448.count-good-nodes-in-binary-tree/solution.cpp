// Created by zwyyy456 at 2023/08/25 08:59
// leetgo: 1.3.5
// https://leetcode.com/problems/count-good-nodes-in-binary-tree/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int dfs(TreeNode *root, int val) {
        if (root == nullptr) {
            return 0;
        }
        int res = 0;
        if (root->val >= val) {
            res = 1;
            val = root->val;
        }
        return res + dfs(root->left, val) + dfs(root->right, val);
    }
    int goodNodes(TreeNode *root) {
        return dfs(root, root->val);
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    TreeNode *root;
    LeetCodeIO::scan(cin, root);

    Solution *obj = new Solution();
    auto res = obj->goodNodes(root);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
