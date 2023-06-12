// Created by zwyyy456 at 2023/06/02 14:04
// https://leetcode.com/problems/maximum-number-of-removable-characters/

/*
1898. Maximum Number of Removable Characters (Medium)
You are given two strings `s` and `p` where `p` is a **subsequence** of `s`. You are also given a
**distinct 0-indexed** integer array `removable` containing a subset of indices of `s` ( `s` is also
**0-indexed**).

You want to choose an integer `k` ( `0 <= k <= removable.length`) such that, after removing `k`
characters from `s` using the **first** `k` indices in `removable`, `p` is still a **subsequence**
of `s`. More formally, you will mark the character at `s[removable[i]]` for each `0 <= i < k`, then
remove all marked characters and check if `p` is still a subsequence.

Return the **maximum** `k` you can choose such that  `p` is still a **subsequence** of  `s` after
the removals.

A **subsequence** of a string is a new string generated from the original string with some
characters (can be none) deleted without changing the relative order of the remaining characters.

**Example 1:**

```
Input: s = "abcacb", p = "ab", removable = [3,1,0]
Output: 2
Explanation: After removing the characters at indices 3 and 1, "abcacb" becomes "accb".
"ab" is a subsequence of "accb".
If we remove the characters at indices 3, 1, and 0, "abcacb" becomes "ccb", and "ab" is no longer a
subsequence.
Hence, the maximum k is 2.

```

**Example 2:**

```
Input: s = "abcbddddd", p = "abcd", removable = [3,2,1,4,5,6]
Output: 1
Explanation: After removing the character at index 3, "abcbddddd" becomes "abcddddd".
"abcd" is a subsequence of "abcddddd".

```

**Example 3:**

```
Input: s = "abcab", p = "abc", removable = [0,1,2,3,4]
Output: 0
Explanation: If you remove the first index in the array removable, "abc" is no longer a subsequence.

```

**Constraints:**

- `1 <= p.length <= s.length <= 10⁵`
- `0 <= removable.length < s.length`
- `0 <= removable[i] < s.length`
- `p` is a **subsequence** of `s`.
- `s` and `p` both consist of lowercase English letters.
- The elements in `removable` are **distinct**.

*/

#include <bits/stdc++.h>
#include <unordered_map>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    bool Check(string &s, string &p, unordered_map<int, int> &num_idx, int k) {
        int i = 0, j = 0; // i for s, j for p
        while (j < p.size() && i < s.size()) {
            if (num_idx[i] < k) {
                ++i;
                continue;
            }
            if (s[i] == p[j]) {
                ++i;
                ++j;
            } else {
                ++i;
            }
        }
        return j >= p.size();
    }
    int maximumRemovals(string s, string p, vector<int> &removable) {
        unordered_map<int, int> num_idx;
        int n = removable.size();
        for (int i = 0; i < n; ++i) {
            num_idx[removable[i]] = i;
        }
        int left = 0, right = s.size() - p.size() + 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (Check(s, p, num_idx, mid)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left - 1;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    string s;
    LeetCodeIO::scan(cin, s);
    string p;
    LeetCodeIO::scan(cin, p);
    vector<int> removable;
    LeetCodeIO::scan(cin, removable);

    Solution *obj = new Solution();

    auto res = obj->maximumRemovals(s, p, removable);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
