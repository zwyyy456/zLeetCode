// Created by zwyyy456 at 2023/03/14 09:53
// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

/*
1976. Number of Ways to Arrive at Destination (Medium)

You are in a city that consists of `n` intersections numbered from `0` to `n - 1` with
**bi-directional** roads between some intersections. The inputs are generated such that you can
reach any intersection from any other intersection and that there is at most one road between any
two intersections.

You are given an integer `n` and a 2D integer array `roads` where `roads[i] = [uᵢ, vᵢ, timeᵢ]` means
that there is a road between intersections `uᵢ` and `vᵢ` that takes `timeᵢ` minutes to travel. You
want to know in how many ways you can travel from intersection `0` to intersection `n - 1` in the
**shortest amount of time**.

Return the **number of ways** you can arrive at your destination in the **shortest amount of time**.
Since the answer may be large, return it **modulo** `10⁹ + 7`.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/07/17/graph2.png)

```
Input: n = 7, roads =
[[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
Output: 4
Explanation: The shortest amount of time it takes to go from intersection 0 to intersection 6 is 7
minutes.
The four ways to get there in 7 minutes are:
- 0 ➝ 6
- 0 ➝ 4 ➝ 6
- 0 ➝ 1 ➝ 2 ➝ 5 ➝ 6
- 0 ➝ 1 ➝ 3 ➝ 5 ➝ 6

```

**Example 2:**

```
Input: n = 2, roads = [[1,0,10]]
Output: 1
Explanation: There is only one way to go from intersection 0 to intersection 1, and it takes 10
minutes.

```

**Constraints:**

- `1 <= n <= 200`
- `n - 1 <= roads.length <= n * (n - 1) / 2`
- `roads[i].length == 3`
- `0 <= uᵢ, vᵢ <= n - 1`
- `1 <= timeᵢ <= 10⁹`
- `uᵢ != vᵢ`
- There is at most one road connecting any two intersections.
- You can reach any intersection from any other intersection.
*/

// @lc code=begin
#include <vector>
#include <queue>
#include <utility>
using std::pair;
using std::vector;
using std::priority_queue;
class Solution {
  public:
    int mod = 1000000007;
    void Dijkstra(vector<vector<vector<int>>> &graph, vector<long> &dis, int start_idx, vector<int> &is_min) {
        auto cmp = [&](pair<int, long> &p1, pair<int, long> &p2) {
            return p1.second > p2.second;
        };
        priority_queue<pair<int, long>, vector<pair<int, long>>, decltype(cmp)> pq(cmp);
        pq.push({start_idx, 0});
        while (!pq.empty()) {
            auto [idx, len] = pq.top();
            pq.pop();
            if (is_min[idx] == 1) {
                continue;
            }
            dis[idx] = len;  // 更新最短路
            is_min[idx] = 1; // 已找到最短路
            for (auto &vec : graph[idx]) {
                if (is_min[vec[0]] == 0) {
                    pq.push({vec[0], len + vec[1]});
                }
            }
        }
    }
    int dfs(vector<int> &used, vector<vector<vector<int>>> &graph, int idx, vector<long> &disn, vector<int> &cach) {
        if (idx == 0) {
            return 1;
        }
        if (cach[idx] != -1) {
            return cach[idx];
        }
        int res = 0;
        for (auto &vec : graph[idx]) {
            // 这个条件判断是关键，第一个表示下一个点也是最短的（可以忽略），第二个表示不会走回路，第三个表示每次走最短路径
            // if (dis0[vec[0]] + disn[vec[0]] == disn[0] && dis0[idx] > dis0[vec[0]] && vec[1] + disn[idx] == disn[vec[0]]) {
            if (vec[1] + disn[idx] == disn[vec[0]]) {
                res = (res + dfs(used, graph, vec[0], disn, cach)) % mod;
            }
        }
        cach[idx] = res;
        return cach[idx];
    }
    int countPaths(int n, vector<vector<int>> &roads) {
        vector<vector<vector<int>>> graph(n);
        for (auto &road : roads) {
            graph[road[0]].push_back({road[1], road[2]});
            graph[road[1]].push_back({road[0], road[2]});
        }
        // vector<long> dis0(n); // 用于存储从0开始的最短路径
        // vector<int> is_min0(n);
        vector<long> disn(n);   // 用于存储从n - 1开始的最短路径
        vector<int> is_minn(n); // 表示是否已经找到最短路径
        // Dijkstra(graph, dis0, 0, is_min0);
        Dijkstra(graph, disn, n - 1, is_minn);
        vector<int> used(n);
        vector<int> cach(n, -1);
        return dfs(used, graph, n - 1, disn, cach);
    }
};

// @lc code=end
