// Created by zwyyy456 at 2023/03/15 14:28
// https://leetcode.com/problems/trapping-rain-water-ii/

/*
407. Trapping Rain Water II (Hard)

Given an `m x n` integer matrix `heightMap` representing the height of each unit cell in a 2D
elevation map, return the volume of water it can trap after raining.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/04/08/trap1-3d.jpg)

```
Input: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
Output: 4
Explanation: After the rain, water is trapped between the blocks.
We have two small ponds 1 and 3 units trapped.
The total volume of water trapped is 4.

```

**Example 2:**

![](https://assets.leetcode.com/uploads/2021/04/08/trap2-3d.jpg)

```
Input: heightMap = [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]
Output: 10

```

**Constraints:**

- `m == heightMap.length`
- `n == heightMap[i].length`
- `1 <= m, n <= 200`
- `0 <= heightMap[i][j] <= 2 * 10⁴`
*/

// @lc code=begin
#include <vector>
#include <queue>
using std::vector;
using std::priority_queue;
class Solution {
  public:
    int trapRainWater(vector<vector<int>> &heightMap) {
        // 找边界上所有点，到x,y的路径上的最大高度的最小值（不包括x,y）
        // (x,y)处的存放的雨水即这个高度h-heightMap[x][y];
        int m = heightMap.size();
        int n = heightMap[0].size();
        auto cmp = [&](vector<int> &v1, vector<int> &v2) {
            return v1[2] > v2[2];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < n; ++i) {
            pq.push({0, i, heightMap[0][i]});
            pq.push({m - 1, i, heightMap[m - 1][i]});
        }
        for (int i = 1; i < m - 1; ++i) {
            pq.push({i, 0, heightMap[i][0]});
            pq.push({i, n - 1, heightMap[i][n - 1]});
        }
        vector<vector<int>> dis(m, vector<int>(n));
        vector<vector<int>> vis(m, vector<int>(n));
        vector<vector<int>> neighbor{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while (!pq.empty()) {
            auto vec = pq.top();
            int x = vec[0], y = vec[1], height = vec[2];
            pq.pop();
            if (vis[x][y] != 0) {
                continue;
            }
            vis[x][y] = 1;
            dis[x][y] = height;
            for (int i = 0; i < 4; ++i) {
                int new_x = x + neighbor[i][0];
                int new_y = y + neighbor[i][1];
                if (new_x < m && new_x >= 0 && new_y < n && new_y >= 0) {
                    pq.push({new_x, new_y, std::max(height, heightMap[new_x][new_y])});
                }
            }
        }
        int res = 0;
        for (int i = 1; i < m - 1; ++i) {
            for (int j = 1; j < n - 1; ++j) {
                res += dis[i][j] - heightMap[i][j];
            }
        }
        return res;
    }
};

// @lc code=end
