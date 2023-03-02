// Created by zwyyy456 at 2023/03/01 18:21
// https://leetcode.com/problems/largest-local-values-in-a-matrix/

/*
2373. Largest Local Values in a Matrix (Easy)

You are given an `n x n` integer matrix `grid`.

Generate an integer matrix `maxLocal` of size `(n - 2) x (n - 2)` such that:

- `maxLocal[i][j]` is equal to the **largest** value of the `3 x 3` matrix in `grid` centered around
row `i + 1` and column `j + 1`.

In other words, we want to find the largest value in every contiguous `3 x 3` matrix in `grid`.

Return the generated matrix.

**Example 1:**

![](https://assets.leetcode.com/uploads/2022/06/21/ex1.png)

```
Input: grid = [[9,9,8,1],[5,6,2,6],[8,2,6,4],[6,2,2,2]]
Output: [[9,9],[8,6]]
Explanation: The diagram above shows the original matrix and the generated matrix.
Notice that each value in the generated matrix corresponds to the largest value of a contiguous 3 x
3 matrix in grid.
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2022/07/02/ex2new2.png)

```
Input: grid = [[1,1,1,1,1],[1,1,1,1,1],[1,1,2,1,1],[1,1,1,1,1],[1,1,1,1,1]]
Output: [[2,2,2],[2,2,2],[2,2,2]]
Explanation: Notice that the 2 is contained within every contiguous 3 x 3 matrix in grid.

```

**Constraints:**

- `n == grid.length == grid[i].length`
- `3 <= n <= 100`
- `1 <= grid[i][j] <= 100`
*/

// @lc code=begin
#include <algorithm>
#include <vector>
using std::vector;
class Solution {
  public:
    vector<vector<int>> largestLocal(vector<vector<int>> &grid) {
        vector<vector<int>> move{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        int n = grid.size();
        vector<vector<int>> res(n - 2);
        int max_num = 0;
        for (int i = 1; i < n - 1; ++i) {
            for (int j = 1; j < n - 1; ++j) {
                max_num = grid[i][j];
                for (int k = 0; k < 8; k++) {
                    max_num = std::max(max_num, grid[i + move[k][0]][j + move[k][1]]);
                }
                res[i - 1].push_back(max_num);
            }
        }
        return res;
    }
};

// @lc code=end
