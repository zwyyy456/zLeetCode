// Created by zwyyy456 at 2023/03/21 18:39
// https://leetcode.com/problems/making-a-large-island/

/*
827. Making A Large Island (Hard)

You are given an `n x n` binary matrix `grid`. You are allowed to change **at most one** `0` to be
`1`.

Return the size of the largest **island** in `grid`after applying this operation.

An **island** is a 4-directionally connected group of `1` s.

**Example 1:**

```
Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.

```

**Example 2:**

```
Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
```

**Example 3:**

```
Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.

```

**Constraints:**

- `n == grid.length`
- `n == grid[i].length`
- `1 <= n <= 500`
- `grid[i][j]` is either `0` or `1`.
*/

// @lc code=begin
#include <vector>
#include <queue>
using std::queue;
using std::vector;
class Solution {
  public:
    int dfs(int cnt, vector<vector<int>> &grid, vector<vector<vector<int>>> &vis, int x, int y) {
        if (x >= grid.size() || y >= grid.size()) {
            return 0;
        }
        if (vis[x][y][0] == 0) {
            return vis[x][y][0];
        }
        if (vis[x][y][0] > 0) {
            vis[x][y][1] = cnt;
            return vis[x][y][0];
        }
        if (grid[x][y] == 0) {
            vis[x][y][0] = 0;
            return 0;
        }
        vis[x][y][1] = cnt;
        vis[x][y][0] = 1 + dfs(cnt, grid, vis, x + 1, y) + dfs(cnt, grid, vis, x, y + 1);
        return vis[x][y][0];
    }
    int largestIsland(vector<vector<int>> &grid) {
        // dfs来确定有几个岛屿，每个小岛属于哪个岛屿
        int n = grid.size();
        vector<int> island(n * n);
        vector<vector<vector<int>>> vis(n, vector<vector<int>>(n, vector<int>(2, -1)));
        int res = 0;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (vis[i][j][0] == -1 && grid[i][j] == 1) {
                    cnt++;
                    res = std::max(res, dfs(cnt, grid, vis, i, j));
                }
            }
        }
        vector<int> arr(cnt + 1);
        vector<vector<int>> mov{{1, 0}, {-1, 0}, {0, 1}, {1, 0}};
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    int tmp = 1;
                    for (int k = 0; k < 4; ++k) {
                        int x = i + mov[k][0];
                        int y = j + mov[k][1];
                        if (x >= 0 && x < n && y >= 0 && y < n) {
                            int tmp_cnt = vis[x][y][1];
                            if (arr[tmp_cnt] == 0) {
                                tmp += vis[x][y][0];
                                arr[tmp_cnt] = 1;
                            }
                        }
                    }
                    res = std::max(res, tmp);
                    for (int k = 0; k < 4; ++k) {
                        int x = i + mov[k][0];
                        int y = j + mov[k][1];
                        if (x >= 0 && x < n && y >= 0 && y < n) {
                            int tmp_cnt = vis[x][y][1];
                            arr[tmp_cnt] = 0;
                        }
                    }
                }
            }
        }
        return ans;
    }
};

// @lc code=end
