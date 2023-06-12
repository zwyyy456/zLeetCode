// Created by zwyyy456 at 2023/06/05 16:19
// https://leetcode.com/problems/numbers-with-repeated-digits/

/*
1012. Numbers With Repeated Digits (Hard)
Given an integer `n`, return the number of positive integers in the range  `[1, n]` that have **at
least one** repeated digit.

**Example 1:**

```
Input: n = 20
Output: 1
Explanation: The only positive number (<= 20) with at least 1 repeated digit is 11.

```

**Example 2:**

```
Input: n = 100
Output: 10
Explanation: The positive numbers (<= 100) with atleast 1 repeated digit are 11, 22, 33, 44, 55, 66,
77, 88, 99, and 100.

```

**Example 3:**

```
Input: n = 1000
Output: 262

```

**Constraints:**

- `1 <= n <= 10⁹`

*/

#include <bits/stdc++.h>
#include <string>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int dfs(string &str, int idx, bool is_limit, int mask, bool filled, vector<vector<vector<vector<int>>>> &cach) {
        if (idx == str.size()) {
            return 1; // 说明找到了一个合理的选择
        }
        if (cach[idx][is_limit][mask][filled] != -1) {
            return cach[idx][is_limit][mask][filled];
        }
        int limit = is_limit ? str[idx] - '0' : 9;
        int res = 0;
        if (!filled) {
            // 前面的数位都没有填充
            res += dfs(str, idx + 1, false, mask, filled, cach);
        }
        int left = filled ? 0 : 1;

        for (int i = left; i <= limit; ++i) {
            if (((1 << i) & mask) != 0) {
                // 说明 i 已经选择过了
                continue;
            }
            res += dfs(str, idx + 1, is_limit && (i == str[idx] - '0'), mask | (1 << i), filled || (i != 0), cach);
        }
        cach[idx][is_limit][mask][filled] = res;
        return res;
    }
    int numDupDigitsAtMostN(int n) {
        // 考虑所有数字都不重复的正整数
        string str = to_string(n);
        vector<vector<vector<vector<int>>>> cach(10, vector<vector<vector<int>>>(2, vector<vector<int>>(1 << 10, vector<int>(2, -1))));
        return n - dfs(str, 0, true, 0, false, cach);
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int n;
    LeetCodeIO::scan(cin, n);

    Solution *obj = new Solution();

    auto res = obj->numDupDigitsAtMostN(n);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
