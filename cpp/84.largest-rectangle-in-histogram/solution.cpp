// Created by zwyyy456 at 2023/05/23 14:55
// https://leetcode.com/problems/largest-rectangle-in-histogram/

/*
84. Largest Rectangle in Histogram (Hard)
Given an array of integers `heights` representing the histogram's bar height where the width of each
bar is `1`, return the area of the largest rectangle in the histogram.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/01/04/histogram.jpg)

```
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.

```

**Example 2:**

![](https://assets.leetcode.com/uploads/2021/01/04/histogram-1.jpg)

```
Input: heights = [2,4]
Output: 4

```

**Constraints:**

- `1 <= heights.length <= 10⁵`
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
