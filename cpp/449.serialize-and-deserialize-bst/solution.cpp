// Created by zwyyy456 at 2023/09/04 16:04
// leetgo: 1.3.1
// https://leetcode.com/problems/serialize-and-deserialize-bst/

#include <bits/stdc++.h>
#include <string>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Codec {
  public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        if (root == nullptr) {
            return ".";
        }
        string str = to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        int n = data.size();
        int l = 0;
        return deserialize(data, l, n);
    }

  private:
    TreeNode *deserialize(string &data, int &l, int r) {
        // 左闭右开
        if (l == r) {
            return nullptr;
        }
        if (data[l] == '.') {
            ++l;
            return nullptr;
        }
        int num = 0;
        for (; l < r; ++l) {
            if (data[l] == ',') {
                ++l;
                break;
            }
            num = num * 10 + data[l] - '0';
        }
        TreeNode *root = new TreeNode(num);
        root->left = deserialize(data, l, r);
        root->right = deserialize(data, l, r);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    TreeNode *root;
    LeetCodeIO::scan(cin, root);

    Solution *obj = new Solution();

    auto res = obj->CodecDriver(root);

    LeetCodeIO::print(out_stream, res);
    cout << "
        output : " << out_stream.rdbuf() << endl;

                 delete obj;
    return 0;
}
