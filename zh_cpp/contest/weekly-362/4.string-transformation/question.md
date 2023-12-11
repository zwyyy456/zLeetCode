# [8020. 字符串转换][link] (Hard)

[link]: https://leetcode.cn/contest/weekly-contest-362/problems/string-transformation/

给你两个长度都为 `n` 的字符串 `s` 和 `t` 。你可以对字符串 `s` 执行以下操作：

- 将 `s` 长度为 `l` （ `0 < l < n`）的 **后缀字符串** 删除，并将它添加在 `s` 的开头。

   比方说， `s = 'abcd'` ，那么一次操作中，你可以删除后缀 `'cd'` ，并将它添加到 `s` 的开头，得到 `s 
= 'cdab'` 。

给你一个整数 `k` ，请你返回 **恰好** `k` 次操作将 `s` 变为 `t` 的方案数。

由于答案可能很大，返回答案对 `10⁹ + 7` **取余** 后的结果。

**示例 1：**

```
输入：s = "abcd", t = "cdab", k = 2
输出：2
解释：
第一种方案：
第一次操作，选择 index = 3 开始的后缀，得到 s = "dabc" 。
第二次操作，选择 index = 3 开始的后缀，得到 s = "cdab" 。

第二种方案：
第一次操作，选择 index = 1 开始的后缀，得到 s = "bcda" 。
第二次操作，选择 index = 1 开始的后缀，得到 s = "cdab" 。
```

**示例 2：**

```
输入：s = "ababab", t = "ababab", k = 1
输出：2
解释：
第一种方案：
选择 index = 2 开始的后缀，得到 s = "ababab" 。

第二种方案：
选择 index = 4 开始的后缀，得到 s = "ababab" 。
```

**提示：**

- `2 <= s.length <= 5 * 10⁵`
- `1 <= k <= 10¹⁵`
- `s.length == t.length`
- `s` 和 `t` 都只包含小写英文字母。
