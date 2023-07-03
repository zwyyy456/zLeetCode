// Created by zwyyy456 at 2023/03/28 09:23
// https://leetcode.com/problems/shortest-common-supersequence/

/*
1092. Shortest Common Supersequence  (Hard)

Given two strings `str1` and `str2`, return the shortest string that has both  `str1` and  `str2` as
**subsequences**. If there are multiple valid strings, return **any** of them.

A string `s` is a **subsequence** of string `t` if deleting some number of characters from `t`
(possibly `0`) results in the string `s`.

**Example 1:**

```
Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation:
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.

```

**Example 2:**

```
Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
Output: "aaaaaaaa"

```

**Constraints:**

- `1 <= str1.length, str2.length <= 1000`
- `str1` and `str2` consist of lowercase English letters.
*/

// @lc code=begin
#include <string>
using std::string;
class Solution {
public:
    int lis(string &str1, string &str2) {

    }
    string shortestCommonSupersequence(string str1, string str2) {
        // 求一个str2相对于str1的最长递增子序列的长度，设为l2，res = str1.size() + str2.size() - l2
        // 求一个str1相对于str2的最长递增子序列的长度，设为l1，res = min(res, str1.size() + str2.size() - l1)
        // 转化
        int l1 = lis(str1, str2), l2 = lis(str2, str1);
        
    }
};

// @lc code=end
