# [1595. 连通两组点的最小成本][link] (Hard)

[link]: https://leetcode.cn/problems/minimum-cost-to-connect-two-groups-of-points/

给你两组点，其中第一组中有 `size₁` 个点，第二组中有 `size₂` 个点，且 `size₁ >= size₂` 。

任意两点间的连接成本 `cost` 由大小为 `size₁ x size₂` 矩阵给出，其中 `cost[i][j]` 是第一组中的点 `i` 
和第二组中的点 `j` 的连接成本。 **如果两个组中的每个点都与另一组中的一个或多个点连接，则称这两组点是
连通的。** 换言之，第一组中的每个点必须至少与第二组中的一个点连接，且第二组中的每个点必须至少与第一
组中的一个点连接。

返回连通两组点所需的最小成本。

**示例 1：**

![](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/09/20/ex1.jpg)

```
输入：cost = [[15, 96], [36, 2]]
输出：17
解释：连通两组点的最佳方法是：
1--A
2--B
总成本为 17 。

```

**示例 2：**

![](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/09/20/ex2.jpg)

```
输入：cost = [[1, 3, 5], [4, 1, 1], [1, 5, 3]]
输出：4
解释：连通两组点的最佳方法是：
1--A
2--B
2--C
3--A
最小成本为 4 。
请注意，虽然有多个点连接到第一组中的点 2 和第二组中的点 A ，但由于题目并不限制连接点的数目，所以只需
要关心最低总成本。
```

**示例 3：**

```
输入：cost = [[2, 5, 1], [3, 4, 7], [8, 1, 2], [6, 2, 4], [3, 8, 8]]
输出：10

```

**提示：**

- `size₁ == cost.length`
- `size₂ == cost[i].length`
- `1 <= size₁, size₂ <= 12`
- `size₁ >= size₂`
- `0 <= cost[i][j] <= 100`
