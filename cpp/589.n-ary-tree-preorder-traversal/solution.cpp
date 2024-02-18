// Created by zwyyy456 at 2024/02/18 12:25
// leetgo: 1.4.1
// https://leetcode.com/problems/n-ary-tree-preorder-traversal/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
  public:
    void solve(Node *root, vector<int> &res) {
        res.push_back(root->val);
        for (auto *ptr : root->children) {
            solve(ptr, res);
        }
        return res;
    }
    vector<int> preorder(Node *root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        solve(root, res);
        return res;
    }
};

// @lc code=end

// Warning: this is a manual question, the generated test code may be incorrect.
int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int root;
    LeetCodeIO::scan(cin, root);

    Solution *obj = new Solution();
    auto res = obj->preorder(root);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
