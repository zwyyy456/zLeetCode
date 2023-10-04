# [6988. 统计距离为 k 的点对][link] (Medium)

[link]: https://leetcode.cn/contest/biweekly-contest-113/problems/count-pairs-of-points-with-distance-k/

给你一个 **二维** 整数数组 `coordinates` 和一个整数 `k` ，其中 `coordinates[i] = [xᵢ, yᵢ]` 是第 `i` 
个点在二维平面里的坐标。

我们定义两个点 `(x₁, y₁)` 和 `(x₂, y₂)` 的 **距离** 为 `(x1 XOR x2) + (y1 XOR y2)` ， `XOR` 指的
是按位异或运算。

请你返回满足 `i < j` 且点 `i` 和点 `j` 之间距离为 `k` 的点对数目。

**示例 1：**

```
输入：coordinates = [[1,2],[4,2],[1,3],[5,2]], k = 5
输出：2
解释：以下点对距离为 k ：
- (0, 1)：(1 XOR 4) + (2 XOR 2) = 5 。
- (2, 3)：(1 XOR 5) + (3 XOR 2) = 5 。

```

**示例 2：**

```
输入：coordinates = [[1,3],[1,3],[1,3],[1,3],[1,3]], k = 0
输出：10
解释：任何两个点之间的距离都为 0 ，所以总共有 10 组点对。

```

**提示：**

- `2 <= coordinates.length <= 50000`
- `0 <= xᵢ, yᵢ <= 10⁶`
- `0 <= k <= 100`
