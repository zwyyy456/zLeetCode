// Created by zwyyy456 at 2023/03/17 13:58
// https://leetcode.com/problems/swim-in-rising-water/

/*
778. Swim in Rising Water (Hard)

You are given an `n x n` integer matrix `grid` where each value `grid[i][j]` represents the
elevation at that point `(i, j)`.

The rain starts to fall. At time `t`, the depth of the water everywhere is `t`. You can swim from a
square to another 4-directionally adjacent square if and only if the elevation of both squares
individually are at most `t`. You can swim infinite distances in zero time. Of course, you must stay
within the boundaries of the grid during your swim.

Return the least time until you can reach the bottom right square  `(n - 1, n - 1)` if you start at
the top left square  `(0, 0)`.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/06/29/swim1-grid.jpg)

```
Input: grid = [[0,2],[1,3]]
Output: 3
Explanation:
At time 0, you are in grid location (0, 0).
You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than
t = 0.
You cannot reach point (1, 1) until time 3.
When the depth of water is 3, we can swim anywhere inside the grid.

```

**Example 2:**

![](https://assets.leetcode.com/uploads/2021/06/29/swim2-grid-1.jpg)

```
Input: grid = [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
Output: 16
Explanation: The final route is shown.
We need to wait until time 16 so that (0, 0) and (4, 4) are connected.

```

**Constraints:**

- `n == grid.length`
- `n == grid[i].length`
- `1 <= n <= 50`
- `0 <= grid[i][j] < n²`
- Each value `grid[i][j]` is **unique**.
*/

// @lc code=begin
#include <vector>
#include <queue>
using std::priority_queue;
using std::vector;
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        // Dijkstra算法
        int n = grid.size();
        auto cmp = [&](vector<int> &v1, vector<int> &v2) {
            return v1[2] > v2[2];
        };
        priority_queue<vector<int> , vector<vector<int>>, decltype(cmp)> pq(cmp);
        pq.push({0, 0, grid[0][0]}); // 从0时刻出发，0，0坐标出发
        vector<vector<int>> dis(n, vector<int>(n, -1));
        vector<vector<int>> mov{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while (!pq.empty()) {
            auto vec = pq.top();
            int x = vec[0], y = vec[1], time = vec[2];
            pq.pop();
            if (dis[x][y] != -1) {
                continue;
            }
            dis[x][y] = time;
            for (int i = 0; i < 4; ++i) {
                int new_x = x + mov[i][0], new_y = y + mov[i][1];
                if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < n) {
                    if (dis[new_x][new_y] == -1) {
                        if (time >= grid[new_x][new_y]) {
                            pq.push({new_x, new_y, time});
                        } else {
                            pq.push({new_x, new_y, grid[new_x][new_y]});
                        }
                    }
                }
            }
        }
        return dis[n - 1][n - 1];
    }
};

// @lc code=end
