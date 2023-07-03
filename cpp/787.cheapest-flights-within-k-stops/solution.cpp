// Created by zwyyy456 at 2023/03/12 14:59
// https://leetcode.com/problems/cheapest-flights-within-k-stops/

/*
787. Cheapest Flights Within K Stops (Medium)

There are `n` cities connected by some number of flights. You are given an array `flights` where
`flights[i] = [fromᵢ, toᵢ, priceᵢ]` indicates that there is a flight from city `fromᵢ` to city `toᵢ`
with cost `priceᵢ`.

You are also given three integers `src`, `dst`, and `k`, return **the cheapest price** from  `src`
to  `dst` with at most  `k` stops. If there is no such route, return `-1`.

**Example 1:**

![](https://assets.leetcode.com/uploads/2022/03/18/cheapest-flights-within-k-stops-3drawio.png)

```
Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.

```

**Example 2:**

![](https://assets.leetcode.com/uploads/2022/03/18/cheapest-flights-within-k-stops-1drawio.png)

```
Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.

```

**Example 3:**

![](https://assets.leetcode.com/uploads/2022/03/18/cheapest-flights-within-k-stops-2drawio.png)

```
Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
Output: 500
Explanation:
The graph is shown above.
The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.

```

**Constraints:**

- `1 <= n <= 100`
- `0 <= flights.length <= (n * (n - 1) / 2)`
- `flights[i].length == 3`
- `0 <= fromᵢ, toᵢ < n`
- `fromᵢ != toᵢ`
- `1 <= priceᵢ <= 10⁴`
- There will not be any multiple flights between two cities.
- `0 <= src, dst, k < n`
- `src != dst`
*/

// @lc code=begin
#include <vector>
using std::vector;
class Solution {
  public:
    const int ubd = 20000000;
    int dfs(int cnt, vector<vector<vector<int>>> &graph, int src, int dst, int k, vector<vector<int>> &cach) {
        if (cnt > k + 1) {
            return ubd;
        }
        if (src == dst) {
            return 0;
        }
        if (cach[cnt][src] >= 0) {
            return cach[cnt][src];
        }
        int res = ubd;
        for (auto &vec : graph[src]) {
            res = std::min(res, vec[1] + dfs(cnt + 1, graph, vec[0], dst, k, cach));
        }
        cach[cnt][src] = res;
        return cach[cnt][src];
    }
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k) {
        vector<vector<vector<int>>> graph(n + 1);
        for (auto &time : flights) {
            graph[time[0]].push_back({time[1], time[2]});
            // graph[time[1]].push_back({time[0], time[2]});
        }
        vector<vector<int>> cach(k + 3, vector<int>(n, -1));
        int res = dfs(0, graph, src, dst, k, cach);
        if (res >= ubd) {
            return -1;
        }
        return res;
    }
};

// @lc code=end
