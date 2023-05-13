// Created by zwyyy456 at 2023/04/14 09:22
// https://leetcode.com/problems/camelcase-matching/

/*
1023. Camelcase Matching (Medium)

Given an array of strings `queries` and a string `pattern`, return a boolean array `answer` where
`answer[i]` is `true` if `queries[i]` matches `pattern`, and `false` otherwise.

A query word `queries[i]` matches `pattern` if you can insert lowercase English letters pattern so
that it equals the query. You may insert each character at any position and you may not insert any
characters.

**Example 1:**

```
Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FB"
Output: [true,false,true,true,false]
Explanation: "FooBar" can be generated like this "F" + "oo" + "B" + "ar".
"FootBall" can be generated like this "F" + "oot" + "B" + "all".
"FrameBuffer" can be generated like this "F" + "rame" + "B" + "uffer".

```

**Example 2:**

```
Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBa"
Output: [true,false,true,false,false]
Explanation: "FooBar" can be generated like this "Fo" + "o" + "Ba" + "r".
"FootBall" can be generated like this "Fo" + "ot" + "Ba" + "ll".

```

**Example 3:**

```
Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBaT"
Output: [false,true,false,false,false]
Explanation: "FooBarTest" can be generated like this "Fo" + "o" + "Ba" + "r" + "T" + "est".

```

**Constraints:**

- `1 <= pattern.length, queries.length <= 100`
- `1 <= queries[i].length <= 100`
- `queries[i]` and `pattern` consist of English letters.
*/

// @lc code=begin
#include <vector>
#include <string>
using std::string;
using std::vector;
class Solution {
public:
    bool match(string &str, string &pattern) {
        int m = str.size(), n = pattern.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); // 1表示true
        dp[0][0] = 1;
        for (int i = 1; i <= m; ++i) {
            if (str[i - 1] >= 'a' && str[i - 1] <= 'z') {
                dp[i][0] = dp[i - 1][0];
            }
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (str[i - 1] == pattern[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    if (str[i - 1] >= 'a' && str[i -1] <= 'z') {
                        dp[i][j] = dp[i - 1][j];
                    }
                }
            }
        }
        return dp[m][n] == 1;
    }
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        // 利用动态规划进行匹配
        int n = queries.size();
        vector<bool> ans(n, false);
        for (int i = 0; i < n; ++i) {
            auto str = queries[i];
            if (match(str, pattern)) {
                ans[i] = true;
            }
        }
        return ans;
    }
};
// @lc code=end
