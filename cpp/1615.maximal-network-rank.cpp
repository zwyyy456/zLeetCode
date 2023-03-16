// Created by zwyyy456 at 2023/03/15 09:30
// https://leetcode.com/problems/maximal-network-rank/

/*
1615. Maximal Network Rank (Medium)

There is an infrastructure of `n` cities with some number of `roads` connecting these cities. Each
`roads[i] = [aᵢ, bᵢ]` indicates that there is a bidirectional road between cities `aᵢ` and `bᵢ`.

The **network rank** of **two different cities** is defined as the total number of **directly**
connected roads to **either** city. If a road is directly connected to both cities, it is only
counted **once**.

The **maximal network rank** of the infrastructure is the **maximum network rank** of all pairs of
different cities.

Given the integer `n` and the array `roads`, return the **maximal network rank** of the entire
infrastructure.

**Example 1:**

**![](https://assets.leetcode.com/uploads/2020/09/21/ex1.png)**

```
Input: n = 4, roads = [[0,1],[0,3],[1,2],[1,3]]
Output: 4
Explanation: The network rank of cities 0 and 1 is 4 as there are 4 roads that are connected to
either 0 or 1. The road between 0 and 1 is only counted once.

```

**Example 2:**

**![](https://assets.leetcode.com/uploads/2020/09/21/ex2.png)**

```
Input: n = 5, roads = [[0,1],[0,3],[1,2],[1,3],[2,3],[2,4]]
Output: 5
Explanation: There are 5 roads that are connected to cities 1 or 2.

```

**Example 3:**

```
Input: n = 8, roads = [[0,1],[1,2],[2,3],[2,4],[5,6],[5,7]]
Output: 5
Explanation: The network rank of 2 and 5 is 5. Notice that all the cities do not have to be
connected.

```

**Constraints:**

- `2 <= n <= 100`
- `0 <= roads.length <= n * (n - 1) / 2`
- `roads[i].length == 2`
- `0 <= aᵢ, bᵢ <= n-1`
- `aᵢ != bᵢ`
- Each pair of cities has **at most one** road connecting them.
*/

// @lc code=begin
#include <vector>
using std::vector;
class Solution {
  public:
    int maximalNetworkRank(int n, vector<vector<int>> &roads) {
        vector<vector<int>> graph(n, vector<int>(n));
        vector<int> cnt(n); // 统计每个点有多少个点与它相连
        for (auto &vec : roads) {
            graph[vec[0]][vec[1]] = 1;
            cnt[vec[0]]++;
            graph[vec[1]][vec[0]] = 1;
            cnt[vec[1]]++;
        }
        int num = 0;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (graph[i][j] == 1) {
                    num = std::max(num, cnt[i] + cnt[j] - 1);
                } else {
                    num = std::max(num, cnt[i] + cnt[j]);
                }
            }
        }
        return num;
    }
};

// @lc code=end
