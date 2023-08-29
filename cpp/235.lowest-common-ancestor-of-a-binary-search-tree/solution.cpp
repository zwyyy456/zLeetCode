// Created by zwyyy456 at 2023/08/25 09:29
// leetgo: 1.3.5
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        // 左子结点是 p 所在子树的根结点;
        // 右子结点是 q 所在子树的根结点;
        if (root == p || root == q || root == nullptr) {
            return root;
        }
        root->left = lowestCommonAncestor(root->left, p, q);
        root->right = lowestCommonAncestor(root->right, p, q);
        if (root->left != nullptr && root->right != nullptr) {
            return root;
        }
        if (root->left) {
            return root->left;
        }
        if (root->right != nullptr) {
            return root->right;
        }
        return nullptr;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    TreeNode *root;
    LeetCodeIO::scan(cin, root);
    int p;
    LeetCodeIO::scan(cin, p);
    int q;
    LeetCodeIO::scan(cin, q);

    Solution *obj = new Solution();
    auto res = obj->lowestCommonAncestor(root, p, q);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
