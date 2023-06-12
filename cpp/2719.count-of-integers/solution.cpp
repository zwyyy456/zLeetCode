// Created by zwyyy456 at 2023/06/05 12:15
// https://leetcode.com/problems/count-of-integers/

/*
2719. Count of Integers (Hard)
You are given two numeric strings `num1` and `num2` and two integers `max_sum` and `min_sum`. We
denote an integer `x` to be good if:

- `num1 <= x <= num2`
- `min_sum <= digit_sum(x) <= max_sum`.

Return the number of good integers. Since the answer may be large, return it modulo `10⁹ + 7`.

Note that `digit_sum(x)` denotes the sum of the digits of `x`.

**Example 1:**

```
Input: num1 = "1", num2 = "12", min_num = 1, max_num = 8
Output: 11
Explanation: There are 11 integers whose sum of digits lies between 1 and 8 are
1,2,3,4,5,6,7,8,10,11, and 12. Thus, we return 11.

```

**Example 2:**

```
Input: num1 = "1", num2 = "5", min_num = 1, max_num = 5
Output: 5
Explanation: The 5 integers whose sum of digits lies between 1 and 5 are 1,2,3,4, and 5. Thus, we
return 5.

```

**Constraints:**

- `1 <= num1 <= num2 <= 10²²`
- `1 <= min_sum <= max_sum <= 400`

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    const int Mod = 1e9 + 7;
    int Check(string num, int max_sum, int min_sum) {
        int total = 0;
        for (char c : num) {
            total += c - '0';
        }
        return total <= max_sum && total >= min_sum;
    }
    int dfs(string &str, int max_sum, int min_sum, int is_limit, int sum, int idx, vector<vector<vector<int>>> &cache) {
        if (sum > max_sum) {
            return 0;
        }
        if (idx == str.size()) {
            return sum >= min_sum;
        }
        if (cache[is_limit][sum][idx] != -1) {
            return cache[is_limit][sum][idx];
        }
        int res = 0;
        if (is_limit != 0) {
            for (int i = 0; i <= str[idx] - '0'; ++i) {
                res = (res + dfs(str, max_sum, min_sum, i == str[idx] - '0' ? 1 : 0, sum + i, idx + 1, cache)) % Mod;
            }
        } else {
            for (int i = 0; i <= 9; ++i) {
                res = (res + dfs(str, max_sum, min_sum, 0, sum + i, idx + 1, cache)) % Mod;
            }
        }
        cache[is_limit][sum][idx] = res;
        return res;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        // dfs(num2, max_num) 表示整数小于 num2 并且 min_sum <= digit_sum(x) <= max_sum 的整数数目
        vector<vector<vector<int>>> cach1(2, vector<vector<int>>(401, vector<int>(23, -1)));
        vector<vector<vector<int>>> cach2(2, vector<vector<int>>(401, vector<int>(23, -1)));
        int res = dfs(num2, max_sum, min_sum, 1, 0, 0, cach1) - dfs(num1, max_sum, min_sum, 1, 0, 0, cach2) + Check(num1, max_sum, min_sum);
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    string num1;
    LeetCodeIO::scan(cin, num1);
    string num2;
    LeetCodeIO::scan(cin, num2);
    int min_sum;
    LeetCodeIO::scan(cin, min_sum);
    int max_sum;
    LeetCodeIO::scan(cin, max_sum);

    Solution *obj = new Solution();

    auto res = obj->count(num1, num2, min_sum, max_sum);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
