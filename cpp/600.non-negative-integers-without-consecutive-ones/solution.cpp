// Created by zwyyy456 at 2023/06/06 14:58
// https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/

/*
600. Non-negative Integers without Consecutive Ones (Hard)
Given a positive integer `n`, return the number of the integers in the range `[0, n]` whose binary
representations **do not** contain consecutive ones.

**Example 1:**

```
Input: n = 5
Output: 5
Explanation:
Here are the non-negative integers <= 5 with their corresponding binary representations:
0 : 0
1 : 1
2 : 10
3 : 11
4 : 100
5 : 101
Among them, only integer 3 disobeys the rule (two consecutive ones) and the other 5 satisfy the
rule.

```

**Example 2:**

```
Input: n = 1
Output: 2

```

**Example 3:**

```
Input: n = 2
Output: 3

```

**Constraints:**

- `1 <= n <= 10⁹`

*/

#include <algorithm>
#include <bits/stdc++.h>
#include <string>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    // 由于本题中，前导 0 不会影响答案，因此不使用 filled
    string ToString(int n) {
        string res;
        while (n != 0) {
            res.push_back((n & 1) + '0');
            n = (n >> 1);
        }
        reverse(res.begin(), res.end());
        return res;
    }
    int dfs(string &str, int idx, bool pre1, bool is_limit, bool filled, vector<vector<int>> &cach) {
        if (idx == str.size()) {
            return 1; // 找到了一个合法数字
        }
        if (cach[idx][pre1] != -1 && !is_limit) {
            return cach[idx][pre1];
        }
        int res = 0;
        int up = is_limit ? str[idx] - '0' : 1;
        if (pre1) {
            for (int i = 0; i <= up; ++i) {
                if (i == 1) {
                    continue;
                }
                res += dfs(str, idx + 1, false, is_limit && i == str[idx] - '0', filled, cach);
            }
        } else {
            for (int i = 0; i <= up; ++i) {
                res += dfs(str, idx + 1, i == 1, is_limit && i == str[idx] - '0', filled, cach);
            }
        }
        if (!is_limit) {
            cach[idx][pre1] = res;
        }
        return res;
    }
    int findIntegers(int n) {
        string str = ToString(n);
        vector<vector<int>> cach(31, vector<int>(2, -1));
        return dfs(str, 0, false, true, false, cach);
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int n;
    LeetCodeIO::scan(cin, n);

    Solution *obj = new Solution();

    auto res = obj->findIntegers(n);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
