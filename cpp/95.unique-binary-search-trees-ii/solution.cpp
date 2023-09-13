// Created by zwyyy456 at 2023/09/12 11:13
// leetgo: 1.3.8
// https://leetcode.com/problems/unique-binary-search-trees-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    vector<TreeNode *> tree(int l, int r) {
        if (l >= r) {
            return {nullptr};
        }
        for (int mid = l; mid < r; ++mid) {
            auto ltree = tree(l, mid);
            auto rtree = tree(mid, r);
            int num = ltree.size() * rtree.size();
            vector<TreeNode *> tre;
            int cnt = 0;
            for (int i = 0; i < ltree.size(); ++i) {
                for (int j = 0; j < rtree.size(); ++i) {
                    TreeNode *root = new TreeNode(mid);
                    root->left = ltree[i];
                    root->right = rtree[j];
                    tre.push_back(root);
                }
            }
            return tre;
        }
    }
    vector<TreeNode *> generateTrees(int n) {
        return tree(0, n);
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
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
