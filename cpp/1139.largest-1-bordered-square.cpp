// Created by Bob at 2023/02/17 10:39
// https://leetcode.com/problems/largest-1-bordered-square/

/*
1139. Largest 1-Bordered Square (Medium)

Given a 2D `grid` of `0` s and `1` s, return the number of elements in the largest **square**
subgrid that has all `1` s on its **border**, or `0` if such a subgrid doesn't exist in the `grid`.
**Example 1:**
```
Input: grid = [[1,1,1],[1,0,1],[1,1,1]]
Output: 9
```
**Example 2:**
```
Input: grid = [[1,1,0,0]]
Output: 1
```
**Constraints:**
- `1 <= grid.length <= 100`
- `1 <= grid[0].length <= 100`
- `grid[i][j]` is `0` or `1`
*/

// @lc code=begin
#include <iterator>
#include <vector>
#include <algorithm>
using std::vector;
class Solution {
  public:
    int largest1BorderedSquare(vector<vector<int>> &grid) {
        // 前缀和
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> sum_row(m, vector<int>(n + 1, 0)); // 每行前缀和
        vector<vector<int>> sum_col(m + 1, vector<int>(n, 0)); // 每列前缀和
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 1; j <= n; j++) {
                sum_row[i][j] = sum_row[i][j - 1] + grid[i][j - 1];
            }
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < n; j++) {
                sum_col[i][j] = sum_col[i - 1][j] + grid[i - 1][j];
            }
        }
        int res = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                for (int l = res + 1; l <= std::min(i, j); l++) { // 直接从res开始
                    if (sum_col[i][j - 1] - sum_col[i - l][j - 1] == l && sum_row[i - 1][j] - sum_row[i - 1][j - l] == l && sum_col[i][j - l] - sum_col[i - l][j - l] == l && sum_row[i - l][j] - sum_row[i - l][j - l] == l)
                        res = std::max(l, res);
                }
            }
        }
        return res * res;
    }
};

// @lc code=end
