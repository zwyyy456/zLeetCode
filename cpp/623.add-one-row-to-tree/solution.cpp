// Created by zwyyy456 at 2023/09/03 10:46
// leetgo: 1.3.1
// https://leetcode.com/problems/add-one-row-to-tree/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    TreeNode *addrow(TreeNode *root, int val, int cur_dep, int depth) {
        if (cur_dep + 1 == depth) {
            TreeNode *l = new TreeNode(val);
            TreeNode *r = new TreeNode(val);
            l->left = root->left;
            r->right = root->right;
            root->left = l;
            root->right = r;
            return root;
        }
        root->left = addrow(root->left, val, cur_dep + 1, depth);
        root->right = addrow(root->right, val, cur_dep + 1, depth);
        return root;
    }
    TreeNode *addOneRow(TreeNode *root, int val, int depth) {
        if (depth == 1) {
            TreeNode *cur_root = new TreeNode(val);
            cur_root->left = root;
            return cur_root;
        }
        int cur_dep = 1;
        return addrow(root, val, cur_dep, depth);
        // 层序遍历
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    TreeNode *root;
    LeetCodeIO::scan(cin, root);
    int val;
    LeetCodeIO::scan(cin, val);
    int depth;
    LeetCodeIO::scan(cin, depth);

    Solution *obj = new Solution();

    auto res = obj->addOneRow(root, val, depth);

    LeetCodeIO::print(out_stream, res);
    cout << "
        output : " << out_stream.rdbuf() << endl;

                 delete obj;
    return 0;
}
