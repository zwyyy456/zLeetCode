// Created by zwyyy456 at 2023/03/06 09:40
// https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/

/*
1653. Minimum Deletions to Make String Balanced (Medium)

You are given a string `s` consisting only of characters `'a'` and `'b'` .

You can delete any number of characters in `s` to make `s` **balanced**. `s` is **balanced** if
there is no pair of indices `(i,j)` such that `i < j` and `s[i] = 'b'` and `s[j]= 'a'`.

Return the **minimum** number of deletions needed to make  `s`**balanced**.

**Example 1:**

```
Input: s = "aababbab"
Output: 2
Explanation: You can either:
Delete the characters at 0-indexed positions 2 and 6 ("aababbab" -> "aaabbb"), or
Delete the characters at 0-indexed positions 3 and 6 ("aababbab" -> "aabbbb").

```

**Example 2:**

```
Input: s = "bbaaaaabb"
Output: 2
Explanation: The only solution is to delete the first two characters.

```

**Constraints:**

- `1 <= s.length <= 10⁵`
- `s[i]` is `'a'` or `'b'` .
*/

// @lc code=begin
#include <string>
#include <vector>
using std::string;
using std::vector;
class Solution {
  public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        vector<int> cnt(n + 1, 0); // 前n个字符中'b'的数目
        for (int i = 1; i <= n; ++i) {
            if (s[i - 1] == 'b') {
                cnt[i] = cnt[i - 1] + 1;
                dp[i] = dp[i - 1];
            } else {
                cnt[i] = cnt[i - 1];
                dp[i] = std::min(dp[i - 1] + 1, cnt[i]);
            }
        }
        return dp[n];
    }
};
// @lc code=end
