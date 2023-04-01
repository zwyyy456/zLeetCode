// Created by Bob at 2023/03/17 14:21
// https://leetcode.cn/problems/swim-in-rising-water/

/*
778. 水位上升的泳池中游泳 (Hard)

在一个 `n x n` 的整数矩阵 `grid` 中，每一个方格的值 `grid[i][j]` 表示位置 `(i,
j)` 的平台高度。

当开始下雨时，在时间为 `t` 时，水池中的水位为 `t`
。你可以从一个平台游向四周相邻的任意一个平台，但是前提是此时水位必须同时淹没这两个平台。假定你可以瞬间移动无限距离，也就是默认在方格内部游动是不耗时的。当然，在你游泳的时候你必须待在坐标方格里面。

你从坐标方格的左上平台 `(0，0)` 出发。返回 你到达坐标方格的右下平台 `(n-1, n-1)` 所需的最少时间
。

**示例 1:**

![](https://assets.leetcode.com/uploads/2021/06/29/swim1-grid.jpg)

```
输入: grid = [[0,2],[1,3]]
输出: 3
解释:
时间为0时，你位于坐标方格的位置为 (0, 0)。
此时你不能游向任意方向，因为四个相邻方向平台的高度都大于当前时间为 0 时的水位。
等时间到达 3 时，你才可以游向平台 (1, 1). 因为此时的水位是 3，坐标方格中的平台没有比水位 3
更高的，所以你可以游向坐标方格中的任意位置

```

**示例 2:**

![](https://assets.leetcode.com/uploads/2021/06/29/swim2-grid-1.jpg)

```
输入: grid =
[[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
输出: 16
解释: 最终的路线用加粗进行了标记。
我们必须等到时间为 16，此时才能保证平台 (0, 0) 和 (4, 4) 是连通的

```

**提示:**

- `n == grid.length`
- `n == grid[i].length`
- `1 <= n <= 50`
- `0 <= grid[i][j] < n²`
- `grid[i][j]` 中每个值 **均无重复**
*/

// @lc code=begin
#include <vector>
#include <queue>
using std::vector;
using std::queue;
class Solution {
  public:
    bool bfs(vector<vector<int>> &grid, int mid) {
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        queue<vector<int>> q;
        q.push({0, 0});
        vis[0][0] = 1;
        vector<vector<int>> mov{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            auto vec = q.front();
            if (vec[0] == n - 1 && vec[1] == n - 1) {
                return true;
            }
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int x_new = vec[0] + mov[i][0], y_new = vec[1] + mov[i][1];
                if (x_new >= 0 && x_new < n && y_new >= 0 && y_new < n && vis[x_new][y_new] == 0 && mid >= grid[x_new][y_new]) {
                    q.push({x_new, y_new});
                    vis[x_new][y_new] = 1;
                }
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>> &grid) {
        // 二分答案，如果ans < target，那么无法到达，左闭右开
        int left = 0, right = 2500;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (bfs(grid, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return std::max(left, grid[0][0]);
    }
};

// @lc code=end
