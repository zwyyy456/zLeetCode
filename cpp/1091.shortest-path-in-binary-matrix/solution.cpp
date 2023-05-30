// Created by zwyyy456 at 2023/05/26 09:15
// https://leetcode.com/problems/shortest-path-in-binary-matrix/

/*
1091. Shortest Path in Binary Matrix (Medium)
Given an `n x n` binary matrix `grid`, return the length of the shortest **clear path** in the
matrix. If there is no clear path, return `-1`.

A **clear path** in a binary matrix is a path from the **top-left** cell (i.e., `(0, 0)`) to the
**bottom-right** cell (i.e., `(n - 1, n - 1)`) such that:

- All the visited cells of the path are `0`.
- All the adjacent cells of the path are **8-directionally** connected (i.e., they are different and
they share an edge or a corner).

The **length of a clear path** is the number of visited cells of this path.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/02/18/example1_1.png)

```
Input: grid = [[0,1],[1,0]]
Output: 2

```

**Example 2:**

![](https://assets.leetcode.com/uploads/2021/02/18/example2_1.png)

```
Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4

```

**Example 3:**

```
Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
Output: -1

```

**Constraints:**

- `n == grid.length`
- `n == grid[i].length`
- `1 <= n <= 100`
- `grid[i][j] is 0 or 1`

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
        // bfs
        vector<pair<int, int>> mov{{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
        int n = grid.size();
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        queue<pair<pair<int, int>, int>> q;
        if (grid[0][0] == 1) {
            return -1;
        }
        q.push({{0, 0}, 1});
        while (!q.empty()) {
            auto [p, dis] = q.front();
            q.pop();
            int x = p.first, y = p.second;
            if (x == n - 1 && y == n - 1) {
                return dis;
            }
            for (int i = 0; i < 8; ++i) {
                int new_x = x + mov[i].first;
                int new_y = y + mov[i].second;
                if (new_x >= n || new_x < 0 || new_y >= n || new_y < 0) {
                    continue;
                }
                if (!vis[new_x][new_y] && grid[new_x][new_y] == 0) {
                    q.push({{new_x, new_y}, dis + 1});
                    vis[new_x][new_y] = true;
                }
            }
        }
        return -1;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<vector<int>> grid;
    LeetCodeIO::scan(cin, grid);

    Solution *obj = new Solution();

    auto res = obj->shortestPathBinaryMatrix(grid);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
