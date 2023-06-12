// Created by Bob at 2023/05/21 10:31
// https://leetcode.cn/problems/modify-graph-edge-weights/
// https://leetcode.cn/contest/weekly-contest-346/problems/modify-graph-edge-weights/

/*
6442. 修改图中的边权 (Hard)
给你一个 `n` 个节点的 **无向带权连通** 图，节点编号为 `0` 到
`n - 1` ，再给你一个整数数组 `edges` ，其中 `edges[i] = [aᵢ,
bᵢ, wᵢ]` 表示节点 `aᵢ` 和 `bᵢ` 之间有一条边权为 `wᵢ` 的边。

部分边的边权为 `-1`（ `wᵢ = -1`），其他边的边权都为 **正** 
数（ `wᵢ > 0`）。

你需要将所有边权为 `-1` 的边都修改为范围 `[1, 2 * 10⁹]` 中的
**正整数** ，使得从节点 `source` 到节点 `destination` 的 **
最短距离** 为整数 `target` 。如果有 **多种** 修改方案可以使 
`source` 和 `destination` 之间的最短距离等于 `target` ，你可
以返回任意一种方案。

如果存在使 `source` 到 `destination` 最短距离为 `target` 的
方案，请你按任意顺序返回包含所有边的数组（包括未修改边权的边
）。如果不存在这样的方案，请你返回一个 **空数组** 。

**注意：** 你不能修改一开始边权为正数的边。

**示例 1：**

**![](https://assets.leetcode.com/uploads/2023/04/18/graph.p
ng)**

```
输入：n = 5, edges = [[4,1,-1],[2,0,-1],[0,3,-1],[4,3,-1]], 
source = 0, destination = 1, target = 5
输出：[[4,1,1],[2,0,1],[0,3,3],[4,3,1]]
解释：上图展示了一个满足题意的修改方案，从 0 到 1 的最短距离
为 5 。

```

**示例 2：**

**![](https://assets.leetcode.com/uploads/2023/04/18/graph-2
.png)**

```
输入：n = 3, edges = [[0,1,-1],[0,2,5]], source = 0, destina
tion = 2, target = 6
输出：[]
解释：上图是一开始的图。没有办法通过修改边权为 -1 的边，使得
0 到 2 的最短距离等于 6 ，所以返回一个空数组。

```

**示例 3：**

**![](https://assets.leetcode.com/uploads/2023/04/19/graph-3
.png)**

```
输入：n = 4, edges = [[1,0,4],[1,2,3],[2,3,5],[0,3,-1]], sou
rce = 0, destination = 2, target = 6
输出：[[1,0,4],[1,2,3],[2,3,5],[0,3,1]]
解释：上图展示了一个满足题意的修改方案，从 0 到 2 的最短距离
为 6 。

```

**提示：**

- `1 <= n <= 100`
- `1 <= edges.length <= n * (n - 1) / 2`
- `edges[i].length == 3`
- `0 <= aᵢ, bᵢ < n`
- `wᵢ = -1` 或者 `1 <= wᵢ <= 10⁷`
- `aᵢ != bᵢ`
- `0 <= source, destination < n`
- `source != destination`
- `1 <= target <= 10⁹`
- 输入的图是连通图，且没有自环和重边。

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	int n; LeetCodeIO::scan(cin, n);
	vector<vector<int>> edges; LeetCodeIO::scan(cin, edges);
	int source; LeetCodeIO::scan(cin, source);
	int destination; LeetCodeIO::scan(cin, destination);
	int target; LeetCodeIO::scan(cin, target);

	Solution *obj = new Solution();

	auto res = obj->modifiedGraphEdges(n, edges, source, destination, target);

	LeetCodeIO::print(out_stream, res);
	cout << "output: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
