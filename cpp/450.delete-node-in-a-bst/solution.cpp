// Created by zwyyy456 at 2023/09/02 11:17
// leetgo: 1.3.1
// https://leetcode.com/problems/delete-node-in-a-bst/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    TreeNode *deleteNode(TreeNode *root, int key) {
        // 递归处理
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else {
            if (root->right != nullptr) {
                TreeNode *tmp = root->right;
                TreeNode *pre = tmp;
                while (tmp->left != nullptr) {
                    pre = tmp;
                    tmp = tmp->left;
                }
                swap(root->val, tmp->val);
                pre->left = tmp->right;
                delete (tmp);
            } else {
                TreeNode *res = root->left;
                delete (root);
                return res;
            }
        }
        return root;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    TreeNode *root;
    LeetCodeIO::scan(cin, root);
    int key;
    LeetCodeIO::scan(cin, key);

    Solution *obj = new Solution();

    auto res = obj->deleteNode(root, key);

    LeetCodeIO::print(out_stream, res);
    cout << "
        output : " << out_stream.rdbuf() << endl;

                 delete obj;
    return 0;
}
