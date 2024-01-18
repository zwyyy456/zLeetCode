// Created by zwyyy456 at 2023/12/11 16:22
// leetgo: 1.3.8
// https://leetcode.com/problems/maximum-binary-tree/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    TreeNode *dfs(vector<int> &nums, int l, int r) {
        // 左闭右闭
        if (l > r) {
            return nullptr;
        }
        if (l == r) {
            return new TreeNode(nums[l]);
        }
        int mx = nums[l], mxid = l;
        for (int i = l + 1; i <= r; ++i) {
            if (nums[i] > mx) {
                mx = nums[i];
                mxid = i;
            }
        }
        auto node = new TreeNode(mx);
        node->left = dfs(nums, l, mxid - 1);
        node->right = dfs(nums, mxid + 1, r);
        return node;
    }
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        return dfs(nums, 0, nums.size() - 1);
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> nums;
    LeetCodeIO::scan(cin, nums);

    Solution *obj = new Solution();
    auto res = obj->constructMaximumBinaryTree(nums);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
