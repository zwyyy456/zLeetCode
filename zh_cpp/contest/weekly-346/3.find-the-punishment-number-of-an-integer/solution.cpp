// Created by Bob at 2023/05/21 10:31
// https://leetcode.cn/problems/find-the-punishment-number-of-an-integer/
// https://leetcode.cn/contest/weekly-contest-346/problems/find-the-punishment-number-of-an-integer/

/*
6441. 求一个整数的惩罚数 (Medium)
给你一个正整数 `n` ，请你返回 `n` 的 **惩罚数** 。

`n` 的 **惩罚数** 定义为所有满足以下条件 `i` 的数的平方和：

- `1 <= i <= n`
- `i * i` 的十进制表示的字符串可以分割成若干连续子字符串，且
这些子字符串对应的整数值之和等于 `i` 。

**示例 1：**

```
输入：n = 10
输出：182
解释：总共有 3 个整数 i 满足要求：
- 1 ，因为 1 * 1 = 1
- 9 ，因为 9 * 9 = 81 ，且 81 可以分割成 8 + 1 。
- 10 ，因为 10 * 10 = 100 ，且 100 可以分割成 10 + 0 。
因此，10 的惩罚数为 1 + 81 + 100 = 182

```

**示例 2：**

```
输入：n = 37
输出：1478
解释：总共有 4 个整数 i 满足要求：
- 1 ，因为 1 * 1 = 1
- 9 ，因为 9 * 9 = 81 ，且 81 可以分割成 8 + 1 。
- 10 ，因为 10 * 10 = 100 ，且 100 可以分割成 10 + 0 。
- 36 ，因为 36 * 36 = 1296 ，且 1296 可以分割成 1 + 29 + 6
。
因此，37 的惩罚数为 1 + 81 + 100 + 1296 = 1478

```

**提示：**

- `1 <= n <= 1000`

*/

#include <bits/stdc++.h>
#include <cstddef>
#include <string>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int str2num(string &str, int l, int r) {
        int res = 0;
        for (int i = l; i <= r; ++i) {
            res = 10 * res + str[i] - '0';
        }
        return res;
    }
    auto check(string &tmp, int target, int idx) -> bool {
        if (idx == tmp.size()) {
            return target == 0;
        }
        bool flag = false;
        for (int i = idx; i < tmp.size(); ++i) {
            int num = str2num(tmp, idx, i);
            if (num <= target) {
                flag = (flag || check(tmp, target - num, i + 1));
            }
        }
        return flag;
    }
    int punishmentNumber(int n) {
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            int tmp = i * i;
            string str = to_string(tmp);
            if (check(str, i, 0)) {
                res += tmp;
            }
        }
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int n;
    LeetCodeIO::scan(cin, n);

    Solution *obj = new Solution();

    auto res = obj->punishmentNumber(n);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
