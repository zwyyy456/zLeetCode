// Created by Bob at 2023/06/03 14:03
// https://leetcode.cn/problems/swap-for-longest-repeated-character-substring/

/*
1156. 单字符重复子串的最大长度 (Medium)
如果字符串中的所有字符都相同，那么这个字符串是单字符重复的字
符串。

给你一个字符串 `text`，你只能交换其中两个字符一次或者什么都
不做，然后得到一些单字符重复的子串。返回其中最长的子串的长度
。

**示例 1：**

```
输入：text = "ababa"
输出：3

```

**示例 2：**

```
输入：text = "aaabaaa"
输出：6

```

**示例 3：**

```
输入：text = "aaabbaaa"
输出：4

```

**示例 4：**

```
输入：text = "aaaaa"
输出：5

```

**示例 5：**

```
输入：text = "abcdef"
输出：1

```

**提示：**

- `1 <= text.length <= 20000`
- `text` 仅由小写英文字母组成。

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int maxRepOpt1(string text) {
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    string text;
    LeetCodeIO::scan(cin, text);

    Solution *obj = new Solution();

    auto res = obj->maxRepOpt1(text);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
