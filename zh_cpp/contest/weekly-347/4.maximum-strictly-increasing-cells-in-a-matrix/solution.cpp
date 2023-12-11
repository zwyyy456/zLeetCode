// Created by Bob at 2023/05/28 10:48
// https://leetcode.cn/problems/maximum-strictly-increasing-cells-in-a-matrix/
// https://leetcode.cn/contest/weekly-contest-347/problems/maximum-strictly-increasing-cells-in-a-matrix/

/*
6456. 矩阵中严格递增的单元格数 (Hard)
给你一个下标从 **1** 开始、大小为 `m x n` 的整数矩阵 `mat`，
你可以选择任一单元格作为 **起始单元格** 。

从起始单元格出发，你可以移动到 **同一行或同一列** 中的任何其
他单元格，但前提是目标单元格的值 **严格大于** 当前单元格的值
。

你可以多次重复这一过程，从一个单元格移动到另一个单元格，直到
无法再进行任何移动。

请你找出从某个单元开始访问矩阵所能访问的 **单元格的最大数量*
* 。

返回一个表示可访问单元格最大数量的整数。

**示例 1：**

**![](https://assets.leetcode.com/uploads/2023/04/23/diag1dr
awio.png)**

```
输入：mat = [[3,1],[3,4]]
输出：2
解释：上图展示了从第 1 行、第 2 列的单元格开始，可以访问 2 
个单元格。可以证明，无论从哪个单元格开始，最多只能访问 2 个
单元格，因此答案是 2 。

```

**示例 2：**

**![](https://assets.leetcode.com/uploads/2023/04/23/diag3dr
awio.png)**

```
输入：mat = [[1,1],[1,1]]
输出：1
解释：由于目标单元格必须严格大于当前单元格，在本示例中只能访
问 1 个单元格。

```

**示例 3：**

**![](https://assets.leetcode.com/uploads/2023/04/23/diag4dr
awio.png)**

```
输入：mat = [[3,1,6],[-9,5,7]]
输出：4
解释：上图展示了从第 2 行、第 1 列的单元格开始，可以访问 4 
个单元格。可以证明，无论从哪个单元格开始，最多只能访问 4 个
单元格，因此答案是 4 。

```

**提示：**

- `m == mat.length `
- `n == mat[i].length `
- `1 <= m, n <= 10⁵`
- `1 <= m * n <= 10⁵`
- `-10⁵ <= mat[i][j] <= 10⁵`

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<vector<int>> mat; LeetCodeIO::scan(cin, mat);

	Solution *obj = new Solution();

	auto res = obj->maxIncreasingCells(mat);

	LeetCodeIO::print(out_stream, res);
	cout << "output: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
