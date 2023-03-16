// Created by zwyyy456 at 2023/03/15 10:05
// https://leetcode.com/problems/trapping-rain-water/

/*
42. Trapping Rain Water (Hard)

Given `n` non-negative integers representing an elevation map where the width of each bar is `1`,
compute how much water it can trap after raining.

**Example 1:**

![](https://assets.leetcode.com/uploads/2018/10/22/rainwatertrap.png)

```
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array
[0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

```

**Example 2:**

```
Input: height = [4,2,0,3,2,5]
Output: 9

```

**Constraints:**

- `n == height.length`
- `1 <= n <= 2 * 10⁴`
- `0 <= height[i] <= 10⁵`
*/

// @lc code=begin
#include <vector>
using std::vector;
class Solution {
  public:
    int trap(vector<int> &height) {
        int n = height.size();
        // vector<int> max_l2r(n);
        // max_l2r[0] = height[0];
        vector<int> max_r2l(n);
        max_r2l[n - 1] = height[n - 1];
        // for (int i = 1; i < n; ++i) {
        //     if (height[i] > max_l2r[i - 1]) {
        //         max_l2r[i] = height[i];
        //     } else {
        //         max_l2r[i] = max_l2r[i - 1];
        //     }
        // }
        for (int i = n - 2; i >= 0; --i) {
            if (height[i] > max_r2l[i + 1]) {
                max_r2l[i] = height[i];
            } else {
                max_r2l[i] = max_r2l[i + 1];
            }
        }
        int lmax = height[0];
        int res = 0;
        for (int i = 1; i < n - 1; ++i) {
            lmax = std::max(lmax, height[i - 1]);
            int high = std::min(lmax, max_r2l[i + 1]) - height[i];
            if (high > 0) {
                res += high;
            }
        }
        return res;
    }
};

// @lc code=end
