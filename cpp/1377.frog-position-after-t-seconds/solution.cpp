// Created by zwyyy456 at 2023/05/26 10:05
// https://leetcode.com/problems/frog-position-after-t-seconds/

/*
1377. Frog Position After T Seconds (Hard)
Given an undirected tree consisting of `n` vertices numbered from `1` to `n`. A frog starts jumping
from **vertex 1**. In one second, the frog jumps from its current vertex to another **unvisited**
vertex if they are directly connected. The frog can not jump back to a visited vertex. In case the
frog can jump to several vertices, it jumps randomly to one of them with the same probability.
Otherwise, when the frog can not jump to any unvisited vertex, it jumps forever on the same vertex.

The edges of the undirected tree are given in the array `edges`, where `edges[i] = [aᵢ, bᵢ]` means
that exists an edge connecting the vertices `aᵢ` and `bᵢ`.

Return the probability that after `t` seconds the frog is on the vertex `target`. Answers within `10-
⁵` of the actual answer will be accepted.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/12/21/frog1.jpg)

```
Input: n = 7, edges = [[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]], t = 2, target = 4
Output: 0.16666666666666666
Explanation: The figure above shows the given graph. The frog starts at vertex 1, jumping with 1/3
probability to the vertex 2 after second 1 and then jumping with 1/2 probability to vertex 4 after
second 2. Thus the probability for the frog is on the vertex 4 after 2 seconds is 1/3 * 1/2 = 1/6 =
0.16666666666666666.

```

**Example 2:**

 **![](https://assets.leetcode.com/uploads/2021/12/21/frog2.jpg)**

```
Input: n = 7, edges = [[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]], t = 1, target = 7
Output: 0.3333333333333333
Explanation: The figure above shows the given graph. The frog starts at vertex 1, jumping with 1/3 =
0.3333333333333333 probability to the vertex 7 after second 1.

```

**Constraints:**

- `1 <= n <= 100`
- `edges.length == n - 1`
- `edges[i].length == 2`
- `1 <= aᵢ, bᵢ <= n`
- `1 <= t <= 50`
- `1 <= target <= n`

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    double dfs(vector<vector<int>> &graph, int n, int t, int target, vector<bool> &vis, int pos) {
        if (t == 0) {
            if (pos == target) {
                return 1;
            }
            return 0;
        }
        int num = 0;
        for (auto idx : graph[pos]) {
            if (!vis[idx]) {
                ++num;
            }
        }
        if (num == 0) {
            if (pos == target) {
                return 1;
            }
            return 0;
        }
        double res = 0;
        for (auto idx : graph[pos]) {
            if (vis[idx]) {
                continue;
            }
            vis[idx] = true;
            res += dfs(graph, n, t - 1, target, vis, idx) / num;
            vis[idx] = false;
        }
        return res;
    }
    double frogPosition(int n, vector<vector<int>> &edges, int t, int target) {
        vector<vector<int>> graph(n + 1);
        for (auto &edge : edges) {
            int x = edge[0], y = edge[1];
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        vector<bool> vis(n + 1);
        vis[1] = true;
        return dfs(graph, n, t, target, vis, 1);
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int n;
    LeetCodeIO::scan(cin, n);
    vector<vector<int>> edges;
    LeetCodeIO::scan(cin, edges);
    int t;
    LeetCodeIO::scan(cin, t);
    int target;
    LeetCodeIO::scan(cin, target);

    Solution *obj = new Solution();

    auto res = obj->frogPosition(n, edges, t, target);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
