// Created by Bob at 2023/05/31 14:08
// https://leetcode.cn/problems/minimize-the-total-price-of-the-trips/

/*
2646. 最小化旅行的价格总和 (Hard)
现有一棵无向、无根的树，树中有 `n` 个节点，按从 `0` 到 `n - 
1` 编号。给你一个整数 `n` 和一个长度为 `n - 1` 的二维整数数
组 `edges` ，其中 `edges[i] = [aᵢ, bᵢ]` 表示树中节点 `aᵢ` 和
`bᵢ` 之间存在一条边。

每个节点都关联一个价格。给你一个整数数组 `price` ，其中 `pri
ce[i]` 是第 `i` 个节点的价格。

给定路径的 **价格总和** 是该路径上所有节点的价格之和。

另给你一个二维整数数组 `trips` ，其中 `trips[i] = [startᵢ, e
ndᵢ]` 表示您从节点 `startᵢ` 开始第 `i` 次旅行，并通过任何你
喜欢的路径前往节点 `endᵢ` 。

在执行第一次旅行之前，你可以选择一些 **非相邻节点** 并将价格
减半。

返回执行所有旅行的最小价格总和。

**示例 1：**

![](https://assets.leetcode.com/uploads/2023/03/16/diagram2.
png)

```
输入：n = 4, edges = [[0,1],[1,2],[1,3]], price = [2,2,10,6]
, trips = [[0,3],[2,1],[2,3]]
输出：23
解释：
上图表示将节点 2 视为根之后的树结构。第一个图表示初始树，第
二个图表示选择节点 0 、2 和 3 并使其价格减半后的树。
第 1 次旅行，选择路径 [0,1,3] 。路径的价格总和为 1 + 2 + 3 =
6 。
第 2 次旅行，选择路径 [2,1] 。路径的价格总和为 2 + 5 = 7 。
第 3 次旅行，选择路径 [2,1,3] 。路径的价格总和为 5 + 2 + 3 =
10 。
所有旅行的价格总和为 6 + 7 + 10 = 23 。可以证明，23 是可以实
现的最小答案。
```

**示例 2：**

![](https://assets.leetcode.com/uploads/2023/03/16/diagram3.
png)

```
输入：n = 2, edges = [[0,1]], price = [2,2], trips = [[0,0]]
输出：1
解释：
上图表示将节点 0 视为根之后的树结构。第一个图表示初始树，第
二个图表示选择节点 0 并使其价格减半后的树。
第 1 次旅行，选择路径 [0] 。路径的价格总和为 1 。
所有旅行的价格总和为 1 。可以证明，1 是可以实现的最小答案。

```

**提示：**

- `1 <= n <= 50`
- `edges.length == n - 1`
- `0 <= aᵢ, bᵢ <= n - 1`
- `edges` 表示一棵有效的树
- `price.length == n`
- `price[i]` 是一个偶数
- `1 <= price[i] <= 1000`
- `1 <= trips.length <= 100`
- `0 <= startᵢ, endᵢ <= n - 1`

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	int n; LeetCodeIO::scan(cin, n);
	vector<vector<int>> edges; LeetCodeIO::scan(cin, edges);
	vector<int> price; LeetCodeIO::scan(cin, price);
	vector<vector<int>> trips; LeetCodeIO::scan(cin, trips);

	Solution *obj = new Solution();

	auto res = obj->minimumTotalPrice(n, edges, price, trips);

	LeetCodeIO::print(out_stream, res);
	cout << "output: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
