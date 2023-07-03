// Created by zwyyy456 at 2023/03/29 09:59
// https://leetcode.com/problems/valid-square/

/*
593. Valid Square (Medium)

Given the coordinates of four points in 2D space `p1`, `p2`, `p3` and `p4`, return `true`if the four
points construct a square.

The coordinate of a point `pᵢ` is represented as `[xᵢ, yᵢ]`. The input is **not** given in any
order.

A **valid square** has four equal sides with positive length and four equal angles (90-degree
angles).

**Example 1:**

```
Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
Output: true

```

**Example 2:**

```
Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,12]
Output: false

```

**Example 3:**

```
Input: p1 = [1,0], p2 = [-1,0], p3 = [0,1], p4 = [0,-1]
Output: true

```

**Constraints:**

- `p1.length == p2.length == p3.length == p4.length == 2`
- `-10⁴ <= xᵢ, yᵢ <= 10⁴`
*/

// @lc code=begin
#include <vector>
using std::vector;
class Solution {
public:
    int dis(vector<int> &v1, vector<int> &v2) {
        return (v1[0] - v2[0]) * (v1[0] - v2[0]) + (v1[1] - v2[1]) * (v1[1] - v2[1]);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> vec{p2, p3, p4};
        vector<int> p1_;
        int max_dis = 0;
        for (int i = 0; i < 2; ++i) {
            if (dis(p1, vec[i]) > max_dis) {
                max_dis = dis(p1, vec[i]);
                p1_ = vec[i];
            }
        }
        int dis1 = max_dis;
        if (dis1 == 0) {
            return false;
        }
        vector<vector<int>> vec2; // 用来存放另外两个点
        for (int i = 0; i < 2; ++i) {
            if (vec[i] != p1_) {
                vec2.push_back(vec[i]);
            }
        }
        if (vec2.size() < 2) { // 说明有点重叠
            return false;
        } 
        int dis2 = dis(vec2[0], vec2[1]);
        if (dis2 != dis1) {
            return false;
        }
        // 判断两条线是否垂直
        return (p1_[1] - p1[1]) * (vec2[0][1] - vec2[1][1]) + (p1_[0] - p1[0]) * (vec2[0][0] - vec2[1][0]) == 0 && (dis(p1, vec2[0]) == dis(p1_, vec2[0]));
    }
};

// @lc code=end
