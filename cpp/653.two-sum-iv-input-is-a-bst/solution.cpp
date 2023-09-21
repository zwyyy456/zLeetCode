// Created by zwyyy456 at 2023/09/18 10:25
// leetgo: 1.3.8
// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    bool findTarget(TreeNode *root, int k) {
        return midtra(root, k, root);
    }
    bool findx(TreeNode *cur, int target, TreeNode *root) {
        while (root != nullptr) {
            if (target < root->val) {
                root = root->left;
            } else if (target > root->val) {
                root = root->right;
            } else {
                return root != cur;
            }
        }
        return false;
    }
    bool midtra(TreeNode *cur, int k, TreeNode *root) {
        if (cur == nullptr) {
            return false;
        }
        bool res = false;
        res = res || midtra(cur->left, k, root);
        if (k > root->val) {
            res = res || findx(cur, k - root->val, root);
        }
        res = res || midtra(cur->right, k, root);
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    TreeNode *root;
    LeetCodeIO::scan(cin, root);
    int k;
    LeetCodeIO::scan(cin, k);

    Solution *obj = new Solution();
    auto res = obj->findTarget(root, k);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
