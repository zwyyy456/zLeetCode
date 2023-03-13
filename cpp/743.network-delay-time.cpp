// Created by zwyyy456 at 2023/03/12 10:13
// https://leetcode.com/problems/network-delay-time/

/*
743. Network Delay Time (Medium)

You are given a network of `n` nodes, labeled from `1` to `n`. You are also given `times`, a list of
travel times as directed edges `times[i] = (uᵢ, vᵢ, wᵢ)`, where `uᵢ` is the source node, `vᵢ` is the
target node, and `wᵢ` is the time it takes for a signal to travel from source to target.

We will send a signal from a given node `k`. Return the **minimum** time it takes for all the
`n`nodes to receive the signal. If it is impossible for all the `n` nodes to receive the signal,
return `-1`.

**Example 1:**

![](https://assets.leetcode.com/uploads/2019/05/23/931_example_1.png)

```
Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2

```

**Example 2:**

```
Input: times = [[1,2,1]], n = 2, k = 1
Output: 1

```

**Example 3:**

```
Input: times = [[1,2,1]], n = 2, k = 2
Output: -1

```

**Constraints:**

- `1 <= k <= n <= 100`
- `1 <= times.length <= 6000`
- `times[i].length == 3`
- `1 <= uᵢ, vᵢ <= n`
- `uᵢ != vᵢ`
- `0 <= wᵢ <= 100`
- All the pairs `(uᵢ, vᵢ)` are **unique**. (i.e., no multiple edges.)
*/

// @lc code=begin
#include <vector>
#include <queue>
#include <utility>
using std::pair;
using std::vector;
using std::queue;
using std::priority_queue;
class Solution {
  public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k) {
        vector<vector<vector<int>>> graph(n + 1);
        for (auto &vec : times) {
            graph[vec[0]].push_back({vec[1], vec[2]}); // vec1表示目标节点,vec[2]表示距离
        }
        // Dijkstra算法
        vector<int> dis(n + 1, -1);    // 表示从k到各点的最短距离, -1表示这个点还没有到达
        vector<int> min_dis(n + 1, 0); //为0表示还没找到该该点的最短距离
        auto cmp = [&](pair<int, int> &p1, pair<int, int> &p2) {
            return p1.second > p2.second;
        };
        // 小顶堆，pair.first为点坐标，pair.second为时间
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        pq.push({k, 0});
        dis[k] = 0;
        while (!pq.empty()) {
            auto [idx, len] = pq.top();
            pq.pop();
            if (min_dis[idx] == 1) // 如果已经找到最短距离，直接进行下一次循环
                continue;
            dis[idx] = len;
            min_dis[idx] = 1;
            for (auto &v : graph[idx]) {
                if (min_dis[v[0]] == 0) {
                    pq.push({v[0], len + v[1]});
                }
            }
        }
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            if (min_dis[i] == 0) {
                return -1;
            }
            res = std::max(res, dis[i]);
        }
        return res;
    }
};

// @lc code=end
