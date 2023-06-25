/*
 * @lc app=leetcode id=559 lang=cpp
 *
 * [559] Maximum Depth of N-ary Tree
 */

// @lc code=start
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
#include <queue>
using std::queue;
class Solution {
public:
    int maxDepth(Node* root) {
        int dp = 0;
        queue<Node *> q;
        if (root == nullptr)
            return 0;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                Node *node = q.front();
                q.pop();
                for (int j = 0; j < node->children.size(); j++) {
                    if (node->children[j] != nullptr)
                        q.push(node->children[j]);
                }
            }
            dp++;
        }
        return dp;
    }
};
// @lc code=end

