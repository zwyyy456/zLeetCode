// Created by zwyyy456 at 2023/02/21 16:02
// https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/

/*
1326. Minimum Number of Taps to Open to Water a Garden (Hard)

There is a one-dimensional garden on the x-axis. The garden starts at the point `0` and ends at the
point `n`. (i.e The length of the garden is `n`).

There are `n + 1` taps located at points `[0, 1, ..., n]` in the garden.

Given an integer `n` and an integer array `ranges` of length `n + 1` where `ranges[i]` (0-indexed)
means the `i-th` tap can water the area `[i - ranges[i], i + ranges[i]]` if it was open.

Return the minimum number of taps that should be open to water the whole garden, If the garden
cannot be watered return **-1**.

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/01/16/1685_example_1.png)

```
Input: n = 5, ranges = [3,4,1,1,0,0]
Output: 1
Explanation: The tap at point 0 can cover the interval [-3,3]
The tap at point 1 can cover the interval [-3,5]
The tap at point 2 can cover the interval [1,3]
The tap at point 3 can cover the interval [2,4]
The tap at point 4 can cover the interval [4,4]
The tap at point 5 can cover the interval [5,5]
Opening Only the second tap will water the whole garden [0,5]

```

**Example 2:**

```
Input: n = 3, ranges = [0,0,0,0]
Output: -1
Explanation: Even if you activate all the four taps you cannot water the whole garden.

```

**Constraints:**

- `1 <= n <= 10⁴`
- `ranges.length == n + 1`
- `0 <= ranges[i] <= 100`
*/

// @lc code=begin
#include <vector>
using std::vector;
class Solution {
  public:
    int minTaps(int n, vector<int> &ranges) {
        vector<vector<int>> water_range;
        for (int i = 0; i <= n; i++) {
            water_range.push_back({std::max(0, i - ranges[i]), std::min(i + ranges[i], n)});
        }
        std::sort(water_range.begin(), water_range.end());
        vector<int> dp(n + 1, 30000);
        dp[0] = 0;
        for (int i = 0; i <= n; i++) {
            if (dp[water_range[i][0]] == 30000)
                return -1;
            for (int j = water_range[i][0]; j <= water_range[i][1]; j++) {
                dp[j] = std::min(dp[j], dp[water_range[i][0]] + 1);
            }
        }
        return dp[n];
    }
};

// @lc code=end
