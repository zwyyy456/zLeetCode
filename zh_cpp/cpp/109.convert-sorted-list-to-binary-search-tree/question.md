# [109. 有序链表转换二叉搜索树][link] (Medium)

[link]: https://leetcode.cn/problems/convert-sorted-list-to-binary-search-tree/

给定一个单链表的头节点  `head` ，其中的元素 **按升序排序** ，将其转换为高度平衡的二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差不超过 1。

**示例 1:**

![](https://assets.leetcode.com/uploads/2020/08/17/linked.jpg)

```
输入: head = [-10,-3,0,5,9]
输出: [0,-3,9,-10,null,5]
解释: 一个可能的答案是[0，-3,9，-10,null,5]，它表示所示的高度平衡的二叉搜索树。
```

**示例 2:**

```
输入: head = []
输出: []
```

**提示:**

- `head` 中的节点数在 `[0, 2 * 10⁴]` 范围内
- `-10⁵ <= Node.val <= 10⁵`
