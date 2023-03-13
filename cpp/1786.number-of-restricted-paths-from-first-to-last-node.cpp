// Created by zwyyy456 at 2023/03/13 10:19
// https://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node/

/*
1786. Number of Restricted Paths From First to Last Node (Medium)

There is an undirected weighted connected graph. You are given a positive integer `n` which denotes
that the graph has `n` nodes labeled from `1` to `n`, and an array `edges` where each `edges[i] =
[uᵢ, vᵢ, weightᵢ]` denotes that there is an edge between nodes `uᵢ` and `vᵢ` with weight equal to
`weightᵢ`.

A path from node `start` to node `end` is a sequence of nodes `[z₀, z₁,z₂, ..., zₖ]` such that `z₀ =
start` and `zₖ = end` and there is an edge between `zᵢ` and `zᵢ+₁` where `0 <= i <= k-1`.

The distance of a path is the sum of the weights on the edges of the path. Let
`distanceToLastNode(x)` denote the shortest distance of a path between node `n` and node `x`. A
**restricted path** is a path that also satisfies that `distanceToLastNode(zᵢ) >
distanceToLastNode(zᵢ+₁)` where `0 <= i <= k-1`.

Return the number of restricted paths from node `1`to node `n`. Since that number may be too large,
return it **modulo** `10⁹ + 7`.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/02/17/restricted_paths_ex1.png)

```
Input: n = 5, edges = [[1,2,3],[1,3,3],[2,3,1],[1,4,2],[5,2,2],[3,5,1],[5,4,10]]
Output: 3
Explanation: Each circle contains the node number in black and its distanceToLastNode value in blue.
The three restricted paths are:
1) 1 --> 2 --> 5
2) 1 --> 2 --> 3 --> 5
3) 1 --> 3 --> 5

```

**Example 2:**

![](https://assets.leetcode.com/uploads/2021/02/17/restricted_paths_ex22.png)

```
Input: n = 7, edges = [[1,3,1],[4,1,2],[7,3,4],[2,5,3],[5,6,1],[6,7,2],[7,5,3],[2,6,4]]
Output: 1
Explanation: Each circle contains the node number in black and its distanceToLastNode value in blue.
The only restricted path is 1 --> 3 --> 7.

```

**Constraints:**

- `1 <= n <= 2 * 10⁴`
- `n - 1 <= edges.length <= 4 * 10⁴`
- `edges[i].length == 3`
- `1 <= uᵢ, vᵢ <= n`
- `uᵢ != vᵢ`
- `1 <= weightᵢ <= 10⁵`
- There is at most one edge between any two nodes.
- There is at least one path between any two nodes.
*/

// @lc code=begin
#include <vector>
#include <queue>
#include <utility>
using std::pair;
using std::priority_queue;
using std::vector;
class Solution {
  public:
    int mod = 1000000007;
    void Dijkstra(vector<vector<vector<int>>> &graph, int n, vector<int> &dis, vector<int> &is_min) {
        auto cmp = [&](pair<int, int> &p1, pair<int, int> &p2) {
            return p1.second > p2.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        pq.push({n, 0});
        while (!pq.empty()) {
            auto [idx, len] = pq.top(); // vec[0]表示坐标，vec[1]表示距离
            // cout << idx << " " << len << endl;
            pq.pop();
            if (is_min[idx] == 1) { // 说明已经找到最短路
                continue;
            }
            is_min[idx] = 1;
            dis[idx] = len;
            for (auto &tmp : graph[idx]) { // 遍历已经找到最短路的这个点的相邻边
                if (is_min[tmp[0]] == 0) {
                    pq.push({tmp[0], len + tmp[1]});
                }
            }
        }
    }
    int dfs(int idx, vector<vector<vector<int>>> &graph, int n, vector<int> &dis, vector<int> &is_min, vector<int> &cach) {
        if (idx == n) {
            return 1;
        }
        if (cach[idx] != -1) {
            return cach[idx];
        }
        int res = 0;
        for (auto &vec : graph[idx]) {
            if (is_min[idx] == 1 && dis[idx] > dis[vec[0]]) {
                res = (res + dfs(vec[0], graph, n, dis, is_min, cach)) % mod;
            }
        }
        cach[idx] = res;
        return cach[idx];
    }
    int countRestrictedPaths(int n, vector<vector<int>> &edges) {
        vector<vector<vector<int>>> graph(n + 1);
        for (auto &vec : edges) {
            graph[vec[0]].push_back({vec[1], vec[2]});
            graph[vec[1]].push_back({vec[0], vec[2]});
        }
        vector<int> dis(n + 1);
        vector<int> is_min(n + 1);
        vector<int> cach(n + 1, -1);
        Dijkstra(graph, n, dis, is_min); // 找到最短路径
        return dfs(1, graph, n, dis, is_min, cach);
    }
};

// @lc code=end
