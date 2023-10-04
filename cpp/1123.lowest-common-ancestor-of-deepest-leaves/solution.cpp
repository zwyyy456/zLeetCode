// Created by zwyyy456 at 2023/09/06 09:00
// leetgo: 1.3.8
// https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/

#include <bits/stdc++.h>
#include <unordered_map>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    using ump = unordered_map<TreeNode *, int>;
    using pti = pair<TreeNode *, int>;
    pti dfs(TreeNode *root) {
        if (root == nullptr) {
            return {root, 0};
        }
        auto [lptr, ldep] = dfs(root->left);
        auto [rptr, rdep] = dfs(root->right);
        if (ldep == rdep) {
            return {root, 1 + ldep};
        } else if (ldep > rdep) {
            return {root->left, ldep + 1};
        } else {
            return {root->right, rdep + 1};
        }
    }
    TreeNode *lcaDeepestLeaves(TreeNode *root) {
        // 有左子结点和右子结点的结点
        // 包含原树中所有最深叶子结点的最近公共祖先
        return dfs(root).first;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    TreeNode *root;
    LeetCodeIO::scan(cin, root);

    Solution *obj = new Solution();
    auto res = obj->lcaDeepestLeaves(root);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
