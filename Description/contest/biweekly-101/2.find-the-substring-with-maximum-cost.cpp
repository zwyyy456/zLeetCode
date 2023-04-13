// Created by Bob at 2023/04/01 22:59
// https://leetcode.cn/problems/find-the-substring-with-maximum-cost/
// https://leetcode.cn/contest/biweekly-contest-101/problems/find-the-substring-with-maximum-cost/

/*
6328. 找到最大开销的子字符串 (Medium)

给你一个字符串 `s` ，一个字符 **互不相同** 的字符串 `chars` 和一个长度与 `chars`
相同的整数数组 `vals` 。

**子字符串的开销** 是一个子字符串中所有字符对应价值之和。空字符串的开销是 `0` 。

**字符的价值** 定义如下：

- 如果字符不在字符串 `chars` 中，那么它的价值是它在字母表中的位置（下标从 **1** 开始）。

  - 比方说， `'a'` 的价值为 `1` ， `'b'` 的价值为 `2` ，以此类推， `'z'` 的价值为
`26` 。
- 否则，如果这个字符在 `chars` 中的位置为 `i` ，那么它的价值就是 `vals[i]` 。

请你返回字符串 `s` 的所有子字符串中的最大开销。

**示例 1：**

```
输入：s = "adaa", chars = "d", vals = [-1000]
输出：2
解释：字符 "a" 和 "d" 的价值分别为 1 和 -1000 。
最大开销子字符串是 "aa" ，它的开销为 1 + 1 = 2 。
2 是最大开销。

```

**示例 2：**

```
输入：s = "abc", chars = "abc", vals = [-1,-1,-1]
输出：0
解释：字符 "a" ，"b" 和 "c" 的价值分别为 -1 ，-1 和 -1 。
最大开销子字符串是 "" ，它的开销为 0 。
0 是最大开销。

```

**提示：**

- `1 <= s.length <= 10⁵`
- `s` 只包含小写英文字母。
- `1 <= chars.length <= 26`
- `chars` 只包含小写英文字母，且 **互不相同** 。
- `vals.length == chars.length`
- `-1000 <= vals[i] <= 1000`
*/

// @lc code=begin
#include <string>
#include <vector>
using std::string;
using std::vector;
class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        int n = chars.size(), m = s.size();
        vector<int> arr(26, -1);
        for (int i = 0; i < n; ++i) {
            arr[chars[i] - 'a'] = i;
        }
        vector<int> dp(m); // dp[i]表示s[i]结尾的子串的最大开销
        dp[0] = (arr[s[0] - 'a'] == -1 ? s[0] - 'a' + 1 : vals[arr[s[0] - 'a']]);
        dp[0] = std::max(0, dp[0]);
        int res = dp[0];
        for (int i = 1; i < m; ++i) {
            if (arr[s[i] - 'a'] > -1) {
                dp[i] = std::max(dp[i - 1] + vals[arr[s[i] - 'a']], vals[arr[s[i] - 'a']]);
                res = std::max(dp[i], res);
            } else {
                dp[i] = std::max(dp[i - 1] + s[i] - 'a' + 1, s[i] - 'a' + 1);
                res = std::max(dp[i], res);
            }
        }
        return res;
    }
};

// @lc code=end
