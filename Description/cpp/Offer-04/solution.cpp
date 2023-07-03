// Created by Bob at 2023/06/13 16:25
// https://leetcode.cn/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/

/*
剑指 Offer 04. 二维数组中的查找 (Medium)
在一个 n \* m 的二维数组中，每一行都按照从左到右 **非递减** 
的顺序排序，每一列都按照从上到下 **非递减** 的顺序排序。请完
成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组
中是否含有该整数。

**示例:**

现有矩阵 matrix 如下：

```
[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]

```

给定 target = `5`，返回 `true`。

给定 target = `20`，返回 `false`。

**限制：**

`0 <= n <= 1000`

`0 <= m <= 1000`

**注意：** 本题与主站 240 题相同： [https://leetcode-cn.com/
problems/search-a-2d-matrix-ii/](https://leetcode-cn.com/pro
blems/search-a-2d-matrix-ii/)

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {

    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<vector<int>> matrix; LeetCodeIO::scan(cin, matrix);
	int target; LeetCodeIO::scan(cin, target);

	Solution *obj = new Solution();

	auto res = obj->findNumberIn2DArray(matrix, target);

	LeetCodeIO::print(out_stream, res);
	cout << "output: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
