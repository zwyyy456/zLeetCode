// Created by zwyyy456 at 2023/06/28 10:57
// leetgo: 1.3.1
// https://leetcode.com/problems/unique-binary-search-trees-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    vector<TreeNode *> dfs(int left, int right) {
        // 左闭右闭
        if (left > right) {
            return {nullptr};
        }
        vector<TreeNode *> ans;
        for (int k = left; k <= right; ++k) {
            vector<TreeNode *> ltree = dfs(left, k - 1);
            vector<TreeNode *> rtree = dfs(k + 1, right);
            for (int i = 0; i < ltree.size(); ++i) {
                for (int j = 0; j < rtree.size(); ++j) {
                    TreeNode *node = new TreeNode(k);
                    node->left = ltree[i];
                    node->right = rtree[j];
                    ans.push_back(node); 
                }
            }
        }
        return ans;
    }
    vector<TreeNode *> generateTrees(int n) {

        return dfs(1, n);
    }
};
// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int n;
    LeetCodeIO::scan(cin, n);

    Solution *obj = new Solution();

    auto res = obj->generateTrees(n);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
