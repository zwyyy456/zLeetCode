// Created by zwyyy456 at 2023/06/12 09:05
// https://leetcode.com/problems/kth-ancestor-of-a-tree-node/

/*
1483. Kth Ancestor of a Tree Node (Hard)
You are given a tree with `n` nodes numbered from `0` to `n - 1` in the form of a parent array
`parent` where `parent[i]` is the parent of `ith` node. The root of the tree is node `0`. Find the
`kth` ancestor of a given node.

The `kth` ancestor of a tree node is the `kth` node in the path from that node to the root node.

Implement the `TreeAncestor` class:

- `TreeAncestor(int n, int[] parent)` Initializes the object with the number of nodes in the tree and
the parent array.
- `int getKthAncestor(int node, int k)` return the `kth` ancestor of the given node `node`. If there
is no such ancestor, return `-1`.

**Example 1:**

![](https://assets.leetcode.com/uploads/2019/08/28/1528_ex1.png)

```
Input
["TreeAncestor", "getKthAncestor", "getKthAncestor", "getKthAncestor"]
[[7, [-1, 0, 0, 1, 1, 2, 2]], [3, 1], [5, 2], [6, 3]]
Output
[null, 1, 0, -1]

Explanation
TreeAncestor treeAncestor = new TreeAncestor(7, [-1, 0, 0, 1, 1, 2, 2]);
treeAncestor.getKthAncestor(3, 1); // returns 1 which is the parent of 3
treeAncestor.getKthAncestor(5, 2); // returns 0 which is the grandparent of 5
treeAncestor.getKthAncestor(6, 3); // returns -1 because there is no such ancestor
```

**Constraints:**

- `1 <= k <= n <= 5 * 10⁴`
- `parent.length == n`
- `parent[0] == -1`
- `0 <= parent[i] < n` for all `0 < i < n`
- `0 <= node < n`
- There will be at most `5 * 10⁴` queries.

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class TreeAncestor {
  public:
    TreeAncestor(int n, vector<int> &parent) :
        cnt_(n), index_(0), dp(n) {
        int x = 0;
        for (int i = 0; i < parent.size(); ++i) {
            parent_.push_back(parent[i]);
        }
        for (int i = 0; i < cnt_; ++i) {
            for (int j = 0; j < logk; ++j) {
                dp[i].push_back(-1);
            }
        }
        for (int i = 0; i < cnt_; ++i) {
            dp[i][0] = parent_[i];
        }
        while (index_ < logk) {
            for (int i = 0; i < cnt_; ++i) {
                if (dp[i][index_] != -1) {
                    dp[i][index_ + 1] = dp[dp[i][index_]][index_];
                }
            }
            x *= 2;
            ++index_;
        }
    }
    int getKthAncestor(int node, int k) {
        // dp[node][i] 表示出 node 的第 2^i 个祖先
        // dp[node][i] = dp[dp[node][i - 1]][i - 1];
        int pa = node;
        for (int i = 0; (1 << i) <= k; ++i) {
            if (((1 << i) & k) != 0) {
                pa = dp[pa][i];
                if (pa == -1) {
                    return pa;
                }
            }
        }
        return pa;
    }

  private:
    int cnt_;
    vector<int> parent_;
    int index_;
    vector<vector<int>> dp;
    const int logk = 20;
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<string> method_names;
    LeetCodeIO::scan(cin, method_names);

    TreeAncestor *obj;

    const unordered_map<string, function<void()>> methods = {
        {"TreeAncestor", [&]() {
             int n;
             LeetCodeIO::scan(cin, n);
             cin.ignore();
             vector<int> parent;
             LeetCodeIO::scan(cin, parent);
             cin.ignore();
             obj = new TreeAncestor(n, parent);
             out_stream << "null,";
         }},
        {"getKthAncestor", [&]() {
             int node;
             LeetCodeIO::scan(cin, node);
             cin.ignore();
             int k;
             LeetCodeIO::scan(cin, k);
             cin.ignore();
             LeetCodeIO::print(out_stream, obj->getKthAncestor(node, k));
             out_stream << ',';
         }},
    };
    out_stream << '[';
    for (auto &&method_name : method_names) {
        cin.ignore(2);
        methods.at(method_name)();
    }
    cin.ignore();
    out_stream.seekp(-1, ios_base::end);
    out_stream << ']';

    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
