// Created by zwyyy456 at 2023/09/21 11:38
// leetgo: 1.3.8
// https://leetcode.com/problems/binary-tree-maximum-path-sum/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    using pii = pair<int, int>;
    int getsum(TreeNode *root, int &ans) {
        if (root == nullptr) {
            return 0;
        }
        int l1 = getsum(root->left, ans);
        int l2 = getsum(root->right, ans);
        ans = max(ans, l1 + l2 + root->val);
        return max(max(root->val + l1, root->val + l2), 0);
    }
    int maxPathSum(TreeNode *root) {
        int ans = -1e8;
        getsum(root, ans);
        return ans;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    TreeNode *root;
    LeetCodeIO::scan(cin, root);

    Solution *obj = new Solution();
    auto res = obj->maxPathSum(root);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
