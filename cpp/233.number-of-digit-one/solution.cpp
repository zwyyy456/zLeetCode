// Created by zwyyy456 at 2023/06/06 14:03
// https://leetcode.com/problems/number-of-digit-one/

/*
233. Number of Digit One (Hard)
Given an integer `n`, count the total number of digit  `1` appearing in all non-negative integers
less than or equal to `n`.

**Example 1:**

```
Input: n = 13
Output: 6

```

**Example 2:**

```
Input: n = 0
Output: 0

```

**Constraints:**

- `0 <= n <= 10⁹`

*/

#include <bits/stdc++.h>
#include <string>
#include "LC_IO.h"
using namespace std;

// @lc code=begin
class Solution {
  public:
    int dfs(string &str, int cnt, bool is_limit, bool filled, int idx, vector<vector<int>> &cach) {
        if (idx == str.size()) {
            return cnt;
        }
        int res = 0;
        // 只记录 is_limit == false && filled == true 的情况
        if (cach[cnt][idx] != -1 && !is_limit && filled) {
            return cach[cnt][idx];
        }
        if (!filled) {
            res += dfs(str, cnt, false, false, idx + 1, cach);
        }
        int up = is_limit ? str[idx] - '0' : 9;
        int left = filled ? 0 : 1;
        for (int i = left; i <= up; ++i) {
            if (i == 1) {
                res += dfs(str, cnt + 1, is_limit && i == str[idx] - '0', true, idx + 1, cach);
            } else {
                res += dfs(str, cnt, is_limit && i == str[idx] - '0', true, idx + 1, cach);
            }
        }
        if (!is_limit && filled)
            cach[cnt][idx] = res;
        return res;
    }
    int countDigitOne(int n) {
        string str = to_string(n);
        vector<vector<int>> cach(10, vector<int>(11, -1));
        return dfs(str, 0, true, false, 0, cach);
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int n;
    LeetCodeIO::scan(cin, n);

    Solution *obj = new Solution();

    auto res = obj->countDigitOne(n);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
