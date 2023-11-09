// Created by zwyyy456 at 2023/11/03 17:01
// leetgo: 1.3.8
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
  public:
    Node *connect(Node *root) {
        queue<Node *> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            auto st = q.front();
            q.pop();
            q.push(st->left);
            q.push(st->right);
            for (int i = 1; i < sz; ++i) {
                st->next = q.front();
                q.pop();
                st = st->next;
                if (st->left != nullptr) {
                    q.push(st->left);
                }
                if (st->right != nullptr) {
                    q.push(st->right);
                }
            }
            return root;
        }
    }
};

// @lc code=end

// Warning: this is a manual question, the generated test code may be incorrect.
int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    TreeNode *root;
    LeetCodeIO::scan(cin, root);

    Solution *obj = new Solution();
    auto res = obj->connect(root);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
