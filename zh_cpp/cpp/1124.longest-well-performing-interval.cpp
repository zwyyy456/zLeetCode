// Created by Bob at 2023/03/02 18:50
// https://leetcode.cn/problems/longest-well-performing-interval/

/*
1124. 表现良好的最长时间段 (Medium)

给你一份工作时间表 `hours`，上面记录着某一位员工每天的工作小时数。

我们认为当员工一天中的工作小时数大于 `8` 小时的时候，那么这一天就是「 **劳累的一天**」。

所谓「表现良好的时间段」，意味在这段时间内，「劳累的天数」是严格 **大于**「不劳累的天数」。

请你返回「表现良好时间段」的最大长度。

**示例 1：**

```
输入：hours = [9,9,6,0,6,6,9]
输出：3
解释：最长的表现良好时间段是 [9,9,6]。
```

**示例 2：**

```
输入：hours = [6,6,6]
输出：0

```

**提示：**

- `1 <= hours.length <= 10⁴`
- `0 <= hours[i] <= 16`
*/

// @lc code=begin
#include <algorithm>
#include <vector>
#include <stack>
using std::stack;
using std::vector;
class Solution {
  public:
    int longestWPI(vector<int> &hours) {
        int n = hours.size();
        if (n == 1) {
            return hours[0] > 8;
        }
        for (auto &i : hours) {
            if (i > 8) {
                i = 1;
            } else {
                i = -1;
            }
        }
        // 计算新hours的前缀和
        vector<int> prefix(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + hours[i - 1];
        }
        //
        stack<int> l_stk;
        int res = 0;
        l_stk.push(0);
        for (int i = 1; i <= n; i++) {
            if (prefix[i] > 0) {
                res = std::max(res, i);
            }
            if (prefix[i] < prefix[l_stk.top()]) {
                l_stk.push(i);
            }
        }
        for (int r = n; r >= 1; r--) {
            while (!l_stk.empty() && prefix[r] > prefix[l_stk.top()]) {
                if (l_stk.empty()) {
                    return std::max(r, res);
                }
                res = std::max(res, r - l_stk.top());
                l_stk.pop();
            }
        }
        return res;
    }
};

// @lc code=end
