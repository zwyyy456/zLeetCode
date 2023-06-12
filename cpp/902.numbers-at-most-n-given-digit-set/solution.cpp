// Created by zwyyy456 at 2023/06/06 15:30
// https://leetcode.com/problems/numbers-at-most-n-given-digit-set/

/*
902. Numbers At Most N Given Digit Set (Hard)
Given an array of `digits` which is sorted in **non-decreasing** order. You can write numbers using
each `digits[i]` as many times as we want. For example, if `digits = ['1','3','5']`, we may write
numbers such as `'13'`, `'551'`, and `'1351315'`.

Return the number of positive integers that can be generated that are less than or equal to a given
integer `n`.

**Example 1:**

```
Input: digits = ["1","3","5","7"], n = 100
Output: 20
Explanation:
The 20 numbers that can be written are:
1, 3, 5, 7, 11, 13, 15, 17, 31, 33, 35, 37, 51, 53, 55, 57, 71, 73, 75, 77.

```

**Example 2:**

```
Input: digits = ["1","4","9"], n = 1000000000
Output: 29523
Explanation:
We can write 3 one digit numbers, 9 two digit numbers, 27 three digit numbers,
81 four digit numbers, 243 five digit numbers, 729 six digit numbers,
2187 seven digit numbers, 6561 eight digit numbers, and 19683 nine digit numbers.
In total, this is 29523 integers that can be written using the digits array.

```

**Example 3:**

```
Input: digits = ["7"], n = 8
Output: 1

```

**Constraints:**

- `1 <= digits.length <= 9`
- `digits[i].length == 1`
- `digits[i]` is a digit from `'1'` to `'9'`.
- All the values in `digits` are **unique**.
- `digits` is sorted in **non-decreasing** order.
- `1 <= n <= 10⁹`

*/

#include <bits/stdc++.h>
#include <string>
#include <vector>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int dfs(string &str, vector<int> &nums, int idx, bool is_limit, bool is_filled, vector<vector<int>> &cach) {
        if (idx == str.size()) {
            return is_filled ? 1 : 0;
        }
        if (cach[idx][is_filled ? 1 : 0] != -1 && !is_limit) {
            return cach[idx][is_filled ? 1 : 0];
        }
        int res = 0;
        if (!is_filled) {
            res += dfs(str, nums, idx + 1, false, false, cach);
        }
        int upbound = is_limit ? str[idx] - '0' : 9;
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            if (is_limit && num > upbound) {
                break;
            }
            res += dfs(str, nums, idx + 1, is_limit && num == upbound, true, cach);
        }
        if (!is_limit) {
            cach[idx][is_filled ? 1 : 0] = res;
        }
        return res;
    }
    int atMostNGivenDigitSet(vector<string> &digits, int n) {
        vector<vector<int>> cach(11, vector<int>(2, -1));
        vector<int> nums;
        for (auto &str : digits) {
            nums.push_back(str[0] - '0');
        }
        string str = to_string(n);
        return dfs(str, nums, 0, true, false, cach);
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<string> digits;
    LeetCodeIO::scan(cin, digits);
    int n;
    LeetCodeIO::scan(cin, n);

    Solution *obj = new Solution();

    auto res = obj->atMostNGivenDigitSet(digits, n);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
