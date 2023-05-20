// Created by Bob at 2023/05/20 20:38
// https://leetcode.cn/problems/largest-rectangle-in-histogram/

/*
84. 柱状图中最大的矩形 (Hard)
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子
彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。

**示例 1:**

![](https://assets.leetcode.com/uploads/2021/01/04/histogram
.jpg)

```
输入：heights = [2,1,5,6,2,3]
输出：10
解释：最大的矩形为图中红色区域，面积为 10

```

**示例 2：**

![](https://assets.leetcode.com/uploads/2021/01/04/histogram
-1.jpg)

```
输入： heights = [2,4]
输出： 4
```

**提示：**

- `1 <= heights.length <=10⁵`
- `0 <= heights[i] <= 10⁴`

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin
class Solution {
  public:
    int largestRectangleArea(vector<int> &heights) {
        // 栈底到栈顶单调递增，栈中存储的是索引
        if (heights.size() == 1) {
            return heights[0];
        }
        stack<int> stk;
        int n = heights.size();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && heights[i] < heights[stk.top()]) {
                int h = heights[stk.top()];
                // min_h = min(min_h, h);
                stk.pop();
                if (!stk.empty()) {
                    res = max(res, (i - stk.top() - 1) * h);
                } else {
                    res = max(res, (i)*h);
                }
            }

            stk.push(i);
        }
        int right = stk.top();
        // int min_h = 100001;
        while (!stk.empty()) {
            int h = heights[stk.top()];
            stk.pop();
            if (!stk.empty()) {
                res = max(res, (right - stk.top()) * h);
            } else {
                res = max(res, h * n);
            }
        }

        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> heights;
    LeetCodeIO::scan(cin, heights);

    Solution *obj = new Solution();

    auto res = obj->largestRectangleArea(heights);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
