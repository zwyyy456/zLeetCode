// Created by zwyyy456 at 2023/03/27 15:40
// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

/*
28. Find the Index of the First Occurrence in a String (Easy)

Given two strings `needle` and `haystack`, return the index of the first occurrence of `needle` in
`haystack`, or `-1` if `needle` is not part of `haystack`.

**Example 1:**

```
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

```

**Example 2:**

```
Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.

```

**Constraints:**

- `1 <= haystack.length, needle.length <= 10⁴`
- `haystack` and `needle` consist of only lowercase English characters.
*/

// @lc code=begin
#include <string>
#include <vector>
using std::vector;
using std::string;
class Solution {
public:
    void SetNext(vector<int> &next, string needle) {
        int x = 1, now = 0;
        while (x < needle.size()) {
            if (needle[x] == needle[now]) {
                next[x++] = ++now;
            } else if (now != 0) {
                now = next[now - 1];
            } else {
                next[x] = 0;
                x += 1;
            }
        }
    }
    int strStr(string haystack, string needle) {
        int m = needle.size(), n = haystack.size();
        vector<int> next(m);
        SetNext(next, needle);
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (haystack[i] == needle[j]) {
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
        if (j >= m) {
            return i - m;
        }
        return -1;
    }
};

// @lc code=end
