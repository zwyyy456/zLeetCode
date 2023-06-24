// Created by Bob at 2023/02/18 19:02
// https://leetcode.com/problems/max-increase-to-keep-city-skyline/

/*
807. Max Increase to Keep City Skyline (Medium)

There is a city composed of `n x n` blocks, where each block contains a single building shaped like
a vertical square prism. You are given a **0-indexed** `n x n` integer matrix `grid` where
`grid[r][c]` represents the **height** of the building located in the block at row `r` and column
`c`.
A city's **skyline** is the the outer contour formed by all the building when viewing the side of
the city from a distance. The **skyline** from each cardinal direction north, east, south, and west
may be different.
We are allowed to increase the height of **any number of buildings by any amount** (the amount can
be different per building). The height of a `0`-height building can also be increased. However,
increasing the height of a building should **not** affect the city's **skyline** from any cardinal
direction.
Return the **maximum total sum** that the height of the buildings can be increased by **without**
changing the city's **skyline** from any cardinal direction.
**Example 1:**
![](https://assets.leetcode.com/uploads/2021/06/21/807-ex1.png)
```
Input: grid = [[3,0,8,4],[2,4,5,7],[9,2,6,3],[0,3,1,0]]
Output: 35
Explanation: The building heights are shown in the center of the above image.
The skylines when viewed from each cardinal direction are drawn in red.
The grid after increasing the height of buildings without affecting skylines is:
gridNew = [ [8, 4, 8, 7],
            [7, 4, 7, 7],
            [9, 4, 8, 7],
            [3, 3, 3, 3] ]
```
**Example 2:**
```
Input: grid = [[0,0,0],[0,0,0],[0,0,0]]
Output: 0
Explanation: Increasing the height of any building will result in the skyline changing.
```
**Constraints:**
- `n == grid.length`
- `n == grid[r].length`
- `2 <= n <= 50`
- `0 <= grid[r][c] <= 100`
*/

// @lc code=begin
#include <locale>
#include <vector>
using std::vector;
class Solution {
  public:
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid) {
        int n = grid.size();
        vector<int> col_max(n, 0);
        vector<int> row_max(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                row_max[i] = std::max(row_max[i], grid[i][j]);
                col_max[j] = std::max(col_max[j], grid[i][j]);
            }
        }
        // vector<vector<int>> res(n, vector<int>(n, 0));
        int res = 0;
        int diff = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                diff = std::min(row_max[i], col_max[j]) - grid[i][j];
                res += diff > 0 ? diff : 0;
            }
        }
        return res;
    }
};

// @lc code=end
