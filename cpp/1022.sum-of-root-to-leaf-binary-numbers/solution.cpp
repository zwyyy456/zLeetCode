// Created by zwyyy456 at 2023/09/05 09:21
// leetgo: 1.3.1
// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    void getsum(TreeNode *root, int &total, int num) {
        if (root != nullptr && root->left == nullptr && root->right == nullptr) {
            num = num * 2 + root->val;
            total += num;
            return;
        }
        num = num * 2 + root->val;
        if (root->left != nullptr) {
            getsum(root->left, total, num);
        }
        if (root->right != nullptr) {
            getsum(root->right, total, num);
        }
    }
    int sumRootToLeaf(TreeNode *root) {
        // 前序遍历
        int total = 0;
        getsum(root, total, 0);
        return total;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    TreeNode *root;
    LeetCodeIO::scan(cin, root);

    Solution *obj = new Solution();

    auto res = obj->sumRootToLeaf(root);

    LeetCodeIO::print(out_stream, res);
    cout << "
        output : " << out_stream.rdbuf() << endl;

                 delete obj;
    return 0;
}
