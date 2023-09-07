// Created by zwyyy456 at 2023/09/04 17:05
// leetgo: 1.3.1
// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int kthSmallest(TreeNode *root, int k) {
        int res = 0;
        int cnt = 0;
        midfs(root, k, res, cnt);
        return res;
    }
    void midfs(TreeNode *root, int k, int &res, int &cnt) {
        if (root == nullptr) {
            return;
        }
        midfs(root->left, k, res, cnt);
        ++cnt;
        if (cnt == k) {
            res = root->val;
            return;
        }
        midfs(root->right, k, res, cnt);
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

    auto res = obj->kthSmallest(root, k);

    LeetCodeIO::print(out_stream, res);
    cout << "
        output : " << out_stream.rdbuf() << endl;

                 delete obj;
    return 0;
}
