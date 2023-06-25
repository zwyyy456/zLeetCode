// Created by zwyyy456 at 2023/06/14 12:27
// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/

/*
1751. Maximum Number of Events That Can Be Attended II (Hard)
You are given an array of `events` where `events[i] = [startDayᵢ, endDayᵢ, valueᵢ]`. The `ith` event
starts at `startDayᵢ` and ends at `endDayᵢ`, and if you attend this event, you will receive a value
of `valueᵢ`. You are also given an integer `k` which represents the maximum number of events you can
attend.

You can only attend one event at a time. If you choose to attend an event, you must attend the
**entire** event. Note that the end day is **inclusive**: that is, you cannot attend two events
where one of them starts and the other ends on the same day.

Return the **maximum sum** of values that you can receive by attending events.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/01/10/screenshot-2021-01-11-at-60048-pm.png)

```
Input: events = [[1,2,4],[3,4,3],[2,3,1]], k = 2
Output: 7
Explanation: Choose the green events, 0 and 1 (0-indexed) for a total value of 4 + 3 = 7.
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2021/01/10/screenshot-2021-01-11-at-60150-pm.png)

```
Input: events = [[1,2,4],[3,4,3],[2,3,10]], k = 2
Output: 10
Explanation: Choose event 2 for a total value of 10.
Notice that you cannot attend any other event as they overlap, and that you do not have to attend k
events.
```

**Example 3:**

**![](https://assets.leetcode.com/uploads/2021/01/10/screenshot-2021-01-11-at-60703-pm.png)**

```
Input: events = [[1,1,1],[2,2,2],[3,3,3],[4,4,4]], k = 3
Output: 9
Explanation: Although the events do not overlap, you can only attend 3 events. Pick the highest
valued three.
```

**Constraints:**

- `1 <= k <= events.length`
- `1 <= k * events.length <= 10⁶`
- `1 <= startDayᵢ <= endDayᵢ <= 10⁹`
- `1 <= valueᵢ <= 10⁶`

*/

#include <bits/stdc++.h>
#include <vector>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int Bfind(vector<vector<int>> &events, int target) {
        int l = 0, r = events.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (events[mid][1] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
    int maxValue(vector<vector<int>> &events, int k) {
        auto cmp = [&events](vector<int> &vec1, vector<int> &vec2) {
            if (vec1[1] == vec2[1]) {
                return vec1[0] < vec2[0];
            }
            return vec1[1] < vec2[1];
        };
        sort(events.begin(), events.end(), cmp);
        int n = events.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1));
        for (int i = 1; i <= n; ++i) {
            int idx = Bfind(events, events[i - 1][0]);
            for (int j = 1; j <= k; ++j)
                dp[i][j] = max(dp[i - 1][j], dp[idx][j - 1] + events[i - 1][2]);
        }
        return dp[n][k];
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<vector<int>> events;
    LeetCodeIO::scan(cin, events);
    int k;
    LeetCodeIO::scan(cin, k);

    Solution *obj = new Solution();

    auto res = obj->maxValue(events, k);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
