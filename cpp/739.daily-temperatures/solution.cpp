// Created by zwyyy456 at 2023/05/22 10:04
// https://leetcode.com/problems/daily-temperatures/

/*
739. Daily Temperatures (Medium)
Given an array of integers `temperatures` represents the daily temperatures, return an array
`answer`such that `answer[i]`is the number of days you have to wait after the `ith`day to get a
warmer temperature. If there is no future day for which this is possible, keep `answer[i] == 0`
instead.

**Example 1:**

```
Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]

```

**Example 2:**

```
Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]

```

**Example 3:**

```
Input: temperatures = [30,60,90]
Output: [1,1,0]

```

**Constraints:**

- `1 <= temperatures.length <= 10⁵`
- `30 <= temperatures[i] <= 100`

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        // 维护一个单调递减栈
        stack<int> stk;
        int n = temperatures.size();
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
                int idx = stk.top();
                ans[idx] = i - idx;
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> temperatures;
    LeetCodeIO::scan(cin, temperatures);

    Solution *obj = new Solution();

    auto res = obj->dailyTemperatures(temperatures);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
