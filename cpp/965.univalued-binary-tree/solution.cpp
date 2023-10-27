// Created by zwyyy456 at 2023/10/24 09:25
// leetgo: 1.3.8
// https://leetcode.com/problems/univalued-binary-tree/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    bool dfs(TreeNode *root, int val) {
        if (root == nullptr) {
            return true;
        }
        if (root->val == val) {
            return dfs(root->left, val) && dfs(root->right, val);
        }
        return false;
    }
    bool isUnivalTree(TreeNode *root) {
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
    auto res = obj->isUnivalTree(root);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
