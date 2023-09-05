// Created by zwyyy456 at 2023/09/03 10:04
// leetgo: 1.3.1
// https://leetcode.com/problems/find-duplicate-subtrees/

#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    using ump = unordered_map<string, int>;
    using umpt = unordered_map<string, TreeNode *>;
    string serialize(TreeNode *root, unordered_map<string, int> &strs, umpt &nodes) {
        string str;
        if (root == nullptr) {
            str += ".";
            ++strs[str];
            nodes[str] = root;
            return str;
        }
        str = to_string(root->val) + "," + serialize(root->left, strs, nodes) + serialize(root->right, strs, nodes);
        ++strs[str];
        nodes[str] = root;
        return str;
    }
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
        // 序列化
        unordered_map<string, int> strs;
        umpt nodes;
        serialize(root, strs, nodes);
        vector<TreeNode *> res;
        for (auto [str, cnt] : strs) {
            if (cnt > 1 && str != ".") {
                res.push_back(nodes[str]);
            }
        }
        return res;
        // 然后对哈希表中次数大于 > 1 的字符串进行反序列化
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    TreeNode *root;
    LeetCodeIO::scan(cin, root);

    Solution *obj = new Solution();

    auto res = obj->findDuplicateSubtrees(root);

    LeetCodeIO::print(out_stream, res);
    cout << "
        output : " << out_stream.rdbuf() << endl;

                 delete obj;
    return 0;
}
