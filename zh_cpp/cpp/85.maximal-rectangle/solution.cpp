// Created by Bob at 2023/05/23 15:25
// https://leetcode.cn/problems/maximal-rectangle/

/*
85. 最大矩形 (Hard)
给定一个仅包含 `0` 和 `1` 、大小为 `rows x cols` 的二维二进
制矩阵，找出只包含 `1` 的最大矩形，并返回其面积。

**示例 1：**

![](https://assets.leetcode.com/uploads/2020/09/14/maximal.j
pg)

```
输入：matrix = [["1","0","1","0","0"],["1","0","1","1","1"],
["1","1","1","1","1"],["1","0","0","1","0"]]
输出：6
解释：最大矩形如上图所示。

```

**示例 2：**

```
输入：matrix = []
输出：0

```

**示例 3：**

```
输入：matrix = [["0"]]
输出：0

```

**示例 4：**

```
输入：matrix = [["1"]]
输出：1

```

**示例 5：**

```
输入：matrix = [["0","0"]]
输出：0

```

**提示：**

- `rows == matrix.length`
- `cols == matrix[0].length`
- `1 <= row, cols <= 200`
- `matrix[i][j]` 为 `'0'` 或 `'1'`

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int maximalRectangle(vector<vector<char>> &matrix) {
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<vector<char>> matrix;
    LeetCodeIO::scan(cin, matrix);

    Solution *obj = new Solution();

    auto res = obj->maximalRectangle(matrix);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
