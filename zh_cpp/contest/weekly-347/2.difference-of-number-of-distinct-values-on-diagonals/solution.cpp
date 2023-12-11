// Created by Bob at 2023/05/28 10:48
// https://leetcode.cn/problems/difference-of-number-of-distinct-values-on-diagonals/
// https://leetcode.cn/contest/weekly-contest-347/problems/difference-of-number-of-distinct-values-on-diagonals/

/*
6440. 对角线上不同值的数量差 (Easy)
给你一个下标从 `0` 开始、大小为 `m x n` 的二维矩阵 `grid` ，
请你求解大小同样为 `m x n` 的答案矩阵 `answer` 。

矩阵 `answer` 中每个单元格 `(r, c)` 的值可以按下述方式进行计
算：

- 令 `topLeft[r][c]` 为矩阵 `grid` 中单元格 `(r, c)` 左上角
对角线上 **不同值** 的数量。
- 令 `bottomRight[r][c]` 为矩阵 `grid` 中单元格 `(r, c)` 右
下角对角线上 **不同值** 的数量。

然后 `answer[r][c] = |topLeft[r][c] - bottomRight[r][c]|` 。

返回矩阵 `answer` 。

**矩阵对角线** 是从最顶行或最左列的某个单元格开始，向右下方
向走到矩阵末尾的对角线。

如果单元格 `(r1, c1)` 和单元格 `(r, c) ` 属于同一条对角线且
`r1 < r` ，则单元格 `(r1, c1)` 属于单元格 `(r, c)` 的左上对
角线。类似地，可以定义右下对角线。

**示例 1：**

![](https://assets.leetcode.com/uploads/2023/04/19/ex2.png)

```
输入：grid = [[1,2,3],[3,1,5],[3,2,1]]
输出：[[1,1,0],[1,0,1],[0,1,1]]
解释：第 1 个图表示最初的矩阵 grid 。
第 2 个图表示对单元格 (0,0) 计算，其中蓝色单元格是位于右下对
角线的单元格。
第 3 个图表示对单元格 (1,2) 计算，其中红色单元格是位于左上对
角线的单元格。
第 4 个图表示对单元格 (1,1) 计算，其中蓝色单元格是位于右下对
角线的单元格，红色单元格是位于左上对角线的单元格。
- 单元格 (0,0) 的右下对角线包含 [1,1] ，而左上对角线包含 []
。对应答案是 |1 - 0| = 1 。
- 单元格 (1,2) 的右下对角线包含 [] ，而左上对角线包含 [2] 。
对应答案是 |0 - 1| = 1 。
- 单元格 (1,1) 的右下对角线包含 [1] ，而左上对角线包含 [1]
。对应答案是 |1 - 1| = 0 。
其他单元格的对应答案也可以按照这样的流程进行计算。

```

**示例 2：**

```
输入：grid = [[1]]
输出：[[0]]
解释：- 单元格 (0,0) 的右下对角线包含 [] ，左上对角线包含 []
。对应答案是 |0 - 0| = 0 。

```

**提示：**

- `m == grid.length`
- `n == grid[i].length`
- `1 <= m, n, grid[i][j] <= 50`

*/

#include <bits/stdc++.h>
#include <unordered_set>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int Count(vector<vector<int>> &grid, int i, int j) {
        unordered_set<int> top_left;
        for (int x = i - 1, y = j - 1; x >= 0 && y >= 0; --x, --y) {
            top_left.insert(grid[x][y]);
        }
        unordered_set<int> bot_right;
        for (int x = i + 1, y = j + 1; x < grid.size() && y < grid[0].size(); ++x, ++y) {
            bot_right.insert(grid[x][y]);
        }
        int l = top_left.size(), r = bot_right.size();
        return abs(l - r);
    }
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res[i][j] = Count(grid, i, j);
            }
        }
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<vector<int>> grid;
    LeetCodeIO::scan(cin, grid);

    Solution *obj = new Solution();

    auto res = obj->differenceOfDistinctValues(grid);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
