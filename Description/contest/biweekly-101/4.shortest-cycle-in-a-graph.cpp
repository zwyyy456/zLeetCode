// Created by Bob at 2023/04/01 22:59
// https://leetcode.cn/problems/shortest-cycle-in-a-graph/
// https://leetcode.cn/contest/biweekly-contest-101/problems/shortest-cycle-in-a-graph/

/*
6330. 图中的最短环 (Hard)

现有一个含 `n` 个顶点的 **双向** 图，每个顶点按从 `0` 到 `n - 1` 标记。图中的边由二维整数数组
`edges` 表示，其中 `edges[i] = [uᵢ, vᵢ]` 表示顶点 `uᵢ` 和 `vᵢ`
之间存在一条边。每对顶点最多通过一条边连接，并且不存在与自身相连的顶点。

返回图中 **最短** 环的长度。如果不存在环，则返回 `-1` 。

**环** 是指以同一节点开始和结束，并且路径中的每条边仅使用一次。

**示例 1：**

![](https://assets.leetcode.com/uploads/2023/01/04/cropped.png)

```
输入：n = 7, edges =
[[0,1],[1,2],[2,0],[3,4],[4,5],[5,6],[6,3]]
输出：3
解释：长度最小的循环是：0 -> 1 -> 2 -> 0

```

**示例 2：**

![](https://assets.leetcode.com/uploads/2023/01/04/croppedagin.png)

```
输入：n = 4, edges = [[0,1],[0,2]]
输出：-1
解释：图中不存在循环

```

**提示：**

- `2 <= n <= 1000`
- `1 <= edges.length <= 1000`
- `edges[i].length == 2`
- `0 <= uᵢ, vᵢ < n`
- `uᵢ != vᵢ`
- 不存在重复的边
*/

// @lc code=begin

class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        
    }
};

// @lc code=end
