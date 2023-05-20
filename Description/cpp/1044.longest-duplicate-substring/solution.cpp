// Created by Bob at 2023/05/15 11:55
// https://leetcode.cn/problems/longest-duplicate-substring/

/*
1044. 最长重复子串 (Hard)
给你一个字符串 `s` ，考虑其所有 重复子串 ：即 `s` 的（连续）
子串，在 `s` 中出现 2 次或更多次。这些出现之间可能存在重叠。

返回 **任意一个** 可能具有最长长度的重复子串。如果 `s` 不含
重复子串，那么答案为 `""` 。

**示例 1：**

```
输入：s = "banana"
输出："ana"

```

**示例 2：**

```
输入：s = "abcd"
输出：""

```

**提示：**

- `2 <= s.length <= 3 * 10⁴`
- `s` 由小写英文字母组成

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    string check(int mid, string &s, vector<uint64_t> &h, vector<uint64_t> &p) {
        unordered_set<uint64_t> substrs;
        for (int i = 0; i + mid <= s.size(); ++i) {
            int j = i + mid;
            long hash = h[j] - h[i] * p[j - i];
            if (substrs.find(hash) != substrs.end()) {
                return s.substr(i, mid);
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
        p[0] = 1;
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
