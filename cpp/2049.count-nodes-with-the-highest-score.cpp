// Created by zwyyy456 at 2023/04/15 12:45
// https://leetcode.com/problems/count-nodes-with-the-highest-score/

/*
2049. Count Nodes With the Highest Score (Medium)

There is a **binary** tree rooted at `0` consisting of `n` nodes. The nodes are labeled from `0` to
`n - 1`. You are given a **0-indexed** integer array `parents` representing the tree, where
`parents[i]` is the parent of node `i`. Since node `0` is the root, `parents[0] == -1`.

Each node has a **score**. To find the score of a node, consider if the node and the edges connected
to it were **removed**. The tree would become one or more **non-empty** subtrees. The **size** of a
subtree is the number of the nodes in it. The **score** of the node is the **product of the sizes**
of all those subtrees.

Return the **number** of nodes that have the **highest score**.

**Example 1:**

![example-1](https://assets.leetcode.com/uploads/2021/10/03/example-1.png)

```
Input: parents = [-1,2,0,2,0]
Output: 3
Explanation:
- The score of node 0 is: 3 * 1 = 3
- The score of node 1 is: 4 = 4
- The score of node 2 is: 1 * 1 * 2 = 2
- The score of node 3 is: 4 = 4
- The score of node 4 is: 4 = 4
The highest score is 4, and three nodes (node 1, node 3, and node 4) have the highest score.

```

**Example 2:**

![example-2](https://assets.leetcode.com/uploads/2021/10/03/example-2.png)

```
Input: parents = [-1,2,0]
Output: 2
Explanation:
- The score of node 0 is: 2 = 2
- The score of node 1 is: 2 = 2
- The score of node 2 is: 1 * 1 = 1
The highest score is 2, and two nodes (node 0 and node 1) have the highest score.

```

**Constraints:**

- `n == parents.length`
- `2 <= n <= 10⁵`
- `parents[0] == -1`
- `0 <= parents[i] <= n - 1` for `i != 0`
- `parents` represents a valid binary tree.
*/

// @lc code=begin
#include <unordered_map>
#include <vector>
using std::vector;
class Solution {
  public:
    int dfs(vector<vector<int>> &tree, vector<int> &cnt, int idx) {
        if (cnt[idx] != -1) {
            return cnt[idx];
        }
        if (tree[idx].empty()) {
            cnt[idx] = 1;
            return cnt[idx];
        }
        int tmp = 0;
        for (int i = 0; i < tree[idx].size(); ++i) {
            tmp += dfs(tree, cnt, tree[idx][i]);
        }
        cnt[idx] = tmp;
        return cnt[idx];
    }
    int countHighestScoreNodes(vector<int> &parents) {
        int n = parents.size();
        vector<vector<int>> tree(n);
        for (int i = 1; i < n; ++i) {
            tree[parents[i]].push_back(i);
        }
        vector<int> cnt(n, -1);
        dfs(tree, cnt, 0);
        std::unordered_map<int, int> res;
        int num = 1;
        for (int i = 0; i < n; ++i) {
            int tmp = cnt[0] - cnt[i];
            if (tmp != 0) {
                num *= tmp;
            }
            for (auto j : tree[i]) {
                tmp = cnt[j];
                num *= tmp;
            }
            ++res[num];
        }
        int max_num = 0, ans = 0;
        for (auto &count : res) {
            if (count.first > max_num) {
                max_num = count.first;
                ans = count.second;
            }
        }
        return ans;
    }
};

// @lc code=end
