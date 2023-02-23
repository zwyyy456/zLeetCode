// Created by Bob at 2023/02/13 13:42
// https://leetcode.com/problems/replace-the-substring-for-balanced-string/

/*
1234. Replace the Substring for Balanced String (Medium)

You are given a string s of length `n` containing only four kinds of characters: `'Q'`, `'W'`,
`'E'`, and `'R'`.
A string is said to be **balanced** if each of its characters appears `n / 4` times where `n` is the
length of the string.
Return the minimum length of the substring that can be replaced with **any** other string of the
same length to make  `s`**balanced**. If s is already **balanced**, return `0`.
**Example 1:**
```
Input: s = "QWER"
Output: 0
Explanation: s is already balanced.
```
**Example 2:**
```
Input: s = "QQWE"
Output: 1
Explanation: We need to replace a 'Q' to 'R', so that "RQWE" (or "QRWE") is balanced.
```
**Example 3:**
```
Input: s = "QQQW"
Output: 2
Explanation: We can replace the first "QQ" to "ER".
```
**Constraints:**
- `n == s.length`
- `4 <= n <= 10⁵`
- `n` is a multiple of `4`.
- `s` contains only `'Q'`, `'W'`, `'E'`, and `'R'`.
*/

// @lc code=begin
#include <unordered_map>
#include <string>
using std::string;
using std::unordered_map;
class Solution {
  public:
    bool check(unordered_map<char, int> &mp, int m) {
        return mp['Q'] > m || mp['W'] > m || mp['E'] > m || mp['R'] > m;
    }
    int balancedString(string s) {
        int n = s.size(), partial = n / 4;
        int res = n;
        unordered_map<char, int> chars;
        for (auto &c : s)
            chars[c]++;
        int flag = 1;
        for (auto &pa : chars) {
            if (pa.second != partial)
                flag = 0;
        }
        if (flag == 1)
            return 0;
        for (int right = 0, left = 0; right < n; right++) {
            chars[s[right]]--;
            while (!check(chars, partial)) {
                chars[s[left]]++;
                left++;
            }
            res = min(right - left + 1, res);
        }
        return res;
    }
};

// @lc code=end
