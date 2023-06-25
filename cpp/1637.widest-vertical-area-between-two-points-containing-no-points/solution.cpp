// Created by zwyyy456 at 2023/03/30 08:43
// https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/

/*
1637. Widest Vertical Area Between Two Points Containing No Points (Medium)

Given `n` `points` on a 2D plane where `points[i] = [xᵢ, yᵢ]`, Return the **widest vertical area**
between two points such that no points are inside the area.

A **vertical area** is an area of fixed-width extending infinitely along the y-axis (i.e., infinite
height). The **widest vertical area** is the one with the maximum width.

Note that points **on the edge** of a vertical area **are not** considered included in the area.

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/09/19/points3.png)

```
Input: points = [[8,7],[9,9],[7,4],[9,7]]
Output: 1
Explanation: Both the red and the blue area are optimal.

```

**Example 2:**

```
Input: points = [[3,1],[9,0],[1,0],[1,4],[5,3],[8,8]]
Output: 3

```

**Constraints:**

- `n == points.length`
- `2 <= n <= 10⁵`
- `points[i].length == 2`
- `0 <= xᵢ, yᵢ <= 10⁹`
*/

// @lc code=begin
#include <vector>
using std::vector;
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        std::sort(points.begin(), points.end());
        int res = 0;
        for (int i = 0; i < points.size() - 1; ++i) {
            res = std::max(res, points[i + 1][0] - points[i][0]);
        }
        return res;
    }
};

// @lc code=end
