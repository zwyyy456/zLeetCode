// Created by zwyyy456 at 2023/09/11 14:12
// leetgo: 1.3.8
// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    TreeNode *dfs(vector<int> &nums, int l, int r) {
        if (l == r) {
            return nullptr;
        }
        int mid = l + (r - l) / 2;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = dfs(nums, l, mid);
        node->right = dfs(nums, mid + 1, r);
        return node;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return dfs(nums, 0, nums.size()); // 左闭右开
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> nums;
    LeetCodeIO::scan(cin, nums);

    Solution *obj = new Solution();
    auto res = obj->sortedArrayToBST(nums);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
