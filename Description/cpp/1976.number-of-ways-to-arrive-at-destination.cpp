// Created by Bob at 2023/03/14 14:38
// https://leetcode.cn/problems/number-of-ways-to-arrive-at-destination/

/*
1976. 到达目的地的方案数 (Medium)

你在一个城市里，城市由 `n` 个路口组成，路口编号为 `0` 到 `n - 1` ，某些路口之间有 **双向**
道路。输入保证你可以从任意路口出发到达其他任意路口，且任意两个路口之间最多有一条路。

给你一个整数 `n` 和二维整数数组 `roads` ，其中 `roads[i] = [uᵢ, vᵢ, timeᵢ]`
表示在路口 `uᵢ` 和 `vᵢ` 之间有一条需要花费 `timeᵢ` 时间才能通过的道路。你想知道花费
**最少时间** 从路口 `0` 出发到达路口 `n - 1` 的方案数。

请返回花费 **最少时间** 到达目的地的 **路径数目** 。由于答案可能很大，将结果对 `10⁹ + 7`
**取余** 后返回。

**示例 1：**

![](https://assets.leetcode.com/uploads/2021/07/17/graph2.png)

```
输入：n = 7, roads =
[[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
输出：4
解释：从路口 0 出发到路口 6 花费的最少时间是 7 分钟。
四条花费 7 分钟的路径分别为：
- 0 ➝ 6
- 0 ➝ 4 ➝ 6
- 0 ➝ 1 ➝ 2 ➝ 5 ➝ 6
- 0 ➝ 1 ➝ 3 ➝ 5 ➝ 6

```

**示例 2：**

```
输入：n = 2, roads = [[1,0,10]]
输出：1
解释：只有一条从路口 0 到路口 1 的路，花费 10 分钟。

```

**提示：**

- `1 <= n <= 200`
- `n - 1 <= roads.length <= n * (n - 1) / 2`
- `roads[i].length == 3`
- `0 <= uᵢ, vᵢ <= n - 1`
- `1 <= timeᵢ <= 10⁹`
- `uᵢ != vᵢ`
- 任意两个路口之间至多有一条路。
- 从任意路口出发，你能够到达其他任意路口。
*/

// @lc code=begin

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

    }
};

// @lc code=end
