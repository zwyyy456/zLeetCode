// Created by zwyyy456 at 2023/04/04 09:19
// https://leetcode.com/problems/coloring-a-border/

/*
1034. Coloring A Border (Medium)

You are given an `m x n` integer matrix `grid`, and three integers `row`, `col`, and `color`. Each
value in the grid represents the color of the grid square at that location.

Two squares belong to the same **connected component** if they have the same color and are next to
each other in any of the 4 directions.

The **border of a connected component** is all the squares in the connected component that are
either **4-directionally** adjacent to a square not in the component, or on the boundary of the grid
(the first or last row or column).

You should color the **border** of the **connected component** that contains the square
`grid[row][col]` with `color`.

Return the final grid.

**Example 1:**

```
Input: grid = [[1,1],[1,2]], row = 0, col = 0, color = 3
Output: [[3,3],[3,2]]

```

**Example 2:**

```
Input: grid = [[1,2,2],[2,3,2]], row = 0, col = 1, color = 3
Output: [[1,3,3],[2,3,3]]

```

**Example 3:**

```
Input: grid = [[1,1,1],[1,1,1],[1,1,1]], row = 1, col = 1, color = 2
Output: [[2,2,2],[2,1,2],[2,2,2]]

```

**Constraints:**

- `m == grid.length`
- `n == grid[i].length`
- `1 <= m, n <= 50`
- `1 <= grid[i][j], color <= 1000`
- `0 <= row < m`
- `0 <= col < n`
*/

// @lc code=begin
#include <vector>
#include <queue>
#include <tuple>
using std::tuple;
using std::queue;
using std::vector;
class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        vector<vector<int>> mov{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<tuple<int, int, int>> q;
        q.push({row, col, grid[row][col]});
        vis[row][col] = 1;
        // bfs
        while (!q.empty()) {
            auto [x, y, colo] = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int new_x = x + mov[i][0];
                int new_y = y + mov[i][1];
                if (new_x >= m || new_x < 0 || new_y >= n || new_y < 0) {
                    grid[x][y] = color; // 说明x、y已经是边界了
                    continue; // 不将new_x，new_y入队
                }
                if (vis[new_x][new_y] == 0) {
                    // 说明这个点没访问过
                    if (grid[new_x][new_y] == colo) {
                        // 入队，标记
                        q.push({new_x, new_y, colo});
                        vis[new_x][new_y] = 1;
                    } else {
                        grid[x][y] = color;
                    }
                }
            }
        }
        return grid;
    }
};

// @lc code=end
