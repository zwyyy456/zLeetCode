// Created by zwyyy456 at 2023/05/15 09:57
// https://leetcode.com/problems/longest-duplicate-substring/

/*
1044. Longest Duplicate Substring (Hard)
Given a string `s`, consider all duplicated substrings: (contiguous) substrings of s that occur 2 or
more times. The occurrences may overlap.

Return **any** duplicated substring that has the longest possible length. If `s` does not have a
duplicated substring, the answer is `""`.

**Example 1:**

```
Input: s = "banana"
Output: "ana"

```

**Example 2:**

```
Input: s = "abcd"
Output: ""

```

**Constraints:**

- `2 <= s.length <= 3 * 10⁴`
- `s` consists of lowercase English letters.

*/

#include <_types/_uint64_t.h>
#include <bits/stdc++.h>
#include <unordered_map>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    string check(int mid, string &s, vector<uint64_t> &h, vector<uint64_t> &p) {
        unordered_set<uint64_t> substrs;
        for (int i = 1; i + mid - 1 <= s.size(); ++i) {
            int j = i + mid - 1;
            long hash = h[j] - h[i - 1] * p[j - i + 1];
            if (substrs.find(hash) != substrs.end()) {
                return s.substr(i - 1, mid);
            }
            substrs.insert(hash);
        }
        return "";
    }
    string longestDupSubstring(string s) {
        // 二分查找答案，左边界为0，右边界为 s.size()，左闭右开
        unordered_map<string, int> substr;
        int left = 0, right = s.size();
        string ans;
        int P = 1313131, n = s.size();
        vector<uint64_t> h(n + 10);
        vector<uint64_t> p(n + 10);
        for (int i = 0; i < n; ++i) {
            p[i + 1] = p[i] * P;
            h[i + 1] = h[i] * P + s[i];
        }
        while (left < right) {
            int mid = left + (right - left) / 2;
            string tmp_res = check(mid, s, h, p);
            if (!tmp_res.empty()) {
                left = mid + 1;
            } else {
                right = mid;
            }
            ans = ans.size() < tmp_res.size() ? tmp_res : ans;
        }
        return ans;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    string s;
    LeetCodeIO::scan(cin, s);

    Solution *obj = new Solution();

    auto res = obj->longestDupSubstring(s);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
