// Created by Bob at 2023/02/17 12:41
// https://leetcode.com/problems/flip-string-to-monotone-increasing/

/*
926. Flip String to Monotone Increasing (Medium)

A binary string is monotone increasing if it consists of some number of `0`'s (possibly none),
followed by some number of `1`'s (also possibly none).
You are given a binary string `s`. You can flip `s[i]` changing it from `0` to `1` or from `1` to
`0`.
Return the minimum number of flips to make  `s` monotone increasing.
**Example 1:**
```
Input: s = "00110"
Output: 1
Explanation: We flip the last digit to get 00111.
```
**Example 2:**
```
Input: s = "010110"
Output: 2
Explanation: We flip to get 011111, or alternatively 000111.
```
**Example 3:**
```
Input: s = "00011000"
Output: 2
Explanation: We flip to get 00000000.
```
**Constraints:**
- `1 <= s.length <= 10⁵`
- `s[i]` is either `'0'` or `'1'`.
*/

// @lc code=begin
#include <vector>
#include <string>
using std::vector;
using std::string;
class Solution {
  public:
    int minFlipsMonoIncr(string s) {
        int cnt = 0, res = 0; // cnt为遍历中1的个数
        vector<int> dp(s.size() + 1, 0);
        for (int i = 1; i <= s.size(); i++) {
            if (s[i - 1] == '1') {
                cnt++;
                dp[i] = dp[i - 1];
            } else {
                dp[i] = std::min(dp[i - 1] + 1, cnt);
            }
        }
        return dp[s.size()];
    }
};

// @lc code=end
