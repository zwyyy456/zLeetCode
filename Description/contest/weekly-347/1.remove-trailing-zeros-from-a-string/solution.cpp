// Created by Bob at 2023/05/28 10:48
// https://leetcode.cn/problems/remove-trailing-zeros-from-a-string/
// https://leetcode.cn/contest/weekly-contest-347/problems/remove-trailing-zeros-from-a-string/

/*
6457. 移除字符串中的尾随零 (Easy)
给你一个用字符串表示的正整数 `num` ，请你以字符串形式返回不
含尾随零的整数 `num`。

**示例 1：**

```
输入：num = "51230100"
输出："512301"
解释：整数 "51230100" 有 2 个尾随零，移除并返回整数 "512301"
。

```

**示例 2：**

```
输入：num = "123"
输出："123"
解释：整数 "123" 不含尾随零，返回整数 "123" 。

```

**提示：**

- `1 <= num.length <= 1000`
- `num` 仅由数字 `0` 到 `9` 组成
- `num` 不含前导零

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    string removeTrailingZeros(string num) {
        int r = num.size() - 1;
        for (; r >= 0; --r) {
            if (num[r] != '0') {
                break;
            }
        }
        string str = num.substr(0, r + 1);
        return str;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    string num;
    LeetCodeIO::scan(cin, num);

    Solution *obj = new Solution();

    auto res = obj->removeTrailingZeros(num);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
