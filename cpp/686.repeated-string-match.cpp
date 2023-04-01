// Created by zwyyy456 at 2023/03/27 16:08
// https://leetcode.com/problems/repeated-string-match/

/*
686. Repeated String Match (Medium)

Given two strings `a` and `b`, return the minimum number of times you should repeat string  `a` so
that string `b`is a substring of it. If it is impossible for `b`  to be a substring of `a` after
repeating it, return `-1`.

**Notice:** string `"abc"` repeated 0 times is `""`, repeated 1 time is `"abc"` and repeated 2 times
is `"abcabc"`.

**Example 1:**

```
Input: a = "abcd", b = "cdabcdab"
Output: 3
Explanation: We return 3 because by repeating a three times "abcdabcdabcd", b is a substring of it.

```

**Example 2:**

```
Input: a = "a", b = "aa"
Output: 2

```

**Constraints:**

- `1 <= a.length, b.length <= 10⁴`
- `a` and `b` consist of lowercase English letters.
*/

// @lc code=begin
#include <string>
#include <vector>
using std::vector;
using std::string;
class Solution {
public:
    bool check(string &s, string b) {
        vector<int> next(b.size());
        int x = 1, now = 0;
        while (x < b.size()) {
            if (b[x] == b[now]) {
                next[x++] = ++now;
            } else if (now == 0) {
                next[x++] = 0;
            } else {
                now = next[now - 1];
            }
        }
        int i = 0, j = 0;
        while (i < s.size() && j < b.size()) {
            if (s[i] == b[j]) {
                ++i;
                ++j;
            } else {
                if (j > 0) {
                    j = next[j - 1];
                } else {
                    ++i;
                }
            }
        }
        return j >= b.size();
    }
    int repeatedStringMatch(string a, string b) {
        int left = (b.size() - 1) / a.size();
        string s;
        if (left == 0) {
            s = a;
        } else {
           for (int i = 0; i < left; ++i) {
                s += a; 
           } 
        }
        for (int i = 0; i < 3; ++i) {
            if (check(s, b)) {
                return s.size() / a.size();
            } else {
                s += a;
            }
        }
        return -1;

    }
};

// @lc code=end
