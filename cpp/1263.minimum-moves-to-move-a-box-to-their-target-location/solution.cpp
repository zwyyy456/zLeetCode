// Created by zwyyy456 at 2023/05/08 15:12
// https://leetcode.com/problems/minimum-moves-to-move-a-box-to-their-target-location/

/*
1263. Minimum Moves to Move a Box to Their Target Location (Hard)
A storekeeper is a game in which the player pushes boxes around in a warehouse trying to get them to
target locations.

The game is represented by an `m x n` grid of characters `grid` where each element is a wall, floor,
or box.

Your task is to move the box `'B'` to the target position `'T'` under the following rules:

- The character `'S'` represents the player. The player can move up, down, left, right in `grid` if
it is a floor (empty cell).
- The character `'.'` represents the floor which means a free cell to walk.
- The character `'#' ` represents the wall which means an obstacle (impossible to walk there).
- There is only one box `'B'` and one target cell `'T'` in the `grid`.
- The box can be moved to an adjacent free cell by standing next to the box and then moving in the
direction of the box. This is a **push**.
- The player cannot walk through the box.

Return the minimum number of **pushes** to move the box to the target. If there is no way to reach
the target, return `-1`.

**Example 1:**

![](https://assets.leetcode.com/uploads/2019/11/06/sample_1_1620.png)

```
Input: grid = [["#","#","#","#","#","#"],
               ["#","T","#","#","#","#"],
               ["#",".",".","B",".","#"],
               ["#",".","#","#",".","#"],
               ["#",".",".",".","S","#"],
               ["#","#","#","#","#","#"]]
Output: 3
Explanation: We return only the number of times the box is pushed.
```

**Example 2:**

```
Input: grid = [["#","#","#","#","#","#"],
               ["#","T","#","#","#","#"],
               ["#",".",".","B",".","#"],
               ["#","#","#","#",".","#"],
               ["#",".",".",".","S","#"],
               ["#","#","#","#","#","#"]]
Output: -1

```

**Example 3:**

```
Input: grid = [["#","#","#","#","#","#"],
               ["#","T",".",".","#","#"],
               ["#",".","#","B",".","#"],
               ["#",".",".",".",".","#"],
               ["#",".",".",".","S","#"],
               ["#","#","#","#","#","#"]]
Output: 5
Explanation: push the box down, left, left, up and up.

```

**Constraints:**

- `m == grid.length`
- `n == grid[i].length`
- `1 <= m, n <= 20`
- `grid` contains only characters `'.'`, `'#'`, `'S'`, `'T'`, or `'B'`.
- There is only one character `'S'`, `'B'`, and `'T'` in the `grid`.

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int minPushBox(vector<vector<char>> &grid) {
        // pq，[0]当前状态最小推箱子次数 [1]人的坐标x [2]人的坐标y [3]箱子的坐标x [4]箱子的坐标y
        priority_queue<vector<size_t>, vector<vector<size_t>>, greater<vector<size_t>>> pq;
        size_t m = grid.size();
        size_t n = grid[0].size();
        vector<size_t> a(5, 0);
        for (size_t x = 0; x < m; x++) {
            for (size_t y = 0; y < n; y++) {
                if (grid[x][y] == 'S') {
                    a[1] = x;
                    a[2] = y;
                    grid[x][y] = '.';
                } else if (grid[x][y] == 'B') {
                    a[3] = x;
                    a[4] = y;
                    grid[x][y] = '.';
                }
            }
        }
        pq.push(a);
        set<vector<size_t>> dist;
        dist.insert({a[1], a[2], a[3], a[4]});
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        while (!pq.empty()) {
            auto v = pq.top();
            pq.pop();
            for (int i = 0; i < 4; i++) {
                vector<size_t> next_s = {v[1] + dx[i], v[2] + dy[i]};
                if (next_s[0] >= m || next_s[1] >= n || grid[next_s[0]][next_s[1]] == '#') {
                    continue;
                }
                vector<size_t> next_b = {v[3], v[4]};
                size_t d = v[0];
                if (next_s == next_b) {
                    next_b[0] += dx[i];
                    next_b[1] += dy[i];
                    if (next_b[0] >= m || next_b[1] >= n || grid[next_b[0]][next_b[1]] == '#') {
                        continue;
                    }
                    d++;
                }
                if (grid[next_b[0]][next_b[1]] == 'T') {
                    return (int)d;
                }
                if (dist.find({next_s[0], next_s[1], next_b[0], next_b[1]}) != dist.end()) {
                    continue;
                }
                dist.insert({next_s[0], next_s[1], next_b[0], next_b[1]});
                pq.push({d, next_s[0], next_s[1], next_b[0], next_b[1]});
            }
        }
        return -1;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<vector<char>> grid;
    LeetCodeIO::scan(cin, grid);

    Solution *obj = new Solution();

    auto res = obj->minPushBox(grid);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
