// Created by zwyyy456 at 2023/09/18 10:09
// leetgo: 1.3.8
// https://leetcode.com/problems/house-robber-iii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int rob(TreeNode *root) {
        return robb(root, 1);
    }
    int robb(TreeNode *root, int choose) {
        if (root == nullptr) {
            return 0;
        }
        if (choose == 0) {
            return robb(root->left, 1) + robb(root->right, 1);
        }
        int res1 = root->val;
        res1 += robb(root->left, 0) + robb(root->right, 0);
        int res2 = robb(root->left, 1) + robb(root->right, 1);
        return max(res1, res2);
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    TreeNode *root;
    LeetCodeIO::scan(cin, root);

    Solution *obj = new Solution();
    auto res = obj->rob(root);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
