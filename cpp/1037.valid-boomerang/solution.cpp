// Created by zwyyy456 at 2023/03/29 09:10
// https://leetcode.com/problems/valid-boomerang/

/*
1037. Valid Boomerang (Easy)

Given an array `points` where `points[i] = [xᵢ, yᵢ]` represents a point on the **X-Y** plane, return
`true`if these points are a **boomerang**.

A **boomerang** is a set of three points that are **all distinct** and **not in a straight line**.

**Example 1:**

```
Input: points = [[1,1],[2,3],[3,2]]
Output: true

```

**Example 2:**

```
Input: points = [[1,1],[2,2],[3,3]]
Output: false

```

**Constraints:**

- `points.length == 3`
- `points[i].length == 2`
- `0 <= xᵢ, yᵢ <= 100`
*/

// @lc code=begin
#include <vector>
using std::vector;
class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        // if (points[0][0] == points[1][0] == points[2][0]) {
        //     return false;
        // }
        // if ((points[0][0] == points[1][0] && points[0][1] == points[1][1]) || (points[0][0] == points[2][0] && points[0][1] == points[2][1]) || (points[1][0] == points[2][0] && points[1][1] == points[2][1]))
        //     return false;
        return (points[1][1] - points[0][1]) * (points[2][0] - points[1][0]) != (points[2][1] - points[1][1]) * (points[1][0] - points[0][0]); 
    }
};

// @lc code=end
