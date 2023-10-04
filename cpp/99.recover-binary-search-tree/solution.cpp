// Created by zwyyy456 at 2023/09/08 09:12
// leetgo: 1.3.8
// https://leetcode.com/problems/recover-binary-search-tree/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    void midtra(TreeNode *root, TreeNode **prev, vector<TreeNode *> &wrong) {
        if (root == nullptr) {
            return;
        }
        midtra(root->left, prev, wrong);
        if (*prev != nullptr) {
            if (root->val < (*prev)->val) {
                wrong.push_back(*prev);
                wrong.push_back(root);
            }
        }
        *prev = root;
        midtra(root->right, prev, wrong);
    }
    void recoverTree(TreeNode *root) {
        // 中序遍历
        vector<TreeNode *> wrong;
        TreeNode *node = nullptr;
        midtra(root, &node, wrong);
        swap(wrong[0]->val, wrong.back()->val);
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    TreeNode *root;
    LeetCodeIO::scan(cin, root);

    Solution *obj = new Solution();
    auto res = obj->recoverTree(root);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
