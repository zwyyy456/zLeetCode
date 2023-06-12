// Created by zwyyy456 at 2023/05/31 09:56
// https://leetcode.com/problems/minimize-the-total-price-of-the-trips/

/*
2646. Minimize the Total Price of the Trips (Hard)
There exists an undirected and unrooted tree with `n` nodes indexed from `0` to `n - 1`. You are
given the integer `n` and a 2D integer array `edges` of length `n - 1`, where `edges[i] = [aᵢ, bᵢ]`
indicates that there is an edge between nodes `aᵢ` and `bᵢ` in the tree.

Each node has an associated price. You are given an integer array `price`, where `price[i]` is the
price of the `ith` node.

The **price sum** of a given path is the sum of the prices of all nodes lying on that path.

Additionally, you are given a 2D integer array `trips`, where `trips[i] = [startᵢ, endᵢ]` indicates
that you start the `ith` trip from the node `startᵢ` and travel to the node `endᵢ` by any path you
like.

Before performing your first trip, you can choose some **non-adjacent** nodes and halve the prices.

Return the minimum total price sum to perform all the given trips.

**Example 1:**

![](https://assets.leetcode.com/uploads/2023/03/16/diagram2.png)

```
Input: n = 4, edges = [[0,1],[1,2],[1,3]], price = [2,2,10,6], trips = [[0,3],[2,1],[2,3]]
Output: 23
Explanation: The diagram above denotes the tree after rooting it at node 2. The first part shows the
initial tree and the second part shows the tree after choosing nodes 0, 2, and 3, and making their
price half.
For the 1st trip, we choose path [0,1,3]. The price sum of that path is 1 + 2 + 3 = 6.
For the 2ⁿd trip, we choose path [2,1]. The price sum of that path is 2 + 5 = 7.
For the 3rd trip, we choose path [2,1,3]. The price sum of that path is 5 + 2 + 3 = 10.
The total price sum of all trips is 6 + 7 + 10 = 23.
It can be proven, that 23 is the minimum answer that we can achieve.

```

**Example 2:**

![](https://assets.leetcode.com/uploads/2023/03/16/diagram3.png)

```
Input: n = 2, edges = [[0,1]], price = [2,2], trips = [[0,0]]
Output: 1
Explanation: The diagram above denotes the tree after rooting it at node 0. The first part shows the
initial tree and the second part shows the tree after choosing node 0, and making its price half.
For the 1st trip, we choose path [0]. The price sum of that path is 1.
The total price sum of all trips is 1. It can be proven, that 1 is the minimum answer that we can
achieve.

```

**Constraints:**

- `1 <= n <= 50`
- `edges.length == n - 1`
- `0 <= aᵢ, bᵢ <= n - 1`
- `edges` represents a valid tree.
- `price.length == n`
- `price[i]` is an even integer.
- `1 <= price[i] <= 1000`
- `1 <= trips.length <= 100`
- `0 <= startᵢ, endᵢ <= n - 1`

*/

#include <bits/stdc++.h>
#include <vector>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    // 寻找不重复路径
    void dfs(int cur, int end, vector<int> &path, vector<vector<int>> &graph, vector<bool> &vis, vector<vector<int>> &all_path) {
        if (cur == end) {
            all_path.push_back(path);
            return;
        }
        for (auto next : graph[cur]) {
            if (!vis[next]) {
                path.push_back(next);
                vis[next] = true;
                dfs(next, end, path, graph, vis, all_path);
                path.pop_back();
                vis[next] = false;
            }
        }
    }
    pair<int, int> GetRes(vector<vector<int>> &graph, vector<int> &times, int fa, int idx, vector<int> &price) {
        // 如何避免重复？
        int half = price[idx] * times[idx] / 2, not_half = price[idx] * times[idx];
        for (auto next : graph[idx]) {
            if (next == fa) {
                continue;
            }
            auto [sum_half, sum_not_half] = GetRes(graph, times, idx, next, price);
            half += sum_not_half; // next 不能减半了
            not_half += min(sum_half, sum_not_half);
        }
        return {half, not_half};
    }
    int minimumTotalPrice(int n, vector<vector<int>> &edges, vector<int> &price, vector<vector<int>> &trips) {
        // 统计每个结点的贡献，即每个结点会被经过多少次
        vector<int> times(n);
        vector<vector<int>> graph(n);
        for (int i = 0; i < edges.size(); ++i) {
            int x = edges[i][0], y = edges[i][1];
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        vector<vector<int>> all_path;
        for (auto &vec : trips) {
            int start = vec[0], end = vec[1];
            vector<bool> vis(n);
            vector<int> path;
            path.push_back(start);
            vis[start] = true;
            dfs(start, end, path, graph, vis, all_path);
        }
        for (const auto &path_ : all_path) {
            for (int idx : path_) {
                ++times[idx];
            }
        }
        auto [half, not_half] = GetRes(graph, times, 0, 0, price);
        return min(half, not_half);
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
    vector<int> price;
    LeetCodeIO::scan(cin, price);
    vector<vector<int>> trips;
    LeetCodeIO::scan(cin, trips);

    Solution *obj = new Solution();

    auto res = obj->minimumTotalPrice(n, edges, price, trips);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
